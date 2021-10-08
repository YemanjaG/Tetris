##
## EPITECH PROJECT, 2019
## tetris
## File description:
## tetris makefile
##

SRC	=	*.c	\

NAME	=	tetris

all: $(NAME)

$(NAME):
	@gcc -g3 $(SRC) -o $(NAME) -lncurses

clean:
	@rm -f $(NAME)

fclean:
	@rm -f $(NAME)

re:	fclean all
