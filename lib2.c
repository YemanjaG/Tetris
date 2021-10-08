/*
** EPITECH PROJECT, 2019
** lib2 tetris
** File description:
** lib2 tetris
*/

#include "./struct.h"

char* cat_tetri(char* name)
{
    char* ret = malloc(sizeof(char) * my_strlen(name) + 14);
    ret[0] = '.';
    ret[1] = '/';
    ret[2] = 't';
    ret[3] = 'e';
    ret[4] = 't';
    ret[5] = 'r';
    ret[6] = 'i';
    ret[7] = 'm';
    ret[8] = 'i';
    ret[9] = 'n';
    ret[10] = 'o';
    ret[11] = 's';
    ret[12] = '/';
    return ret;
}

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int temp = 0;
    if (nb < 0){
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb >= 10){
        temp = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(temp + 48);
    }
    else
        my_putchar(nb + 48);
    return 0;
}

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
    return 0;
}
