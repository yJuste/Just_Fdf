NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c		\
	ft_printf_2.c		\
	ft_print_percent.c	\
	ft_print_c.c		\
	ft_print_s.c		\
	ft_print_p.c		\
	ft_print_di.c		\
	ft_print_di_next.c	\
	ft_print_ux.c		\
	ft_print_ux_next.c	\
	ft_printf_lib.c		\
	ft_printf_lib_2.c	\
	ft_printf_lib_3.c	\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC)
	ar -rcs $(NAME) $(OBJ)

bonus: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

rf: re
	rm -f $(OBJ)
	rm -f $(NAME)

s:
	ls -lh $(NAME)

.PHONY: all clean fclean re rf s
