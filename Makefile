# -*- Makefile -*-

NAME = libftprintf.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra -g3

MANDATORY_SRC = ft_printf.c
MANDATORY_SRC += $(addprefix utils/, ft_handle_char.c ft_handle_int.c ft_handle_lower_hex.c ft_handle_percent.c ft_handle_ptr.c ft_handle_str.c ft_handle_unsigned_int.c ft_handle_upper_hex.c)

LIBFT = libft/libft.a

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

all: libft $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	ar -rcs $(NAME) $@

$(NAME): $(LIBFT) $(MANDATORY_OBJ)
	ar -rcsT $(NAME) $(LIBFT)

libft:
	make -C libft

clean:
	rm -rf $(MANDATORY_OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all libft clean fclean re