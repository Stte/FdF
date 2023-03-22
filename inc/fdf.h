#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <stdlib.h> // for exit
#include "libft.h"

#include <stdio.h> // remove this

enum
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ESC = 53
};

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_point;

typedef struct s_map
{
	t_point	**map;
	int		width;
	int		height;
}				t_map;

typedef struct	s_bres
{
	int	x0;
	int	x1;
	int	y0;
	int y1;
	int	delta_x;
	int	delta_y;
	int	sign_x;
	int	sign_y;
	int	err;
}				t_bres;

void	render(t_map map);
void	load_map(char *path, t_map *map);
void	get_map_size(int fd, t_map *map);
int		ft_atoi_hex(const char *str);
void	projection(t_map *map);

#endif
