#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include "math.h"
#include <stdlib.h> // for exit
#include "libft.h"

#include <stdio.h> // remove this

#define WIDTH 1000
#define HEIGHT 1000

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

typedef struct	s_bounds
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
}				t_bounds;

typedef struct	s_xy
{
	int	x;
	int	y;
}				t_xy;

void		ft_render(t_vars mlx_vars, t_map map);
int			close_window(t_vars *param);
int			key_down(int keycode, t_vars *mlx_vars);
void		load_map(char *path, t_map *map);
void		get_map_size(int fd, t_map *map);
int			ft_atoi_hex(const char *str);
void		ft_projection(t_map *map, float x_rad, float y_rad);
void		ft_transform(t_map *map, int transform_x, int transform_y);
t_bounds	get_map_bounds(t_map *map);
void		center_map(t_map *map);
void		ft_zoom(t_map *map, float zoom);
void		fit_map(t_map *map);
int			create_rgb(int r, int g, int b);
int			get_r(int rgb);
int			get_g(int rgb);
int			get_b(int rgb);
void		loop_map(void *dst, void *params, t_map *map,
				void (*f)(void *, void *, t_map *, t_xy));

#endif
