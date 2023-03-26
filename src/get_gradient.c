/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_gradient.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:14:22 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/26 18:55:42 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//Get distance and lerp each RGB values
int	get_gradient(t_bres bres, int start_color, int end_color)
{
	float	tot_dist;
	float	cur_dist;
	int	r;
	int	g;
	int	b;
	int	result;

	tot_dist = get_distance_delta(bres.delta_x, abs(bres.delta_y));
	cur_dist = get_distance(bres.x0, bres.y0, bres.x1, bres.y1);
	r = ft_lerp(get_r(start_color), get_r(end_color), 1 - cur_dist / tot_dist);
	g = ft_lerp(get_g(start_color), get_g(end_color), 1 - cur_dist / tot_dist);
	b = ft_lerp(get_b(start_color), get_b(end_color), 1 - cur_dist / tot_dist);
	result = create_rgb(r, g, b);
	return (result);
}
