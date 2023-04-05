/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:14:25 by tspoof            #+#    #+#             */
/*   Updated: 2023/04/05 15:18:05 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_width(char *line)
{
	int		width;
	char	**split_line;

	split_line = ft_split(line, ' ');
	if (!split_line)
		return (0);
	width = 0;
	while (!ft_strchr(split_line[width], '\n'))
		width++;
	if (*split_line[width] != '\n')
		width++;
	free_split(split_line);
	return (width);
}

static int	get_height(int fd)
{
	int		height;
	char	*line;

	height = 1;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		height++;
	}
	free(line);
	return (height);
}

void	get_map_size(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	map->width = get_width(line);
	map->height = get_height(fd);
	free(line);
}
