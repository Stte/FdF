/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:54:15 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/23 19:51:51 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	ft_projection(t_map *map, int zoom)
{
	int	x;
	int	y;
	int	old_x;
	int	old_y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			old_x = map->map[y][x].x * zoom;
			old_y = map->map[y][x].y * zoom;
			map->map[y][x].x = (old_x - old_y) * cos(0.5236);
			map->map[y][x].y = (old_x + old_y) * sin(0.5236) - map->map[y][x].z;
			x++;
		}
		y++;
	}
}
