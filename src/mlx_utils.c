/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:25:31 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/25 16:25:54 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_down(int keycode, t_vars *mlx_vars)
{
	printf("%d\n", keycode); // remove this
	if (keycode == ESC)
	{
		mlx_destroy_window(mlx_vars->mlx, mlx_vars->win);
		exit (0);
	}
	return (0);
}

int	close_window(t_vars *param)
{
	mlx_destroy_window(param->mlx, param->win);
	exit (0);
}
