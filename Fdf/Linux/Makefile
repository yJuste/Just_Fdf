NAME = fdf

CC = cc
CFLAGS = -Wall -Wextra -Werror

MINILIBX = libmlx_Linux.a
PATH_MINILIBX = minilibx_linux

MLXFLAGS = -lm -lmlx -lXext -lX11

PRINTF = libftprintf.a
PATH_PRINTF = Printf_fd

SRC =	ft_fdf.c				\
	ft_fdf_next.c				\
	ft_fdf_2.c				\
	ft_menu.c				\
	ft_macros.c				\
	ft_menu_next.c				\
	ft_cam_movements.c			\
	ft_lib.c				\
	ft_lib_2.c				\
	ft_color.c				\
	ft_bresenham.c				\
	ft_cohen_sutherland_clip.c		\
	ft_split.c				\
	Get_Next_Line/get_next_line.c

OBJ = $(SRC:.c=.o)

NORMINETTE =	*.c		\
		*.h		\
		Get_Next_Line	\
		Printf_fd

RESET			= "\033[0m"
GREEN			= "\033[92m"	# Green
RED			= "\033[91m"	# Red

all: $(NAME)

$(NAME): $(OBJ) $(PRINTF) $(MINILIBX)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L $(PATH_PRINTF) -lftprintf -L $(PATH_MINILIBX) -lmlx_Linux $(MLXFLAGS)
	@echo $(GREEN)"--- EXECUTABLE ./$(NAME) is ready ---"$(RESET)

bonus: $(NAME)

$(PRINTF):
	$(MAKE) -C $(PATH_PRINTF)

$(MINILIBX):
	@$(MAKE) -s -C $(PATH_MINILIBX) all > /dev/null 2>&1

clean:
	rm -f $(OBJ)
	@$(MAKE) -C $(PATH_PRINTF) clean
	@$(MAKE) -C $(PATH_MINILIBX) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(PATH_PRINTF) fclean
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

re: fclean all

rf: re
	rm -f $(OBJ)
	rm -f $(NAME)
	@$(MAKE) -C $(PATH_PRINTF) fclean
	@$(MAKE) -C $(PATH_MINILIBX) clean
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

s:
	ls -lh $(NAME)

help:
	@echo $(GREEN)
	@head -n 15 ft_fdf.h
	@echo $(RESET)

norm:
	@norminette $(NORMINETTE)

.PHONY: all clean fclean re rf s help norm
