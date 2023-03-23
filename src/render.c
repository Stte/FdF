/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:43:00 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/23 17:53:59 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_down(int keycode, t_vars *mlx_vars)
{
	printf("%d\n", keycode); // remove this
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx_vars->mlx, mlx_vars->win);
		exit (0);
	}
	return (0);
}

static int close_window(t_vars *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit (0);
}

static void	fdf_mlx_pixel_put(t_img *img, int x, int y, int color)
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

static void	plotLine(t_bres bres, t_img *img, int color)
{
	bres.delta_x =  abs(bres.x1 - bres.x0);
	bres.delta_y = -abs(bres.y1 - bres.y0);
	bres.sign_x = bres.x0 < bres.x1 ? 1 : -1; // change these
	bres.sign_y = bres.y0 < bres.y1 ? 1 : -1; // change these
	bres.err = bres.delta_x + bres.delta_y;
	while (1)
	{
		fdf_mlx_pixel_put(img, bres.x0, bres.y0, color);
		if (bres.x0 == bres.x1 && bres.y0 == bres.y1)
			break;
		if (2 * bres.err >= bres.delta_y && bres.x0 != bres.x1)
		{
			bres.err += bres.delta_y;
			bres.x0 += bres.sign_x;
		}
		if (2 * bres.err <= bres.delta_x && bres.y0 != bres.y1)
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
			bres.x0 = map.map[y][x].x;
			bres.y0 = map.map[y][x].y;
			if (x < map.width - 1)
			{
				bres.x1 = map.map[y][x + 1].x;
				bres.y1 = map.map[y][x + 1].y;
				plotLine(bres, img, map.map[y][x].color);
			}
			if (y < map.height - 1)
			{
				bres.x1 = map.map[y + 1][x].x;
				bres.y1 = map.map[y + 1][x].y;
				plotLine(bres, img, map.map[y][x].color);
			}
			x++;
		}
		y++;
	}
}

void ft_render(t_vars mlx_vars, t_map map)
{
	// t_vars	mlx_vars;
	t_img	img;

	img.img = mlx_new_image(mlx_vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// fdf_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	paint_img(&img, map);
	mlx_put_image_to_window(mlx_vars.mlx, mlx_vars.win, img.img, 0, 0);

	mlx_key_hook(mlx_vars.win, key_down, &mlx_vars); // ESC click
	mlx_hook(mlx_vars.win, ON_DESTROY, 0L, close_window, &mlx_vars); // Cross click
	mlx_loop(mlx_vars.mlx);
}
