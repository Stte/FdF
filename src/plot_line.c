/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plotLine.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:00:32 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/04 19:35:54 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_sign(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

static void	fdf_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;
	int		offset;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = img->addr + offset;
		*(unsigned int *)dst = color;
	}
}

void	plot_line(t_bres bres, t_img *img, int start_color, int end_color)
{
	int	e2;

	bres.delta_x = abs(bres.x1 - bres.x0);
	bres.delta_y = -abs(bres.y1 - bres.y0);
	bres.sign_x = get_sign(bres.x0, bres.x1);
	bres.sign_y = get_sign(bres.y0, bres.y1);
	bres.err = bres.delta_x + bres.delta_y;
	while (1)
	{
		fdf_mlx_pixel_put(img, bres.x0, bres.y0,
			get_gradient(bres, start_color, end_color));
		if (bres.x0 == bres.x1 && bres.y0 == bres.y1)
			break ;
		e2 = 2 * bres.err;
		if (e2 >= bres.delta_y && bres.x0 != bres.x1)
		{
			bres.err += bres.delta_y;
			bres.x0 += bres.sign_x;
		}
		if (e2 <= bres.delta_x && bres.y0 != bres.y1)
		{
			bres.err += bres.delta_x;
			bres.y0 += bres.sign_y;
		}
	}
}
