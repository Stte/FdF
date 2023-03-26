/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 13:12:19 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/26 13:12:37 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_distance(int x0, int y0, int x1, int y1)
{
	return (sqrt(pow(y1 - y0, 2) + pow(x1 - x0, 2)));
}

int	get_distance_delta(int delta_x, int delta_y)
{
	return (sqrt(pow(delta_y, 2) + pow(delta_x, 2)));
}
