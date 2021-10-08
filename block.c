/*
** EPITECH PROJECT, 2019
** block tetris
** File description:
** block tetris
*/

#include "./struct.h"

void check_game_over(t_var* var)
{
    for (int i = 0; var->blk->block[1][i] != '\0'; i++){
        if (var->blk->block[1][i] == '*'){
            mvprintw(10, 26 + var->key->col, "GAME OVER !");
            getch();
            free(var->blk->block);
            var->blk->block = create_block(var->key);
            var->key->lvl = 1;
            var->tick = 0;
            var->score = 0;
        }
    }
}

void add_to_block(t_var* var)
{
    int j = 0;
    int x = var->fall->x - 31;
    int y = var->fall->y;
    int x_var = x;
    for (int i = 1; var->fall->g_shape[i] != NULL; j++, x_var++){
        if (var->fall->g_shape[i][j] == '\0'){
            x_var = x - 1;
            y++;
            i++;
            j = -1;
        } else if (var->fall->g_shape[i][j] != ' ')
            var->blk->block[y][x_var] = var->fall->g_shape[i][j];
    }
}

int check_add_to_block(t_var* var)
{
    int j = 0;
    int ret = 0;
    if (var->fall->y == var->key->rows - var->fall->height + 1){
        var->fall->stat = 0;
        add_to_block(var);
        return -1;
    }
    for (int i = 1; var->fall->g_shape[i] != NULL; j++){
        if (var->fall->g_shape[i][j] == '\0'){
            j = -1;
            i++;
        } else if (var->fall->g_shape[i][j] == '*' &&
        var->blk->block[var->fall->y + i][var->fall->x + j - 31] == '*'){
            add_to_block(var);
            var->fall->stat = 0;
            ret = -1;
        }
    }
    return ret;
}

char** create_block(t_key* key)
{
    char** block = malloc(sizeof(char*) * key->rows + 1);
    int i = 1;
    block[0] = malloc(sizeof(char));
    block[1] = malloc(sizeof(char) * key->col * 2 + 1);
    for (int j = 0; i != key->rows + 1; j++){
        block[i][j] = ' ';
        for (; j == key->col * 2; i++, j = -1)
            block[i + 1] = malloc(sizeof(char) * key->col * 2 + 1);
    }
    block[i] = NULL;
    return block;
}

t_blk* init_block(void)
{
    t_blk* blk = malloc(sizeof(t_blk));
    return blk;
}