/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:22:34 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/23 19:50:04 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	center_map(t_map *map)
{
	int	center_x;
	int	center_y;
	t_bounds	map_bounds;

	map_bounds = get_map_bounds(map);
	center_x = (map_bounds.x_max + map_bounds.x_min) / 2;
	center_y = (map_bounds.y_max + map_bounds.y_min) / 2;
	ft_transform(map, WIDTH / 2 - center_x, HEIGHT / 2 - center_y);
}
