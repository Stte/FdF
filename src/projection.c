/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:54:15 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/30 12:39:46 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static void	do_projection(void *dst, void *param, t_map *map, t_xy xy)
// {

// }

// static void	reset_map_proj(t_map *map_proj, t_map map)
// {

// }

// void	ft_projection(t_map *map, float x_rad, float y_rad)
void	ft_projection(t_map *map, t_map *map_proj, t_rads rads)
{
	int	x;
	int	y;
	float	old_x;
	float	old_y;
	t_bounds	old_bounds;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			old_x = map->grid[y][x].x;
			old_y = map->grid[y][x].y;
			map_proj->grid[y][x].x = (old_x - old_y) * cos(rads.x_rad);
			map_proj->grid[y][x].y = (old_x + old_y) * sin(rads.y_rad) - map->grid[y][x].z;
			x++;
		}
		y++;
	}
	old_bounds = get_map_bounds(map);
	ft_center(map_proj, &old_bounds);
}


