/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/11 16:24:36 by tspoof           ###   ########.fr       */
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
	if (!dest->grid)
		exit (0);
	y = 0;
	while (y < dest->height)
	{
		dest->grid[y] = ft_calloc(dest->width, sizeof(t_point));
		if (!dest->grid[y])
			exit (0);
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
	if (!load_map(path, &map))
		exit (0);
	initialize_map(&map);
	copy_map(&map_proj, &map);
	initialize_image(&data);
	ft_render(&data);
	mlx_loop(mlx_vars.mlx);
}

int	main(int argc, char *argv[])
{
	char	*dot;
	int		has_fdf;

	if (argc != 2)
		return (1);
	dot = ft_strrchr(argv[1], '.');
	if (!dot)
		return (1);
	has_fdf = ft_strncmp(dot, ".fdf", 4);
	if (has_fdf)
		return (1);
	fdf(argv[1]);
	return (0);
}
