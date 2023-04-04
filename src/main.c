/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/04 20:18:09 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	initialize_map(t_map *map)
{
	fit_map(map);
	ft_center(map, NULL);
}

static void	copy_map(t_map *dest, t_map *src)
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
	data.rads.x_rad = 0.5236;
	data.rads.y_rad = 0.5236;
	data.iso = 1;
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
	// check that the file exists
	fdf(argv[1]);
	return (0);
}
