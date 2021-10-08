/*
** EPITECH PROJECT, 2019
** init_game tetris
** File description:
** init_game tetris
*/

#include "./struct.h"

char** create_next(t_key* key)
{
    char** next = malloc(sizeof(char*) * 8);
    next[0] = malloc(sizeof(char));
    next[1] = my_strdup("/-next--------\\", 16);
    next[2] = my_strdup("|             |", 16);
    next[3] = my_strdup("|             |", 16);
    next[4] = my_strdup("|             |", 16);
    next[5] = my_strdup("|             |", 16);
    next[6] = my_strdup("\\-------------/", 16);
    next[7] = NULL;
    return next;
}

char** create_pannel(t_key* key)
{
    char** pannel = malloc(sizeof(char*) * 12);
    pannel[0] = malloc(sizeof(char));
    pannel[1] = my_strdup("/--------------------------\\", 29);
    pannel[2] = my_strdup("|                          |", 29);
    pannel[3] = my_strdup("| High Score :             |", 29);
    pannel[4] = my_strdup("| Score :                  |", 29);
    pannel[5] = my_strdup("|                          |", 29);
    pannel[6] = my_strdup("| Lines :                  |", 29);
    pannel[7] = my_strdup("| Level :                  |", 29);
    pannel[8] = my_strdup("|                          |", 29);
    pannel[9] = my_strdup("| Timer :                  |", 29);
    pannel[10] = my_strdup("\\--------------------------/", 29);
    pannel[11] = NULL;
    return pannel;
}

char** create_game_board(t_key* key)
{
    char** board = malloc(sizeof(char*) * key->rows + 3);
    int i = 1;
    board[0] = malloc(sizeof(char));
    board[1] = malloc(sizeof(char) * key->col * 2 + 3);
    for (int j = 0; i != key->rows + 3; j++){
        if ((i == 1 || i == key->rows + 2) &&
            (j == 0 || j == key->col * 2 + 2))
            board[i][j] = '+';
        if (board[i][j] != '+' && (i == 1 || i == key->rows + 2))
            board[i][j] = '-';
        else if (board[i][j] != '+' && (j == 0 || j == key->col * 2 + 2))
            board[i][j] = '|';
        if (board[i][j] != '+' && board[i][j] != '-' && board[i][j] != '|')
            board[i][j] = ' ';
        for (; j == key->col * 2 + 2; i++, j = -1)
            board[i + 1] = malloc(sizeof(char) * key->col * 2 + 3);
    }
    board[i] = NULL;
    return board;
}
