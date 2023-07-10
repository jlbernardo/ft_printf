# -*- Makefile -*-

NAME = libftprintf.a
LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Werror -Wall -Wextra -g3 -I libft/

MAKE_LIBFT = make -C ./libft

MANDATORY_SRC = ft_printf.c
MANDATORY_SRC += $(addprefix utils/, ft_handle_char.c ft_handle_int.c ft_handle_lower_hex.c ft_handle_percent.c ft_handle_ptr.c ft_handle_str.c ft_handle_unsigned_int.c ft_handle_upper_hex.c)

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)

all: libft $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	ar -rcsT $(NAME) $@

$(NAME): $(MANDATORY_OBJ)
	ar -rcsT $(NAME) $(LIBFT)

libft:
	$(MAKE_LIBFT)

clean:
	rm -rf $(MANDATORY_OBJ)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE_LIBFT) fclean

re: fclean all

.PHONY: all libft clean fclean re