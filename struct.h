/*
** EPITECH PROJECT, 2019
** struct tetris
** File description:
** all the includes for tetris
*/

#include <ncurses.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <sys/ioctl.h>
#include <termios.h>

typedef struct keys
{
    int lvl;
    int left;
    int right;
    int turn;
    int drop;
    int quit;
    int pause;
    int rows;
    int col;
    int next;
    int debug;
    int weird;
}t_key;

typedef struct temp
{
    int error;
    char* name;
    int width;
    int height;
    int color;
    char** shape;
    char** g_shape;
}t_temp;

typedef struct ttr
{
    int error;
    char* name;
    int width;
    int height;
    int color;
    char** shape;
    char** g_shape;
    struct ttr *next;
}t_ttr;

typedef struct block
{
    char** block;
}t_blk;

typedef struct fall
{
    int stat;
    int x;
    int y;
    int row;
    int col;
    char** g_shape;
    int height;
    int width;
    int color;
}t_fall;

typedef struct nxt
{
    int stat;
    int x;
    int y;
    int row;
    int col;
    char** g_shape;
    int height;
    int width;
    int color;
}t_nxt;

typedef struct var
{
    t_key* key;
    t_ttr* ttr;
    t_temp* temp;
    t_fall* fall;
    t_nxt* nxt;
    t_blk* blk;
    char** board;
    char** pannel;
    char** next;
    int score;
    int highscore;
    int lines;
    int key_pressed;
    int size_lst;
    long long tick;
}t_var;

t_key* init_key(void);
t_var* init_var(void);
t_blk* init_block(void);
int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
char *my_strdup(char const *src, int size);
int my_strlen(char const *str);
int fill_ttrlst(t_var* var);
char** str_to_tab(char* str);
void draw_ttrlst(t_var* var);
char *my_strcat(char *dest, char const *src);
int str_to_int(char* str);
void draw_debug(t_var* var);
void draw_game(t_var* var);
int handle_flags(int ac, char** av, t_var* var);
char** create_next(t_key* key);
char** create_pannel(t_key* key);
char** create_game_board(t_key* key);
char** create_block(t_key* key);
char* cat_tetri(char* name);
int check_add_to_block(t_var* var);
void check_game_over(t_var* var);
int get_key(t_var* var);
void interact(t_var* var);
void check_line(t_var* var);
int check_left(t_var* var);
int check_right(t_var* var);
int check_turn(t_var* var, char** new_shape);
void add_score(t_var* var, int nb2);
void highscore(t_var* var);
char** get_sorted_tab(t_var *var);
void draw_shape(t_var* var, t_ttr* tmp);