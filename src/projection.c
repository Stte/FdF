/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:54:15 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/28 20:29:34 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	do_projection(void *dst, void *param, t_map *map, t_xy xy)
// {

// }

// void	ft_projection(t_map *map, float x_rad, float y_rad)
t_map	ft_projection(t_map map, float x_rad, float y_rad)
{
	int	x;
	int	y;
	float	old_x;
	float	old_y;
	t_map map_cpy;

	// ft_memcpy(&map_cpy.grid, &map.grid, sizeof(t_point **) * sizeof(t_point *) * map.width * map.height);
	// map_cpy.height = map.height;
	// map_cpy.width = map.width;
	// loop_map(NULL, ?, map, do_projection);

	y = 0;
	while (y < map_cpy.height)
	{
		x = 0;
		while (x < map_cpy.width)
		{
			old_x = map_cpy.grid[y][x].x;
			old_y = map_cpy.grid[y][x].y;
			map_cpy.grid[y][x].x = (old_x - old_y) * cos(x_rad);
			map_cpy.grid[y][x].y = (old_x + old_y) * sin(y_rad) - map_cpy.grid[y][x].z;
			x++;
		}
		y++;
	}
	return (map_cpy);
}
