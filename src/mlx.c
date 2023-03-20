/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:43:00 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/20 14:37:17 by tspoof           ###   ########.fr       */
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

static void	paint_img(t_data *img)
{
	for (int i = 5; i < 55; i++)
	{
		fdf_mlx_pixel_put(img, i, i, 0x00FF0000);
	}
}

void render(void)
{
	t_vars	mlx_vars;
	t_data	img;

	mlx_vars.mlx = mlx_init();
	mlx_vars.win = mlx_new_window(mlx_vars.mlx, 500, 500, "Hello World");
	img.img = mlx_new_image(mlx_vars.mlx, 500, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	// fdf_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	paint_img(&img);
	mlx_put_image_to_window(mlx_vars.mlx, mlx_vars.win, img.img, 0, 0);

	mlx_key_hook(mlx_vars.win, key_down, &mlx_vars); // ESC click
	mlx_hook(mlx_vars.win, ON_DESTROY, 0L, close_window, &mlx_vars); // Cross click
	mlx_loop(mlx_vars.mlx);
}
