/*
** EPITECH PROJECT, 2019
** flag tetris
** File description:
** flag tetris
*/

#include "./struct.h"

void fast_flags2(int ac, char** av, t_var* var, int i)
{
    if (av[i][2] == 'm' && av[i][3] == 'a' && av[i][4] == 'p'){
        if (var->key->weird == 0)
            var->key->rows = str_to_int(&av[i][11]);
        else if (var->key->weird == 1)
            var->key->col = str_to_int(&av[i][11]);
        var->key->weird++;
    } else if (av[i][2] == 'w' && av[i][3] == 'i' && av[i][4] == 't')
        var->key->next = 0;
}

void fast_flags(int ac, char** av, t_var* var, int i)
{
    if (av[i][2] == 'l' && av[i][3] == 'e' && av[i][4] == 'v'){
        var->key->lvl = str_to_int(&av[i][9]);
    }
    if (av[i][2] == 'd' && av[i][3] == 'e' && av[i][4] == 'b'){
        var->key->debug = 1;
    } else if (av[i][2] == 'k' && av[i][3] == 'e' && av[i][4] == 'y'){
        if (av[i][6] == 'l' && av[i][7] == 'e' && av[i][8] == 'f')
            var->key->left = av[i][11];
        else if (av[i][6] == 'r' && av[i][7] == 'i' && av[i][8] == 'g')
            var->key->right = av[i][12];
        if (av[i][6] == 't' && av[i][7] == 'u' && av[i][8] == 'r')
            var->key->turn = av[i][11];
        else if (av[i][6] == 'd' && av[i][7] == 'r' && av[i][8] == 'o')
            var->key->drop = av[i][11];
        if (av[i][6] == 'q' && av[i][7] == 'u' && av[i][8] == 'i')
            var->key->quit = av[i][11];
        else if (av[i][6] == 'p' && av[i][7] == 'a' && av[i][8] == 'u')
            var->key->pause = av[i][12];
    } else
        fast_flags2(ac, av, var, i);
}

void normal_flags2(int ac, char** av, t_var* var, int i)
{
    int a = 0;
    if (av[i][1] == 'd' && av[i + 1] != NULL)
        var->key->drop = av[i + 1][0];
    else if (av[i][1] == 'q' && av[i + 1] != NULL)
        var->key->quit = av[i + 1][0];
    a = 0;
    if (av[i][1] == 'p' && av[i + 1] != NULL)
        var->key->pause = av[i + 1][0];
    else if (av[i][1] == 'w')
        var->key->next = 0;
    a = 0;
    if (av[i][1] == 'D')
        var->key->debug = 1;

}

void normal_flags(int ac, char** av, t_var* var, int i)
{
    int a = 0;
    if (av[i][1] == 'L' && av[i + 1] != NULL)
        var->key->lvl = str_to_int(av[i + 1]);
    else if (av[i][1] == 'l' && av[i + 1] != NULL)
        var->key->left = av[i + 1][0];
    a = 0;
    if (av[i][1] == 'r' && av[i + 1] != NULL)
        var->key->right = av[i + 1][0];
    else if (av[i][1] == 't' && av[i + 1] != NULL)
        var->key->turn = av[i + 1][0];
    normal_flags2(ac, av, var, i);
}

int handle_flags(int ac, char** av, t_var* var)
{
    for (int i = 1; av[i]; i++){
        if (av[i][0] == '-' && av[i][1] == '-')
            fast_flags(ac, av, var, i);
        else if (av[i][0] == '-')
            normal_flags(ac, av, var, i);
    }
}