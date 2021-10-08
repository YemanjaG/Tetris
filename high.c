/*
** EPITECH PROJECT, 2019
** high tetris
** File description:
** high tetris
*/

#include "./struct.h"

char *int_to_str(long long nb)
{
    int len = 0;
    char* str;
    int	tmp = nb;
    for (len; tmp > 0; len++)
        tmp /= 10;
    str = malloc(sizeof(*str) * (len + 1));
    str[len] = '\0';
    for (len; len--; nb /= 10)
        str[len] = nb % 10 + '0';
    return (str);
}

void highscore(t_var* var)
{
    int fd = open("./high.txt", O_RDONLY);
    char* str = malloc(sizeof(char) * 10);
    char* score;
    read(fd, str, 10);
    if (str_to_int(str) < var->score){
        score = int_to_str(var->score);
        close(fd);
        fd = open("./high.txt", O_TRUNC | O_WRONLY);
        close(fd);
        fd = open("./high.txt", O_WRONLY);
        write(fd, score, strlen(score));
        var->highscore = var->score;
    } else
        var->highscore = str_to_int(str);
    close(fd);
}