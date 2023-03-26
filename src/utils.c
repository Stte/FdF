/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:04:47 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/26 17:08:10 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	alphatoint(char c)
{
	if (ft_isalpha(c))
		return (ft_toupper(c) - 55);
	if (ft_isdigit(c))
		return (c - '0');
	return (-1);
}

int	ft_atoi_hex(const char *str)
{
	int				i;
	int				sign;
	unsigned long	val;

	sign = 1;
	val = 0;
	i = 0;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == 'x')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (alphatoint(str[i]) >= 0 && str[i] != '\n')
	{
		val = val * 16 + alphatoint(str[i]);
		if (sign == 1 && val > 9223372036854775807)
			return (-1);
		if (sign == -1 && val > 9223372036854775807)
			return (0);
		i++;
	}
	return ((int)(sign * val));
}

void	loop_map(void *dst, void *params, t_map *map,
			void (*f)(void *, void *, t_map *, t_xy))
{
	t_xy	xy;

	xy.y = 0;
	while (xy.y < map->height)
	{
		xy.x = 0;
		while (xy.x < map->width)
		{
			f(dst, params, map, xy);
			xy.x++;
		}
		xy.y++;
	}
}

float	ft_lerp(float a, float b, float fraction)
{
	return (a * (1.0 - fraction) + (b * fraction));
}

void	free_split(char **split)
{
	char	**indirect;

	indirect = split;
	while (*indirect)
	{
		free (*indirect);
		indirect++;
	}
	free (split);
}
