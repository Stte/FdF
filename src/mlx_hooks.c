/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:25:31 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/05 16:17:36 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	add_hooks(t_data *data)
{
	t_vars	*mlx_vars;

	mlx_vars = data->mlx_vars;
	mlx_hook(mlx_vars->win, ON_DESTROY, 0, close_cross, mlx_vars);
	mlx_hook(mlx_vars->win, ON_KEYDOWN, 0, key_hook, data);
}

static void	do_transform(int keycode, t_data *data)
{
	if (keycode == LEFT)
		ft_transform(data->map, -30, 0);
	if (keycode == RIGHT)
		ft_transform(data->map, 30, 0);
	if (keycode == UP)
		ft_transform(data->map, 0, -30);
	if (keycode == DOWN)
		ft_transform(data->map, 0, 30);
}

static void	do_rotate(int keycode, t_data *data)
{
	if (keycode == ROTATE_Q)
		ft_rotate(data, 'z', 0.05);
	if (keycode == ROTATE_E)
		ft_rotate(data, 'z', -0.05);
	if (keycode == ROTATE_UP)
		ft_rotate(data, 'x', 0.05);
	if (keycode == ROTATE_DOWN)
		ft_rotate(data, 'x', -0.05);
	if (keycode == ROTATE_LEFT)
		ft_rotate(data, 'y', -0.05);
	if (keycode == ROTATE_RIGHT)
		ft_rotate(data, 'y', 0.05);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx_vars->mlx, data->mlx_vars->win);
		exit (0);
	}
	if (keycode == LEFT || keycode == RIGHT || keycode == UP || keycode == DOWN)
		do_transform(keycode, data);
	if (keycode == ROTATE_Q || keycode == ROTATE_E || keycode == ROTATE_UP
		|| keycode == ROTATE_DOWN || keycode == ROTATE_LEFT
		|| keycode == ROTATE_RIGHT)
		do_rotate(keycode, data);
	if (keycode == ZOOM_IN)
		ft_zoom(data->map, 1.05);
	if (keycode == ZOOM_OUT)
		ft_zoom(data->map, 0.95);
	if (keycode == TOGGLE_PROJ)
		data->iso = data->iso * -1;
	ft_render(data);
	return (0);
}

int	close_cross(t_vars *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit (0);
}
