NAME = fdf

CC = cc
CFLAGS = -g -framework OpenGL -framework AppKit

SRC =	ft_fdf.c

OBJ = $(SRC:.c=.o)

RESET			= "\033[0m"
GREEN			= "\033[92m"	# Green
RED			= "\033[91m"	# Red

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo $(GREEN)"--- EXECUTABLE ./$(NAME) is ready ---"$(RESET)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

re: fclean all

rf: re
	rm -f $(OBJ)
	rm -f $(NAME)
	@echo $(RED)"--- EXECUTABLE ./$(NAME) is removed ---"$(RESET)

s:
	ls -lh $(NAME)

help:
	@echo $(GREEN)
	@head -n 13 ft_fdf.c
	@echo $(RESET)

.PHONY: all clean fclean re rf s help
