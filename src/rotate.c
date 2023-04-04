/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:39:24 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/04 19:45:57 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	r_z(void *dst, void *params, t_map *map, t_xy xy)
{
	float	rad;
	float	x;
	float	y;

	(void)dst;
	rad = *(float *)params;
	x = map->grid[xy.y][xy.x].x;
	y = map->grid[xy.y][xy.x].y;
	map->grid[xy.y][xy.x].x = x * cos(rad) - y * sin(rad);
	map->grid[xy.y][xy.x].y = x * sin(rad) + y * cos(rad);
}

static void	r_x(void *dst, void *params, t_map *map, t_xy xy)
{
	float	rad;
	float	z;
	float	y;

	(void)dst;
	rad = *(float *)params;
	z = map->grid[xy.y][xy.x].z;
	y = map->grid[xy.y][xy.x].y;
	map->grid[xy.y][xy.x].y = y * cos(rad) - z * sin(rad);
	map->grid[xy.y][xy.x].z = y * sin(rad) + z * cos(rad);
}

static void	r_y(void *dst, void *params, t_map *map, t_xy xy)
{
	float	rad;
	float	x;
	float	z;

	(void)dst;
	rad = *(float *)params;
	z = map->grid[xy.y][xy.x].z;
	x = map->grid[xy.y][xy.x].x;
	map->grid[xy.y][xy.x].z = z * cos(rad) - x * sin(rad);
	map->grid[xy.y][xy.x].x = z * sin(rad) + x * cos(rad);
}

void	ft_rotate(t_data *data, char axis, float rad)
{
	t_bounds	old_bounds;

	old_bounds = get_map_bounds(data->map);
	if (axis == 'x')
		loop_map(NULL, &rad, data->map, r_x);
	if (axis == 'y')
		loop_map(NULL, &rad, data->map, r_y);
	if (axis == 'z')
		loop_map(NULL, &rad, data->map, r_z);
	ft_center(data->map, &old_bounds);
}
