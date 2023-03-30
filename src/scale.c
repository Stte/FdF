/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:58:20 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/30 14:26:07 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scale(t_map *map, float scale)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->grid[y][x].x = map->grid[y][x].x * scale;
			map->grid[y][x].y = map->grid[y][x].y * scale;
			map->grid[y][x].z = map->grid[y][x].z * scale; // adjust to map size
			x++;
		}
		y++;
	}
}
