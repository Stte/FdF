NAME 		= FdF

S			= src/
O			= obj/
I			= inc/
LIBFT_I		= libft/inc

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
D		=
INCLUDES	= -I$I -I$(LIBFT_I)
LIBRARIES	= -L./libft -lft

AR			= ar
ARFLAGS		= rcs

SRC = \
$S/main.c		$S/render.c		$S/map_size.c	$S/utils.c		$S/load_map.c	\
$S/projection.c	$S/transform.c	$S/center_map.c	$S/map_bounds.c	$S/scale.c		\
$S/fit_map.c	$S/colors.c		$S/mlx_hooks.c	$S/get_distance.c				\
$S/get_gradient.c
OBJ			= $(SRC:$S%=$O%.o)

RM			= /bin/rm -f
RMDIR		= /bin/rm -rf

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a
LIBFT_FLAGS	= $D

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%
	$(CC) $(CFLAGS) $(INCLUDES) $D -Imlx -c $< -o $@

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBRARIES) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIBFT):
	make FLAGS=$(LIBFT_FLAGS) -C $(LIBFT_DIR)

cleanobjdir: $O
	$(RMDIR) $O

clean: cleanobjdir

fclean: clean
	make fclean -C libft
	$(RM) $(NAME)

re:
	@make fclean
	@make all
