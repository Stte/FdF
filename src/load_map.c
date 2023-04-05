/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:39:56 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/05 19:02:49 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

static void	row_add_values(char	**split_line, int width, t_point *row, int y)
{
	int	x;

	x = 0;
	while (x < width)
	{
		row[x].y = y;
		row[x].x = x;
		row[x].z = ft_atoi(split_line[x]) / 2.0;
		row[x].color = ft_atoi_hex(ft_strchr(split_line[x], 'x'));
		if (row[x].color == 0)
			row[x].color = 0xFFFFE0;
		x++;
	}
}

static t_point	*fill_row(int fd, int width, int y)
{
	char	*line;
	char	**split_line;
	t_point	*row;

	row = ft_calloc(width, sizeof(t_point));
	if (!row)
		return (NULL);
	line = get_next_line(fd);
	if (!line)
		exit (0);
	split_line = ft_split(line, ' ');
	if (!split_line)
		exit (0);
	row_add_values(split_line, width, row, y);
	free_split(split_line);
	free(line);
	return (row);
}

static void	store_map(int fd, t_map *map)
{
	int	y;

	map->grid = ft_calloc(map->height, sizeof(t_point *));
	if (!map->grid)
		exit (0);
	if (!map->grid)
		return ;
	y = 0;
	while (y < map->height)
	{
		map->grid[y] = fill_row(fd, map->width, y);
		if (!map->grid[y])
			exit(0);
		y++;
	}
}

int	load_map(char *path, t_map *map)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	get_map_size(fd, map);
	close(fd);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	store_map(fd, map);
	close(fd);
	return (1);
}
