/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:43:00 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/21 17:28:28 by tspoof           ###   ########.fr       */
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

static void	fdf_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset = (y * data->line_length + x * (data->bits_per_pixel / 8));

	dst = data->addr + offset;
	*(unsigned int*)dst = color;
}

static void	paint_img(t_data *img, t_map map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			// fdf_mlx_pixel_put(img, x, y, map.map[y][x].color);
			fdf_mlx_pixel_put(img, map.map[y][x].x * 20 + 10, map.map[y][x].y * 20 + 10, 0x00FF0000);

			x++;
		}
		y++;
	}
}

void render(t_map map)
{
	t_vars	mlx_vars;
	t_data	img;

	mlx_vars.mlx = mlx_init();
	mlx_vars.win = mlx_new_window(mlx_vars.mlx, 500, 500, "Hello World");
	img.img = mlx_new_image(mlx_vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// fdf_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	paint_img(&img, map);
	mlx_put_image_to_window(mlx_vars.mlx, mlx_vars.win, img.img, 0, 0);

	mlx_key_hook(mlx_vars.win, key_down, &mlx_vars); // ESC click
	mlx_hook(mlx_vars.win, ON_DESTROY, 0L, close_window, &mlx_vars); // Cross click
	mlx_loop(mlx_vars.mlx);
}
