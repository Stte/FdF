/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/28 19:41:17 by tspoof           ###   ########.fr       */
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

// static void	add_hooks(t_vars *mlx_vars, t_map *map)
static void	add_hooks(t_data *data)
{
	t_vars	*mlx_vars;

	mlx_vars = data->mlx_vars;
	// mlx_key_hook(mlx_vars->win, key_hook, data);
	// mlx_mouse_hook(mlx_vars->win, mouse_hook, data);
	mlx_hook(mlx_vars->win, ON_DESTROY, 0, close_cross, mlx_vars);
	mlx_hook(mlx_vars->win, ON_KEYDOWN, 0, key_hook, data);
}

static void initialize_map(t_map *map)
{
	fit_map(map);
	// ft_projection(map, 0.5236, 0.5236);
	// fit_map(map);
	ft_center(map, NULL);
}

static void	initialize_image(t_data *data)
{
	t_img	*img;

	img = data->img;
	img->img = mlx_new_image(data->mlx_vars->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
								&img->line_length, &img->endian);

}

static void	fdf(char *path)
{
	t_data	data;
	t_map	map;
	t_vars	mlx_vars;
	t_img	img;

	data.mlx_vars = &mlx_vars;
	data.map = &map;
	data.img = &img;
	create_window(&mlx_vars);
	add_hooks(&data);
	load_map(path, &map);
	initialize_map(&map);
	initialize_image(&data);
	ft_render(&data);
	// mlx_loop_hook(mlx_vars.mlx, ft_render, &data);
	mlx_loop(mlx_vars.mlx);
	// ft_render(mlx_vars, map);
	// debug_print_map(&map);
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
