/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:43:00 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/26 18:48:24 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	fdf_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	char	*dst;
	int		offset;

	offset = (y * img->line_length + x * (img->bits_per_pixel / 8));
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		dst = img->addr + offset;
		*(unsigned int*)dst = color;
	}
}

static void	plotLine(t_bres bres, t_img *img, int start_color, int end_color)
{
	int	e2;

	bres.delta_x =  abs(bres.x1 - bres.x0);
	bres.delta_y = -abs(bres.y1 - bres.y0);
	bres.sign_x = bres.x0 < bres.x1 ? 1 : -1; // change these
	bres.sign_y = bres.y0 < bres.y1 ? 1 : -1; // change these
	bres.err = bres.delta_x + bres.delta_y;
	while (1)
	{
		// fdf_mlx_pixel_put(img, bres.x0, bres.y0, color);
		fdf_mlx_pixel_put(img, bres.x0, bres.y0,
				get_gradient(bres, start_color, end_color));
		if (bres.x0 == bres.x1 && bres.y0 == bres.y1)
			break;
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

static void	paint_img(t_img *img, t_map map)
{
	int		y;
	int		x;
	t_bres	bres;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			bres.x0 = map.grid[y][x].x;
			bres.y0 = map.grid[y][x].y;
			if (x < map.width - 1)
			{
				bres.x1 = map.grid[y][x + 1].x;
				bres.y1 = map.grid[y][x + 1].y;
				// plotLine(bres, img, get_x_color(map, x, y));
				plotLine(bres, img, map.grid[y][x].color, map.grid[y][x + 1].color);
			}
			if (y < map.height - 1)
			{
				bres.x1 = map.grid[y + 1][x].x;
				bres.y1 = map.grid[y + 1][x].y;
				// plotLine(bres, img, get_y_color(map, x, y));
				plotLine(bres, img, map.grid[y][x].color, map.grid[y + 1][x].color);
			}
			x++;
		}
		y++;
	}
}

// void ft_render(t_vars mlx_vars, t_map map)
int	ft_render(void *data)
{
	t_img	*img = ((t_data *)data)->img;
	t_vars	*mlx_vars = ((t_data *)data)->mlx_vars;
	t_map	*map = ((t_data *)data)->map;


	paint_img(img, *map);
	mlx_put_image_to_window(mlx_vars->mlx, mlx_vars->win, img->img, 0, 0);
	return (0);
}
