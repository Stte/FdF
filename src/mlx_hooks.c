/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:25:31 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/26 18:13:05 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// int	close_esc(int keycode, t_vars *mlx_vars)
int	key_hook(int keycode, t_data *data)
{
	t_vars	*mlx_vars;

	mlx_vars = data->mlx_vars;
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx_vars->mlx, mlx_vars->win);
		exit (0);
	}
	return (0);
}

int	test_hook(int keycode, t_data *data)
{
	if (keycode == LEFT)
		ft_transform(data->map, -30, 0);
	if (keycode == RIGHT)
		ft_transform(data->map, 30, 0);
	if (keycode == UP)
		ft_transform(data->map, 0, -30);
	if (keycode == DOWN)
		ft_transform(data->map, 0, 30);
	if (keycode == ZOOM_IN)
	{
		ft_scale(data->map, 1.02);
		center_map(data->map);
	}
	if (keycode == ZOOM_OUT)
	{
		ft_scale(data->map, 0.98);
		center_map(data->map);
	}
	return (0);
}
// int	mouse_hook(int mousecode, t_data *data)
// {

// 	printf("%d\n", mousecode); // remove this
// 	if (mousecode == 4)
// 		ft_transform(data->map, 10, 10);
// 	return (0);
// }

int	close_cross(t_vars *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit (0);
}

// int	key_hook(int keycode, t_map *map)
// int	key_hook(int keycode, t_data *data)
// {
// 	(void) data;
// 	printf("%d\n", keycode); // remove this
// 	return (0);
// }
