/*
** EPITECH PROJECT, 2019
** soort tetris
** File description:
** sort file for tetris
*/

#include "./struct.h"

void draw_shape(t_var* var, t_ttr* tmp)
{
    for (int j = 1; tmp->shape[j] != NULL; my_putstr("\n"), j++){
        my_putstr(tmp->shape[j]);
    }
}

char** sort(t_var *var, char** tab)
{
    char temp = 'z';
    char *tmp = NULL;
    int j = 0;
    for (int i = 0; tab[i] != NULL; i++){
        if (j > my_strlen(tab[i]))
            i++;
        if (tab[i][j] < temp && i > 0){
            tmp = my_strdup(tab[i], my_strlen(tab[i]));
            tab[i] = my_strdup(tab[i - 1], my_strlen(tab[i - 1]));
            tab[i - 1] = my_strdup(tmp, my_strlen(tmp));
            j = 0;
            i = 0;
        }
        if (temp == tab[i][j]){
            i--;
            j++;
        }
        temp = tab[i][j];
    }
    return tab;
}

char** get_sorted_tab(t_var *var)
{
    DIR* dir_tetriminos;
    struct dirent* read_dir;
    char **names = malloc(sizeof(char*) * 20);
    int i = 0;
    dir_tetriminos = opendir("./tetriminos");
    while ((read_dir = readdir(dir_tetriminos)) != NULL){
        if (read_dir->d_name[0] != '.'){
            names[i] = malloc(sizeof(char) * my_strlen(read_dir->d_name) + 1);
            names[i] = read_dir->d_name;
            names[i][my_strlen(read_dir->d_name) + 1] = '\0';
            i++;
        }
    }
    names[i] = NULL;
    names = sort(var, names);
    return names;
}