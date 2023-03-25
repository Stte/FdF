/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:43:00 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/25 14:52:53 by tspoof           ###   ########.fr       */
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

int	get_distance(int x0, int y0, int x1, int y1)
{
	return (sqrt(pow(y1 - y0, 2) + pow(x1 - x0, 2)));
}

int	get_distance_delta(int delta_x, int delta_y)
{
	return (sqrt(pow(delta_y, 2) + pow(delta_x, 2)));
}

float	ft_lerp(float a, float b, float fraction)
{
	return (a * (1.0 - fraction) + (b * fraction));
}
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

// static int	get_x_color(t_map map, int x, int y)
// {
// 	if (map.map[y][x].color == map.map[y][x + 1].color)
// 		return (map.map[y][x].color);
// 	return (0xFFFFE0);
// }
// static int	get_y_color(t_map map, int x, int y)
// {
// 	if (map.map[y][x].color == map.map[y + 1][x].color)
// 		return (map.map[y][x].color);
// 	return (0xFFFFE0);
// }

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
				// plotLine(bres, img, get_x_color(map, x, y));
				plotLine(bres, img, map.map[y][x].color, map.map[y][x + 1].color);
			}
			if (y < map.height - 1)
			{
				bres.x1 = map.map[y + 1][x].x;
				bres.y1 = map.map[y + 1][x].y;
				// plotLine(bres, img, get_y_color(map, x, y));
				plotLine(bres, img, map.map[y][x].color, map.map[y + 1][x].color);
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
