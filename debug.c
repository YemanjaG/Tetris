/*
** EPITECH PROJECT, 2019
** debug tetris
** File description:
** debug file for tetris
*/

#include "struct.h"

void draw_ttrlst(t_var* var)
{
    t_ttr *tmp = var->ttr;
    my_putstr("\n");
    for (; tmp; tmp = tmp->next){
        my_putstr("Tetriminos :  Name ");
        my_putstr(tmp->name);
        my_putstr(" :  ");
        if (tmp->error == -1 && my_putstr("Error\n") == 0);
        else {
            my_putstr("Size ");
            my_put_nbr(tmp->width);
            my_putstr("*");
            my_put_nbr(tmp->height);
            my_putstr(" :  Color ");
            my_put_nbr(tmp->color);
            my_putstr(" :\n");
            draw_shape(var, tmp);
        }
    }
}

int the_key(int key)
{
    int a = 0;
    if (key == KEY_LEFT && my_putstr("^EOD") == 0)
        return 0;
    a = 0;
    if (key == KEY_RIGHT && my_putstr("^EOC") == 0)
        return 0;
    a = 0;
    if (key == KEY_UP && my_putstr("^EOA") == 0)
        return 0;
    a = 0;
    if (key == KEY_DOWN && my_putstr("^EOB") == 0)
        return 0;
    a = 0;
    if (key == 32 && my_putstr("(space)") == 0)
        return 0;
    my_putchar(key);
}

void draw_debug_keys(t_var* var)
{
    my_putstr("Key Left :  ");
    the_key(var->key->left);
    my_putstr("\nKey Right :  ");
    the_key(var->key->right);
    my_putstr("\nKey Turn :  ");
    the_key(var->key->turn);
    my_putstr("\nKey Drop :  ");
    the_key(var->key->drop);
    my_putstr("\nKey Quit :  ");
    the_key(var->key->quit);
    my_putstr("\nKey Pause :  ");
    the_key(var->key->pause);
}

bool key_is_pressed(void)
{
    int byteswaiting;
    struct termios term;
    struct termios term2 = term;
    tcgetattr(0, &term);
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);
    ioctl(0, FIONREAD, &byteswaiting);
    tcsetattr(0, TCSANOW, &term);
    return byteswaiting > 0;
}

void draw_debug(t_var* var)
{
    my_putstr("*** DEBUG MODE ***\n");
    draw_debug_keys(var);
    my_putstr("\nNext :  ");
    if (var->key->next == 1)
        my_putstr("Yes\nLevel :  ");
    else
        my_putstr("No\nLevel :  ");
    my_put_nbr(var->key->lvl);
    my_putstr("\nSize :  ");
    my_put_nbr(var->key->rows);
    my_putstr("*");
    my_put_nbr(var->key->col);
    my_putstr("\nTetriminos :  ");
    my_put_nbr(var->size_lst);
    draw_ttrlst(var);
    my_putstr("Press any key to start Tetris\n");
    while (1){
        if (key_is_pressed())
            break;
    }
}