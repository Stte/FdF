/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:54:15 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/25 14:20:58 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	ft_projection(t_map *map, float x_rad, float y_rad)
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
			old_x = map->map[y][x].x;
			old_y = map->map[y][x].y;
			map->map[y][x].x = (old_x - old_y) * cos(x_rad);
			map->map[y][x].y = (old_x + old_y) * sin(y_rad) - map->map[y][x].z;
			x++;
		}
		y++;
	}
}
