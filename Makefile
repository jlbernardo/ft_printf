# -*- Makefile -*-

NAME = libftprintf.a
LIBFT = ./libft/libft.a

CC = cc
CFLAGS = -Werror -Wall -Wextra -g3 -I libft/

MAKE_LIBFT = make -C ./libft

MANDATORY_SRC = ft_printf.c
MANDATORY_SRC += $(addprefix utils/, ft_handle_char.c ft_handle_int.c ft_handle_lower_hex.c ft_handle_percent.c ft_handle_ptr.c ft_handle_str.c ft_handle_unsigned_int.c ft_handle_upper_hex.c)

BONUS_SRC = ft_printf_bonus.c
BONUS_SRC += $(addprefix utils/, ft_handle_space_bonus.c ft_handle_octothorpe_bonus.c ft_handle_plus_bonus.c)
BONUS_SRC += $(MANDATORY_UTILS)

MANDATORY_OBJ = $(MANDATORY_SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@
	@rm -rf $(NAME)
	ar -rcsT $(NAME) $@

$(NAME): $(MANDATORY_OBJ)
	$(MAKE_LIBFT)
	ar -rcsT $(NAME) $(LIBFT)

bonus: $(BONUS_OBJ) $(NAME)
	
$(BONUS): $(BONUS_OBJ) $(MANDATORY_OBJ)
	ar -rcsT $(NAME) $(BONUS_OBJ)

clean:
	rm -rf $(MANDATORY_OBJ) $(BONUS_OBJ)
	$(MAKE_LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT)

re: fclean all

.PHONY: all libft bonus clean fclean re