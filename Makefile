##
## EPITECH PROJECT, 2021
## navy
## File description:
## Makefile for the navy project
##

DEFAULT     =   "\033[00m"
RED         =   "\033[31m"
GREEN       =   "\033[1;32m"
TEAL        =   "\033[1;36m"
YELLOW      =   "\033[1;7;25;33m"
MAGENTA     =   "\033[1;3;4;35m"
YELLOW       =   "\033[5;7;1;31m"
BLINK       =   "\033[5m"
END         =   "\n"

NAME = navy

SRC_P = src/

SRC = $(SRC_P)navy.c \
	$(SRC_P)map.c \
	$(SRC_P)map2.c \
	$(SRC_P)game.c \
	$(SRC_P)communications.c \
	$(SRC_P)get_user_input.c \
	$(SRC_P)print_positions.c

MAIN = $(SRC_P)main.c

MAINOBJ = $(SRC_P)main.o

CFLAGS = -Llib -lmy -Wall

CC = gcc

OBJ = $(SRC:.c=.o)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ && \
	printf $(GREEN)"[+] Compiled $@ "$(DEFAULT)"\n" || \
	printf $(RED)"[-] Failed compiling $@ "$(DEFAULT)"\n"

all: $(NAME) clean

$(NAME): $(OBJ) $(MAINOBJ)
	@make -C lib/my > /dev/null
	@$(CC) -o $(NAME) $(OBJ) $(MAINOBJ) $(CFLAGS) && \
	printf $(GREEN)"[+] Compiled "$(NAME)" "$(DEFAULT)"\n" || \
	printf $(RED)"[-] Failed compiling "$(NAME)" "$(DEFAULT)"\n"

clean:
	@find . -name "*~" -delete -or -name "#*#" -delete
	@find . -name "*.o" -delete
	@find . -name "*.gcda" -delete -or -name "*.gcno" -delete

fclean:
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
