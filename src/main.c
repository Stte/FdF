/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/20 19:03:35 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h> // for open

#include <stdio.h> // remove this

void	debug_print_map(t_map *map) // remove this function
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_putnbr_fd(map->map[y][x], 1);
			ft_putstr_fd("	", 1);
			x++;
		}
		ft_putchar_fd('\n', 1);
		y++;
	}
}

int	*fill_row(int fd, int width)
{
	char	*line;
	char	**split_line;
	int		*row;
	int		i;

	row = malloc(sizeof(int) * width);
	if (!row)
		return (NULL);
	line = get_next_line(fd);
	split_line = ft_split(line, ' ');
	if (!split_line)
	{
		// free(row);
		return (0);
	}
	i = 0;
	while (i < width)
	{
		row[i] = ft_atoi(split_line[i]);
		i++;
	}
	return (row);
}

void	store_map(int fd, t_map *map)
{
	int	i;

	map->map = malloc(sizeof(int *) * map->height);
	if (!map->map)
		return ;
	i = 0;
	while (i < map->height)
	{
		map->map[i] = fill_row(fd, map->width);
		i++;
	}
}

void	load_map(char *str)
{
	int		fd;
	t_map	map;

	fd = open(str, O_RDONLY);
	get_map_size(fd, &map);
	close(fd);
	fd = open(str, O_RDONLY);
	store_map(fd, &map);
	close(fd);
	debug_print_map(&map);
}

int	main(int argc, char *argv[])
{
	if (argc)
		;
	// render();
	load_map(argv[1]);
	return (0);
}
