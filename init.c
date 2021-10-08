/*
** EPITECH PROJECT, 2019
** init tetris
** File description:
** init tetris
*/

#include "./struct.h"

t_key* init_key(void)
{
    t_key* key = malloc(sizeof(t_key));
    key->lvl = 1;
    key->left = KEY_LEFT;
    key->right = KEY_RIGHT;
    key->turn = KEY_UP;
    key->drop = KEY_DOWN;
    key->quit = 'q';
    key->pause = ' ';
    key->rows = 20;
    key->col = 10;
    key->next = 1;
    key->debug = 0;
    key->weird = 0;
    return key;
}

t_temp* init_temp(void)
{
    t_temp* temp = malloc(sizeof(t_temp));
    return temp;
}

t_fall* init_fall(void)
{
    t_fall* fall = malloc(sizeof(t_fall));
    fall->row = 1;
    fall->col = 32;
    fall->stat = 2;
    return fall;
}

t_nxt* init_next(void)
{
    t_nxt* nxt = malloc(sizeof(t_nxt));
    nxt->row = 1;
    nxt->col = 32;
    nxt->stat = 2;
    return nxt;
}

t_var* init_var(void)
{
    t_var* var = malloc(sizeof(t_var));
    var->key = init_key();
    var->temp = init_temp();
    var->fall = init_fall();
    var->nxt = init_next();
    var->blk = init_block();
    var->score = 0;
    var->lines = 0;
    return var;
}