/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 11:58:20 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/25 13:11:48 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_map *map, float zoom)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			map->map[y][x].x = map->map[y][x].x * zoom;
			map->map[y][x].y = map->map[y][x].y * zoom;
			map->map[y][x].z = map->map[y][x].z * zoom;
			x++;
		}
		y++;
	}
}
