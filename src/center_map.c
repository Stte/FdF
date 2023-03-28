/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:22:34 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/28 14:06:44 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_center(t_map *map, t_bounds *old_bounds)
{
	int			center_x;
	int			center_y;
	int			old_center_x;
	int			old_center_y;
	t_bounds	map_bounds;

	map_bounds = get_map_bounds(map);
	center_x = ft_lerp(map_bounds.x_min, map_bounds.x_max, 0.5);
	center_y = ft_lerp(map_bounds.y_min, map_bounds.y_max, 0.5);
	if (!old_bounds)
		ft_transform(map, WIDTH / 2 - center_x, HEIGHT / 2 - center_y);
	else
	{
		old_center_x = ft_lerp(old_bounds->x_min, old_bounds->x_max, 0.5);
		old_center_y = ft_lerp(old_bounds->y_min, old_bounds->y_max, 0.5);
		ft_transform(map, old_center_x - center_x, old_center_y - center_y);
	}
}
