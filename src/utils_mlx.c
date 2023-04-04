/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:27:14 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/04 20:17:46 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize_image(t_data *data)
{
	t_img	*img;

	img = data->img;
	img->img = mlx_new_image(data->mlx_vars->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
}

void	create_window(t_vars *mlx_vars)
{
	mlx_vars->mlx = mlx_init();
	mlx_vars->win = mlx_new_window(mlx_vars->mlx, WIDTH, HEIGHT, "FdF");
}
