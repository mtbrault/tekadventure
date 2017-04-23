##
## Makefile for scroller in /home/antoine.casse/Desktop/scroller
## 
## Made by Antoine Casse
## Login   <antoine.casse@epitech.net>
## 
## Started on  Sun Jan  1 19:43:23 2017 Antoine Casse
## Last update Sun Apr 23 16:42:57 2017 LAABID Zakaria
##

CC	=	gcc -g3

SRC	=	src/main.c			\
		src/help.c			\
		src/loop.c			\
		src/get_file.c			\
		src/tools.c			\
		src/grid.c			\
		src/colors.c			\
		src/frees.c			\
		src/mouse.c			\
		src/check_class.c		\
		src/fill_player.c		\
		src/position.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tekadventure

CFLAGS	+=	-Wextra -Wall -I./include

LDFLAGS	+=	-L./lib/ -lkaas

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./lib/
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS) -lc_graph_prog_full -lm -lc_graph_prog

clean:
	make clean -C ./lib/
	rm -rf $(OBJ)

fclean:	clean
	make fclean -C ./lib/
	rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
