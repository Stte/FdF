/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 16:45:26 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/21 17:25:29 by tspoof           ###   ########.fr       */
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
			// ft_putnbr_fd(map->map[y][x].x, 1);
			// ft_putchar_fd(' ', 1);
			// ft_putnbr_fd(map->map[y][x].y, 1);
			// ft_putchar_fd(' ', 1);
			ft_putnbr_fd(map->map[y][x].z, 1);
			ft_putstr_fd("	", 1);
			x++;
		}
		ft_putchar_fd('\n', 1);
		y++;
	}
	ft_putchar_fd('\n', 1);
	ft_putstr_fd("---------------------\n", 1);
	ft_putchar_fd('\n', 1);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_putnbr_fd(map->map[y][x].color, 1);
			ft_putstr_fd("	", 1);
			x++;
		}
		ft_putchar_fd('\n', 1);
		y++;
	}
}

void	row_add_values(char	**split_line, int width, t_coord *row, int y)
{
	int	x;

	x = 0;
	while (x < width)
	{
		row[x].y = y;
		row[x].x = x;
		row[x].z = ft_atoi(split_line[x]);
		row[x].color = ft_atoi_hex(ft_strchr(split_line[x], 'x'));
		x++;
	}
}

t_coord	*fill_row(int fd, int width, int y)
{
	char	*line;
	char	**split_line;
	t_coord *row;

	row = ft_calloc(width, sizeof(t_coord));
	if (!row)
		return (NULL);
	line = get_next_line(fd);
	split_line = ft_split(line, ' ');
	if (!split_line)
		return (0);
	row_add_values(split_line, width, row, y);
	return (row);
}

void	store_map(int fd, t_map *map)
{
	int	y;

	map->map = ft_calloc(map->height, sizeof(t_coord *));
	if (!map->map)
		return ;
	y = 0;
	while (y < map->height)
	{
		map->map[y] = fill_row(fd, map->width, y);
		y++;
	}
}

void	load_map(char *path, t_map *map)
{
	int		fd;

	fd = open(path, O_RDONLY);
	get_map_size(fd, map);
	close(fd);
	fd = open(path, O_RDONLY);
	store_map(fd, map);
	close(fd);
	debug_print_map(map);
}

void fdf(char *path)
{
	t_map	map;

	load_map(path, &map);
	render(map);
}

int	main(int argc, char *argv[])
{
	if (argc)
		;
	fdf(argv[1]);
	return (0);
}
