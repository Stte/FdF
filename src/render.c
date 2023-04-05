/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 13:43:00 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/05 19:01:38 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	do_paint_img(void *dst, void *params, t_map *map, t_xy xy)
{
	t_bres	bres;
	t_img	*img;

	(void)dst;
	img = (t_img *)params;
	bres.x0 = map->grid[xy.y][xy.x].x;
	bres.y0 = map->grid[xy.y][xy.x].y;
	if (xy.x < map->width - 1)
	{
		bres.x1 = map->grid[xy.y][xy.x + 1].x;
		bres.y1 = map->grid[xy.y][xy.x + 1].y;
		plot_line(bres, img, map->grid[xy.y][xy.x].color,
			map->grid[xy.y][xy.x + 1].color);
	}
	if (xy.y < map->height - 1)
	{
		bres.x1 = map->grid[xy.y + 1][xy.x].x;
		bres.y1 = map->grid[xy.y + 1][xy.x].y;
		plot_line(bres, img, map->grid[xy.y][xy.x].color,
			map->grid[xy.y + 1][xy.x].color);
	}
}

static void	paint_img(t_img *img, t_map map)
{
	loop_map(NULL, img, &map, do_paint_img);
}

static void	copy_grid(t_map *dst, t_map *src)
{
	int	y;

	y = 0;
	while (y < dst->height)
	{
		ft_memcpy(dst->grid[y], src->grid[y], sizeof(t_point) * dst->width);
		y++;
	}
}

int	ft_render(t_data *data)
{
	t_img	*img;
	t_vars	*mlx_vars;
	int		width;
	int		height;

	img = data->img;
	mlx_vars = data->mlx_vars;
	width = data->map->width;
	height = data->map->height;
	mlx_destroy_image(mlx_vars->mlx, img->img);
	initialize_image(data);
	if (data->iso > 0)
		ft_projection(data->map, data->map_proj, data->rads);
	else
		copy_grid(data->map_proj, data->map);
	paint_img(img, *data->map_proj);
	mlx_put_image_to_window(mlx_vars->mlx, mlx_vars->win, img->img, 0, 0);
	mlx_string_put(mlx_vars->mlx, mlx_vars->win, 15, 10, 0xFFFFFF,
		"Transform: WASD");
	mlx_string_put(mlx_vars->mlx, mlx_vars->win, 15, 30, 0xFFFFFF,
		"Rotate: UIO JKL");
	mlx_string_put(mlx_vars->mlx, mlx_vars->win, 15, 50, 0xFFFFFF, "Zoom: -=");
	mlx_string_put(mlx_vars->mlx, mlx_vars->win, 15, 70, 0xFFFFFF,
		"Projection: P");
	return (0);
}
