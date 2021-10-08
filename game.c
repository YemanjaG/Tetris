/*
** EPITECH PROJECT, 2019
** game tetris
** File description:
** game tetris
*/

#include "./struct.h"

void draw_borders(t_var* var)
{
    for (int j = 1; var->pannel[j] != NULL; j++)
        mvprintw(8 + j, 0, "%s", var->pannel[j]);
    for (int j = 1; var->board[j] != NULL; j++)
        mvprintw(j, 30, "%s", var->board[j]);
    if (var->key->next == 1) {
        for (int j = 1; var->next[j] != NULL; j++)
            mvprintw(j, 34 + (var->key->col * 2), "%s", var->next[j]);
    }
    mvprintw(11, 15, "%d", var->highscore);
    mvprintw(12, 10, "%d", var->score);
    mvprintw(14, 10, "%d", var->lines);
    mvprintw(15, 10, "%d", var->key->lvl);
    mvprintw(17, 10, "%d", var->tick / 20);
}

void new_tetrimino2(t_var* var, t_ttr* tmp)
{
    var->fall->g_shape = var->nxt->g_shape;
    var->fall->col = var->nxt->col;
    var->fall->x = var->nxt->x;
    var->fall->y = var->nxt->y;
    var->fall->height = var->nxt->height;
    var->fall->width = var->nxt->width;
    var->fall->color = var->nxt->color;
    var->nxt->g_shape = tmp->g_shape;
    var->nxt->col = 32 + var->key->col;
    var->nxt->x = var->nxt->col - (tmp->width + tmp->width % 2);
    var->nxt->y = var->nxt->row;
    var->nxt->height = tmp->height;
    var->nxt->width = tmp->width;
    var->nxt->color = tmp->color;
}

void new_tetrimino(t_var* var)
{
    int nb = (rand()%clock()) % var->size_lst;
    t_ttr *tmp = var->ttr;
    for (int i = 0; i < nb; tmp = tmp->next, i++);
    for (; tmp->error == -1;){
        nb = (rand()%clock()) % var->size_lst;
        tmp = var->ttr;
        for (int i = 0; i < nb; tmp = tmp->next, i++);
    }
    if (var->fall->stat == 2) {
        var->nxt->g_shape = tmp->g_shape;
        var->nxt->col = 32 + var->key->col;
        var->nxt->x = var->nxt->col - (tmp->width + tmp->width % 2);
        var->nxt->y = var->nxt->row;
        var->nxt->height = tmp->height;
        var->nxt->width = tmp->width;
        var->nxt->color = tmp->color;
    }
    new_tetrimino2(var, tmp);
}

void draw_falling(t_var* var)
{
    init_pair(1, var->fall->color, COLOR_BLACK);
    if (var->fall->stat == 0 || var->fall->stat == 2){
        new_tetrimino(var);
        var->fall->stat = 1;
    }
    interact(var);
    attron(COLOR_PAIR(1));
    for (int j = 1; var->fall->g_shape[j] != NULL; j++)
        mvprintw(var->fall->y + j, var->fall->x, "%s", var->fall->g_shape[j]);
    attroff(COLOR_PAIR(1));
    if ((var->tick % (11 - var->key->lvl)) == 0){
        check_add_to_block(var);
        var->fall->y++;
    }
}

void draw_game(t_var* var)
{
    draw_borders(var);
    for (int j = 1; var->blk->block[j] != NULL; j++)
        mvprintw(1 + j, 31, "%s", var->blk->block[j]);
    draw_falling(var);
    check_line(var);
    init_pair(2, var->nxt->color, COLOR_BLACK);
    if (var->key->next == 1){
        attron(COLOR_PAIR(2));
        for (int j = 1; var->nxt->g_shape[j] != NULL; j++)
            mvprintw(1 + j, 38 + (var->key->col * 2), "%s",
            var->nxt->g_shape[j]);
        attroff(COLOR_PAIR(2));
    }
    if (var->key_pressed == 6000){
        mvprintw(10, 29 + var->key->col, "PAUSE");
        mvprintw(0, 0, "\0");
        getch();
    }
    mvprintw(0, 0, "\0");
}