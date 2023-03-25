/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/25 14:58:16 by tspoof           ###   ########.fr       */
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
			ft_putnbr_fd(map->map[y][x].z, 1);
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
			ft_putnbr_fd(map->map[y][x].color, 1);
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

//TODO:

// loop_map((*f)());

static void	fdf(char *path)
{
	t_map	map;
	t_vars	mlx_vars;

	create_window(&mlx_vars);
	load_map(path, &map);
	fit_map(&map);
	ft_projection(&map, 0.5236, 0.5236);
	fit_map(&map);
	center_map(&map);
	ft_render(mlx_vars, map);
	// debug_print_map(&map);
}

int	main(int argc, char *argv[])
{
	if (argc)
		;
	fdf(argv[1]);
	return (0);
}
