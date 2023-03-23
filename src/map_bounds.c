/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_bounds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:50:47 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/23 19:51:03 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bounds	get_map_bounds(t_map *map)
{
	t_bounds	bounds;
	int			x;
	int			y;

	bounds.x_max = 0;
	bounds.x_min = 0;
	bounds.y_max = 0;
	bounds.y_min = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->map[y][x].x < bounds.x_min)
				bounds.x_min = map->map[y][x].x;
			if (map->map[y][x].x > bounds.x_max)
				bounds.x_max = map->map[y][x].x;
			if (map->map[y][x].y < bounds.y_min)
				bounds.y_min = map->map[y][x].y;
			if (map->map[y][x].y > bounds.y_max)
				bounds.y_max = map->map[y][x].y;
			x++;
		}
		y++;
	}
	return (bounds);
}
