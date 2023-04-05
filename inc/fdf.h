/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:30:59 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/05 19:10:40 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <limits.h>
# include "libft.h"

# define WIDTH 1000
# define HEIGHT 1000

enum e_keys
{
	ON_KEYDOWN = 2,
	ON_DESTROY = 17,
	ESC = 53,
	RIGHT = 2,
	LEFT = 0,
	UP = 13,
	DOWN = 1,
	ROTATE_Q = 31,
	ROTATE_E = 32,
	ROTATE_LEFT = 38,
	ROTATE_RIGHT = 37,
	ROTATE_UP = 34,
	ROTATE_DOWN = 40,
	ZOOM_IN = 24,
	ZOOM_OUT = 27,
	TOGGLE_PROJ = 35
};

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}				t_point;

typedef struct s_map
{
	t_point	**grid;
	int		width;
	int		height;
}				t_map;

typedef struct s_bres
{
	int	x0;
	int	x1;
	int	y0;
	int	y1;
	int	delta_x;
	int	delta_y;
	int	sign_x;
	int	sign_y;
	int	err;
}				t_bres;

typedef struct s_bounds
{
	int	x_min;
	int	x_max;
	int	y_min;
	int	y_max;
}				t_bounds;

typedef struct s_xy
{
	int	x;
	int	y;
}				t_xy;

typedef struct s_rads
{
	float	x_rad;
	float	y_rad;
}				t_rads;

typedef struct s_data
{
	t_vars	*mlx_vars;
	t_map	*map;
	t_map	*map_proj;
	t_img	*img;
	t_rads	rads;
	int		iso;
}				t_data;

int			ft_render(t_data *data);
int			close_cross(t_vars *param);
int			key_hook(int keycode, t_data *data);
int			load_map(char *path, t_map *map);
void		get_map_size(int fd, t_map *map);
int			ft_atoi_hex(const char *str);
void		ft_projection(t_map *map, t_map *map_proj, t_rads rads);
void		ft_transform(t_map *map, int transform_x, int transform_y);
t_bounds	get_map_bounds(t_map *map);
void		ft_center(t_map *map, t_bounds *old_bounds);
void		ft_scale(t_map *map, float scale);
void		fit_map(t_map *map);
int			create_rgb(int r, int g, int b);
int			get_r(int rgb);
int			get_g(int rgb);
int			get_b(int rgb);
void		loop_map(void *dst, void *params, t_map *map,
				void (*f)(void *, void *, t_map *, t_xy));
int			get_distance(int x0, int y0, int x1, int y1);
int			get_distance_delta(int delta_x, int delta_y);
float		ft_lerp(float a, float b, float fraction);
int			get_gradient(t_bres bres, int start_color, int end_color);
void		free_split(char **split);
void		ft_zoom(t_map *map, float zoom_amount);
void		ft_rotate(t_data *data, char axis, float rad);
void		plot_line(t_bres bres, t_img *img, int start_color, int end_color);
void		initialize_image(t_data *data);
void		add_hooks(t_data *data);
void		create_window(t_vars *mlx_vars);

#endif
