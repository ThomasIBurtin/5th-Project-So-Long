CC = gcc
CFLAGS = -Werror -Wall -Wextra
SRC = so_long.c \
      get_next_line.c \
      get_next_line_utils.c \
      fenetre.c \
      creation_asset.c \
      chek_map.c \
      chek_ligne.c \
      chek_dimension.c \
      creation_map.c \
      split.c \
      cerveau.c
OBJ = $(SRC:.c=.o)
MINILIBX_OBJ = minilibx-linux/obj/*.o
NAME = JEUX
LIBS = -Lminilibx-linux -lmlx -I/usr/X11/include -L/usr/X11/lib -lX11 -lXext

all: minilibx_bibliotheque $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MINILIBX_OBJ) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

minilibx_bibliotheque:
	$(MAKE) -C minilibx-linux

clean:
	rm -f $(OBJ)
	$(MAKE) clean -C minilibx-linux

fclean: clean
	rm -f $(NAME)

re: fclean all

