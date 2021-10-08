/*
** EPITECH PROJECT, 2019
** list tetris
** File description:
** list file for tetris
*/

#include "struct.h"

int tetri_error(char* str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (i < 5 && (((i % 2) == 0 && str[i] < '0' || str[i] > '9') ||
        ((i % 2) == 1 && str[i] != ' '))){
            return -1;
        } else if (i > 5 && str[i] != '*' && str[i] != ' ' &&
        str[i] != '\n'){
            return -1;
        }
    }
    return 0;
}

char** shape_to_gameshape(char** shape, t_var* var)
{
    char** ret = malloc(sizeof(char*) * var->temp->height);
    int x = 1;
    int y = 0;
    ret[0] = malloc(sizeof(char));
    ret[1] = malloc(sizeof(char) * var->temp->width * 2);
    for (int y2 = 0; shape[x] != NULL; y++, y2++){
        if (shape[x][y] == '\0'){
            y = -1;
            y2 = -1;
            x++;
            ret[x] = malloc(sizeof(char) * var->temp->width * 2);
        } else if (y2 % 2 == 1){
            ret[x][y2] = ' ';
            y2++;
            ret[x][y2] = shape[x][y];
        } else
            ret[x][y2] = shape[x][y];
    }
    ret[x] = NULL;
    return ret;
}

void add_ttr(t_ttr **ttr, t_var* var, char* name)
{
    t_ttr *new_ttr = malloc(sizeof(t_ttr));
    new_ttr->error = var->temp->error;
    new_ttr->name = name;
    new_ttr->width = var->temp->width;
    new_ttr->height = var->temp->height;
    new_ttr->color = var->temp->color;
    new_ttr->shape = var->temp->shape;
    new_ttr->g_shape = var->temp->g_shape;
    new_ttr->next = *ttr;
    *ttr = new_ttr;
}

void fill_ttrlst2(t_var* var, char* str)
{
    var->temp->error = tetri_error(str);
    var->temp->width = str[0] - 48;
    var->temp->height = str[2] - 48;
    var->temp->color = str[4] - 48;
    var->temp->shape = str_to_tab(&str[6]);
    var->temp->shape[var->temp->height + 1] = NULL;
    var->temp->g_shape = shape_to_gameshape(var->temp->shape, var);
}

int fill_ttrlst(t_var* var)
{
    int fd;
    int i = 0;
    char* str = malloc(sizeof(char) * 4096);
    char **names = get_sorted_tab(var);
    for (i = 0; names[i] != NULL; i++);
    for (int a = i - 1; a > -1; a--){
        fd = open(my_strcat(cat_tetri(names[a]), names[a]), O_RDONLY);
        if (fd == -1)
            break;
        read(fd, str, 4096);
        fill_ttrlst2(var, str);
        if (names[a][0] != '.')
            add_ttr(&var->ttr, var, names[a]);
    }
    t_ttr *tmp2 = var->ttr;
    for (var->size_lst = 0; tmp2; var->size_lst++, tmp2 = tmp2->next);
    return 0;
}