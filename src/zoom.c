/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:07:39 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/29 16:52:04 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_map *map, float zoom_amount)
{
	t_bounds	old_bounds;

	old_bounds = get_map_bounds(map);
	ft_scale(map, zoom_amount);
	ft_center(map, &old_bounds);
}
