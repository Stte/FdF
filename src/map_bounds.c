/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:50:47 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/30 19:25:02 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	do_get_map_bounds(void *dst, void *params, t_map *map, t_xy xy)
// {
// 	t_bounds	*bounds;

// 	(void)params;
// 	bounds = (t_bounds *)dst;
// 	if (map->grid[xy.y][xy.x].x < bounds->x_min)
// 		bounds->x_min = map->grid[xy.y][xy.x].x;
// 	if (map->grid[xy.y][xy.x].x > bounds->x_max)
// 		bounds->x_max = map->grid[xy.y][xy.x].x;
// 	if (map->grid[xy.y][xy.x].y < bounds->y_min)
// 		bounds->y_min = map->grid[xy.y][xy.x].y;
// 	if (map->grid[xy.y][xy.x].y > bounds->y_max)
// 		bounds->y_max = map->grid[xy.y][xy.x].y;
// }
static void	do_get_map_bounds(t_bounds *bounds, t_map *map)
{
	bounds->x_min = map->grid[0][0].x;
	bounds->x_max = map->grid[map->height-1][map->width-1].x;
	bounds->y_min = map->grid[0][0].y;
	bounds->y_max = map->grid[map->height-1][map->width-1].y;
}

t_bounds	get_map_bounds(t_map *map)
{
	t_bounds	map_bounds;

	ft_bzero(&map_bounds, sizeof(t_bounds));
	// map_bounds.x_min = INT_MAX;
	// map_bounds.y_min = INT_MAX;
	// loop_map(&map_bounds, NULL, map, do_get_map_bounds);
	do_get_map_bounds(&map_bounds, map);
	return(map_bounds);
}
