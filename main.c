/*
** EPITECH PROJECT, 2019
** main tetris
** File description:
** main tetris
*/

#include "./struct.h"

void display_usage(int ac, char** av)
{
    write(1, "Usage:  ", 8);
    my_putstr(av[0]);
    write(1, " [options]\nOptions:\n --help\t\t\tDisplay", 37);
    write(1, " this help\n -L --level={num}\tStart Tetris at level num (", 56);
    write(1, "def: 1)\n -l --key-left={K}\tMove the tetrimino LEFT using", 56);
    write(1, " the K key (def: left arrow)\n -r --key-right={K}\tMove th", 56);
    write(1, "e tetrimino RIGHT using the K key (def: right arrow)\n -t ", 57);
    write(1, "--key-turn={K}\tTURN the tetrimino clockwise 90d using the", 56);
    write(1, " K key (def: top arrow)\n -d --key-drop={K}\tDROP the tetr", 56);
    write(1, "imino using the K key (def: down arrow)\n -q --key-quit={K", 57);
    write(1, "}\tQUIT the game using the K key (def: 'q' key)\n -p --key", 56);
    write(1, "-pause={K}\tPAUSE/RESTART the game using the K key (def: s", 57);
    write(1, "pace bar)\n --map-size={row,col}\tSet the numbers of rows ", 56);
    write(1, "and columns of the map (def: 20,10)\n -w --without-next\tH", 56);
    write(1, "ide the next tetrimino (def: false)\n -D --debug\t\tDebug ", 55);
    write(1, "mode (def: false)\n", 18);
}

void add_score(t_var* var, int nb2)
{
    if (nb2 == 1)
        var->score += 40;
    else if (nb2 == 2)
        var->score += 100;
    if (nb2 == 3)
        var->score += 300;
    else if (nb2 == 4)
        var->score += 1200;
    if (nb2 > 0)
        highscore(var);
}

void game_loop(int ac, char** av, t_var* var)
{
    char *small_term = "The terminal too small, resize it to play the game";
    initscr();
    keypad(stdscr, TRUE);
    start_color();
    highscore(var);
    for (clear(); 1;){
        if (LINES <= var->key->rows + 2){
            mvprintw(LINES / 2, COLS / 2 - 25, small_term);
            getch();
            refresh();
            clear();
        } else if ((clock() % 50000) == 0){
            var->key_pressed = get_key(var);
            var->tick++;
            draw_game(var);
            check_game_over(var);
            refresh();
            clear();
        }
    }
}

int game(int ac, char** av)
{
    t_var* var = init_var();
    if (ac > 1)
        handle_flags(ac, av, var);
    if (fill_ttrlst(var) == -1) {
        return 84;
    } else if (var->key->debug == 1)
        draw_debug(var);
    var->blk->block = create_block(var->key);
    var->board = create_game_board(var->key);
    var->pannel = create_pannel(var->key);
    var->next = create_next(var->key);
    game_loop(ac, av, var);
}

int main(int ac, char **av)
{
    struct stat buff;
    int b = stat(av[1], &buff);
    int size = buff.st_size + 1;
    int fd = open(av[1], O_RDONLY);
    char *str = malloc(sizeof(char) * size + 1);
    int a = read(fd, str, size + 1);
    if (av[1] != NULL && av[1][0] == '-' && av[1][1] == '-' && av[1][2] == 'h')
        display_usage(ac, av);
    else if (game(ac, av) == 84)
        return 84;
    return 0;
}
