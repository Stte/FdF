/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:39:24 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/30 20:41:23 by tspoof           ###   ########.fr       */
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

void	ft_rotate_x(t_data *data, float rad)
{
	t_bounds	old_bounds;

	old_bounds = get_map_bounds(data->map);
	loop_map(NULL, &rad, data->map, r_x);
	ft_center(data->map, &old_bounds);
}

void	ft_rotate_y(t_data *data, float rad)
{
	t_bounds	old_bounds;

	old_bounds = get_map_bounds(data->map);
	loop_map(NULL, &rad, data->map, r_y);
	ft_center(data->map, &old_bounds);
}

void	ft_rotate_z(t_data *data, float rad)
{
	t_bounds	old_bounds;

	old_bounds = get_map_bounds(data->map);
	loop_map(NULL, &rad, data->map, r_z);
	ft_center(data->map, &old_bounds);
}
// void	ft_rotate_y(t_data data)
// {

// }
// void	ft_rotate_z(t_data data)
// {

// }
