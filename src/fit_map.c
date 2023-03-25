/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:17:18 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/25 17:45:24 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static int	get_len(int n_min, int n_max)
{
	if (n_min < 0 && n_max < 0)
		return (abs(n_min) - abs(n_max));
	if (n_min < 0)
		return (abs(n_min) + n_max);
	return (n_max - n_min);
}

void	fit_map(t_map *map)
{
	t_bounds	map_bounds;
	int			map_width;
	int			map_height;

	map_bounds = get_map_bounds(map);
	map_width = get_len(map_bounds.x_min, map_bounds.x_max);
	map_height = get_len(map_bounds.y_min, map_bounds.y_max);
	if ((float)HEIGHT / (float)map_height > (float)WIDTH / (float)map_width)
		ft_zoom(map, (float)WIDTH / (float)map_width);
	else
		ft_zoom(map, (float)HEIGHT / (float)map_height);
}
