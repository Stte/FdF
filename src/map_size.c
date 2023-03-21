/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tspoof <tspoof@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 18:14:25 by tspoof            #+#    #+#             */
/*   Updated: 2023/03/21 12:47:54 by tspoof           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

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
	return (width);
}

static int	get_height(int fd)
{
	int		height;

	height = 1;
	while (get_next_line(fd))
		height++;
	return (height);
}

void	get_map_size(int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	map->width = get_width(line);
	map->height = get_height(fd);
}
