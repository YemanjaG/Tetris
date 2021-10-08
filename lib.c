/*
** EPITECH PROJECT, 2019
** lib tetris
** File description:
** lib tetris
*/

#include "./struct.h"

int str_to_int(char* str)
{
    int val = 0;
    for (str; *str; str++){
        if (*str >= '0' && *str <= '9') {
            val *= 10;
            val += *str - '0';
        } else
            return (val);
    }
    return (val);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int a = 0;
    for (i = 0; dest[i] != '\0'; i++);
    while (src[a] != '\0'){
        dest[i] = src[a];
        a++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char** str_to_tab(char* str)
{
    char** tab = malloc(sizeof(char*) * my_strlen(str));
    int x = 1;
    int y = 0;
    tab[0] = malloc(sizeof(char));
    tab[1] = malloc(sizeof(char) * my_strlen(str));
    for (int i = 0; str[i] != '\0'; i++, y++){
        if (str[i] == '\n'){
            tab[x][y] = '\0';
            x++;
            y = -1;
            tab[x] = malloc(sizeof(char) * my_strlen(str));
        } else
            tab[x][y] = str[i];
    }
    tab[x] = NULL;
    return tab;
}

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strdup(char const *src, int size)
{
    char *dest = malloc(sizeof(char) * size);
    dest = my_strcpy(dest, src);
    return dest;
}