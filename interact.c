/*
** EPITECH PROJECT, 2019
** interact tetris
** File description:
** interact tetris
*/

#include "./struct.h"

void delete_line(t_var* var, int i)
{
    for (int j = 0; var->blk->block[i][j] != '\0';j++)
        var->blk->block[i][j] = ' ';
    var->lines++;
    if (var->lines % 10 == 0)
        var->key->lvl++;
    for (int j = 0; i != 1; j++){
        var->blk->block[i][j] = var->blk->block[i - 1][j];
        if (var->blk->block[i][j] == '\0'){
            i--;
            j = -1;
        }
    }
}

void check_line(t_var* var)
{
    int i = 1;
    int nb = 0;
    int nb2 = 0;
    for (int j = 0; var->blk->block[i] != NULL; j++){
        if (var->blk->block[i][j] == '*')
            nb++;
        else if (var->blk->block[i][j] == '\0'){
            nb = 0;
            j = -1;
            i++;
        }
        if (nb == var->key->col){
            delete_line(var, i);
            nb2++;
            nb = 0;
        }
    }
    add_score(var, nb2);
}

char** turn(t_var* var)
{
    int i = var->fall->height; int x = 0; int y = 1;
    char** new_shape = malloc(sizeof(char*) * (var->fall->width + 2));
    new_shape[0] = malloc(sizeof(char));
    new_shape[1] = malloc(sizeof(char) * (var->fall->height * 2) - 1);
    for (int j = 0; j <= (var->fall->width * 2) - 1; i--, x += 2){
        if (i == 0 && (x = 0) == 0 && (j+= 2) >= 0 && (y++) >= 1){
            i = var->fall->height;
            new_shape[y] = malloc(sizeof(char) * (var->fall->height * 2) - 1);
        }
        if (var->fall->g_shape[i][j] == '*' && j <= (var->fall->width * 2) - 1){
            new_shape[y][x] = '*';
            new_shape[y][x + 1] = ' ';
        } else if (var->fall->g_shape[i][j] != '*' &&
        j <= (var->fall->width * 2) - 1){
            new_shape[y][x] = ' ';
            new_shape[y][x + 1] = ' ';
        }
    }
    new_shape[var->fall->width + 1] = NULL;
    return new_shape;
}

void interact(t_var* var)
{
    int x = 0;
    char** temp;
    if (var->key_pressed == 1000 && var->fall->x > 32 &&
    check_left(var) == 0 && (var->fall->x -= 2) > -1000);
    if (var->key_pressed == 2000 && var->fall->x < ((2 * var->key->col + 32) -
    (var->fall->width * 2)) && check_right(var) == 0) {
        var->fall->x += 2;
    } else if (var->key_pressed == 3000){
        temp = turn(var);
        if (check_turn(var, temp) == 0){
            var->fall->g_shape = temp;
            x = var->fall->width;
            var->fall->width = var->fall->height;
            var->fall->height = x;
        }
    }
    if (var->key_pressed == 4000)
        for (; check_add_to_block(var) != -1; var->fall->y++);
    else if (var->key_pressed == 5000)
        exit(0);
}

int get_key(t_var* var)
{
    int key_pressed;
    nodelay(stdscr, TRUE);
    key_pressed = getch();
    if (key_pressed == var->key->left)
        key_pressed = 1000;
    else if (key_pressed == var->key->right)
        key_pressed = 2000;
    if (key_pressed == var->key->turn)
        key_pressed = 3000;
    else if (key_pressed == var->key->drop)
        key_pressed = 4000;
    if (key_pressed == var->key->quit)
        key_pressed = 5000;
    else if (key_pressed == var->key->pause)
        key_pressed = 6000;
    nodelay(stdscr, FALSE);
    return key_pressed;
}