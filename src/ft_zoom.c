/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zoom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:07:39 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/28 14:09:50 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(t_data *data, float zoom_amount)
{
	t_bounds	old_bounds;

	old_bounds = get_map_bounds(data->map);
	ft_scale(data->map, zoom_amount);
	ft_center(data->map, &old_bounds);
}
