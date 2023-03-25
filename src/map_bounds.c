/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:50:47 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/25 17:39:26 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	do_get_map_bounds(void *dst, void *params, t_map *map, t_xy xy)
{
	t_bounds	*bounds;

	(void)params;
	bounds = (t_bounds *)dst;
	if (map->map[xy.y][xy.x].x < bounds->x_min)
		bounds->x_min = map->map[xy.y][xy.x].x;
	if (map->map[xy.y][xy.x].x > bounds->x_max)
		bounds->x_max = map->map[xy.y][xy.x].x;
	if (map->map[xy.y][xy.x].y < bounds->y_min)
		bounds->y_min = map->map[xy.y][xy.x].y;
	if (map->map[xy.y][xy.x].y > bounds->y_max)
		bounds->y_max = map->map[xy.y][xy.x].y;
}

t_bounds	get_map_bounds(t_map *map)
{
	t_bounds	map_bounds;

	ft_bzero(&map_bounds, sizeof(t_bounds));
	loop_map(&map_bounds, NULL, map, do_get_map_bounds);
	return(map_bounds);
}
