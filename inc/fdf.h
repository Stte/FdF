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

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_map
{
	int	**map;
	int	width;
	int	height;
}				t_map;


void	render(void);
void	get_map_size(int fd, t_map *map);

#endif
