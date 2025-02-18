/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:28:51 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/18 17:38:07 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_map_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\n");
		if (errno == ENOENT)
			ft_printf("No exist map\n");
		else if (errno == EACCES)
			ft_printf("Permission denied\n");
		else
			ft_printf("Couldn't open file: %s\n", strerror(errno));
		return (-1);
	}
	return (0);
}

int	read_map_dimensions(int fd, t_map *map)
{
	char	*line;
	int		width;

	width = 0;
	map->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			ft_printf("Error\n");
			ft_printf("Empty line detected in map\n");
			return (0);
		}
		if (width == 0)
			width = ft_strlen(line) - 1;
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	map->width = width;
	return (1);
}

int	check_map_empty(t_map *map)
{
	if (map->height == 0)
	{
		ft_printf("Error\n");
		ft_printf("Empty map\n");
		return (0);
	}
	return (1);
}
