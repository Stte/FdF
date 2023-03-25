/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:26:10 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/25 17:38:11 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	do_transform(void *dst, void *params, t_map *map, t_xy xy)
{
	t_xy	*transforms;

	(void)dst;
	transforms = (t_xy *)params;
	map->map[xy.y][xy.x].x = map->map[xy.y][xy.x].x + transforms->x;
	map->map[xy.y][xy.x].y = map->map[xy.y][xy.x].y + transforms->y;
}

void	ft_transform(t_map *map, int transform_x, int transform_y)
{
	t_xy	transforms;

	transforms.x = transform_x;
	transforms.y = transform_y;
	loop_map(NULL, &transforms, map, do_transform);
}
