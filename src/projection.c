/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:54:15 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/26 17:52:41 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	do_projection(void *dst, void *param, t_map *map, t_xy xy)
// {

// }

void	ft_projection(t_map *map, float x_rad, float y_rad)
{
	int	x;
	int	y;
	float	old_x;
	float	old_y;

	// loop_map(NULL, ?, map, do_projection);

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			old_x = map->grid[y][x].x;
			old_y = map->grid[y][x].y;
			map->grid[y][x].x = (old_x - old_y) * cos(x_rad);
			map->grid[y][x].y = (old_x + old_y) * sin(y_rad) - map->grid[y][x].z;
			x++;
		}
		y++;
	}
}
