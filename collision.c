/*
** EPITECH PROJECT, 2019
** collisiontetris
** File description:
** collision tetris
*/

#include "./struct.h"

int check_turn(t_var* var, char** new_shape)
{
    int j = 0;
    int ret = 0;
    for (int i = 1; new_shape[i] != NULL; j++){
        if (new_shape[i][j] == '\0'){
            j = -1;
            i++;
        } else if (var->blk->block[var->fall->y + i - 1] == NULL ||
        (new_shape[i][j] == '*' &&
        (var->blk->block[var->fall->y + i - 1][var->fall->x + j - 31] == '*' ||
        var->blk->block[var->fall->y + i - 1][var->fall->x + j - 31] == '\0'))){
            return -1;
        }
    }
    return ret;
}

int check_left(t_var* var)
{
    int j = 0;
    int ret = 0;
    for (int i = 1; var->fall->g_shape[i] != NULL; j++){
        if (var->fall->g_shape[i][j] == '\0'){
            j = -1;
            i++;
        } else if (var->fall->g_shape[i][j] == '*' &&
        var->blk->block[var->fall->y + i - 1][var->fall->x + j - 33] == '*'){
            ret = -1;
        }
    }
    return ret;
}

int check_right(t_var* var)
{
    int j = 0;
    int ret = 0;
    for (int i = 1; var->fall->g_shape[i] != NULL; j++){
        if (var->fall->g_shape[i][j] == '\0'){
            j = -1;
            i++;
        } else if (var->fall->g_shape[i][j] == '*' &&
        var->blk->block[var->fall->y + i - 1][var->fall->x + j - 29] == '*'){
            ret = -1;
        }
    }
    return ret;
}
