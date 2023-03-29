/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:25:31 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/29 16:53:19 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_vars->mlx, data->mlx_vars->win);
		exit (0);
	}
	if (keycode == LEFT)
		ft_transform(data->map_proj, -30, 0);
	if (keycode == RIGHT)
		ft_transform(data->map_proj, 30, 0);
	if (keycode == UP)
		ft_transform(data->map_proj, 0, -30);
	if (keycode == DOWN)
		ft_transform(data->map_proj, 0, 30);
	if (keycode == ZOOM_IN)
		ft_zoom(data->map_proj, 1.05);
	if (keycode == ZOOM_OUT)
		ft_zoom(data->map_proj, 0.95);
	ft_render(data);
	return (0);
}

int	close_cross(t_vars *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit (0);
}
