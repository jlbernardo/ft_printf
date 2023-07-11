# -*- Makefile -*-

NAME = libftprintf.a
LIBFT = ./libft/libft.a
BONUS = libftprintf_bonus.a

CC = cc
CFLAGS = -Werror -Wall -Wextra -g3 -I libft/

MAKE_LIBFT = make -C ./libft

MANDATORY_SRC = ft_printf.c
MANDATORY_UTILS = $(addprefix ./mandatory_utils/, ft_handle_char.c ft_handle_int.c ft_handle_lower_hex.c ft_handle_percent.c ft_handle_ptr.c ft_handle_str.c ft_handle_unsigned_int.c ft_handle_upper_hex.c)

BONUS_SRC = ft_printf_bonus.c
BONUS_SRC += $(addprefix ./bonus_utils/, ft_handle_space_bonus.c ft_handle_octothorpe_bonus.c ft_handle_plus_bonus.c)

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
MANDATORY_OBJ += $(MANDATORY_UTILS:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
BONUS_OBJ += $(MANDATORY_UTILS:.c=.o)

all: libft $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	ar -rcsT $(NAME) $@

$(NAME): $(MANDATORY_OBJ) libft
	ar -rcsT $(NAME) $(LIBFT)

libft:
	$(MAKE_LIBFT)

bonus: $(BONUS)
	ar -rcsT $(NAME)
	
$(BONUS): $(BONUS_OBJ) $(NAME) libft
	ar -rcsT $(BONUS) $(NAME)

clean:
	rm -rf $(MANDATORY_OBJ) $(BONUS_OBJ)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -rf $(NAME) $(BONUS)
	$(MAKE_LIBFT) fclean

re: fclean all

.PHONY: all libft bonus clean fclean re