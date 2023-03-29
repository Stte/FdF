/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/29 17:21:06 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

#include <stdio.h> // remove this

void	debug_print_map(t_map *map) // remove this function
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_putnbr_fd(map->grid[y][x].z, 1);
			ft_putstr_fd("	", 1);
			x++;
		}
		ft_putchar_fd('\n', 1);
		y++;
	}
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("---------------------\n", 1);
	ft_putchar_fd('\n', 1);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_putnbr_fd(map->grid[y][x].color, 1);
			ft_putstr_fd("	", 1);
			x++;
		}
		ft_putchar_fd('\n', 1);
		y++;
	}
}

static void	create_window(t_vars *mlx_vars)
{
	mlx_vars->mlx = mlx_init();
	mlx_vars->win = mlx_new_window(mlx_vars->mlx, WIDTH, HEIGHT, "FdF");
}

static void	add_hooks(t_data *data)
{
	t_vars	*mlx_vars;

	mlx_vars = data->mlx_vars;
	mlx_hook(mlx_vars->win, ON_DESTROY, 0, close_cross, mlx_vars);
	mlx_hook(mlx_vars->win, ON_KEYDOWN, 0, key_hook, data);
}

static void	initialize_image(t_data *data)
{
	t_img	*img;

	img = data->img;
	img->img = mlx_new_image(data->mlx_vars->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
								&img->line_length, &img->endian);
}

static void initialize_map(t_map *map)
{
	fit_map(map);
	ft_center(map, NULL);
}

static void copy_map(t_map *dest, t_map *src)
{
	int	y;

	dest->height = src->height;
	dest->width = src->width;
	dest->grid = ft_calloc(dest->height, sizeof(t_point *));
	y = 0;
	while (y < dest->height)
	{
		dest->grid[y] = ft_calloc(dest->width, sizeof(t_point));
		ft_memcpy(dest->grid[y], src->grid[y], sizeof(t_point) * dest->width);
		y++;
	}
}

static void	fdf(char *path)
{
	t_data	data;
	t_map	map;
	t_vars	mlx_vars;
	t_img	img;
	t_map	map_proj;

	data.mlx_vars = &mlx_vars;
	data.map = &map;
	data.img = &img;
	data.proj.x_rad = 0.5236;
	data.proj.y_rad = 0.5236;
	data.map_proj = &map_proj;
	create_window(&mlx_vars);
	add_hooks(&data);
	load_map(path, &map);
	initialize_map(&map);
	copy_map(&map_proj, &map);
	initialize_image(&data);
	ft_render(&data);
	mlx_loop(mlx_vars.mlx);
}


int	main(int argc, char *argv[])
{
	if (argc)
		;
	printf("%d\n", getpid());
	// check that the file exists
	fdf(argv[1]);
	return (0);
}
