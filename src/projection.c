/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:54:15 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/22 19:29:32 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	projection(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->map[y][x].x = (map->map[y][x].x - map->map[y][x].y) * 0.86;
			map->map[y][x].y = map->map[y][x].y;
			x++;
		}
		y++;
	}
}


x = 5
y = 6

x - y = -1 * 0.86 =
