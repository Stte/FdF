/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bounds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:50:47 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/04 19:33:58 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_bounds	get_map_bounds(t_map *map)
{
	t_bounds	map_bounds;

	ft_bzero(&map_bounds, sizeof(t_bounds));
	map_bounds.x_min = map->grid[0][0].x;
	map_bounds.x_max = map->grid[map->height - 1][map->width - 1].x;
	map_bounds.y_min = map->grid[0][0].y;
	map_bounds.y_max = map->grid[map->height - 1][map->width - 1].y;
	return (map_bounds);
}
