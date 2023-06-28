# -*- Makefile -*-

NAME = libftprintf.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra -g3

MANDATORY_SRC = ft_printf.c

MANDATORY_OBJ = ${MANDATORY_SRC:.c=.o}

all:$(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	ar -rcs $(NAME) $< -o $@

$(NAME): $(MANDATORY_OBJ)

clean:
	rm -rf $(MANDATORY_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re