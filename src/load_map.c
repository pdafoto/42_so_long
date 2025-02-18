/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:12 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/18 15:42:47 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_size(const char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		width;

	width = 0;
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
		return (0);
	}
	map->height = 0;
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			ft_printf("Error\n");
			ft_printf("Empty line detected in map\n");
			close(fd);
			return (0);
		}
		if (width == 0)
			width = ft_strlen(line) - 1;
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	if (map->height == 0)
	{
		ft_printf("Error\n");
		ft_printf("Empty map\n");
		return (0);
	}
	map->width = width;
	return (1);
}

static int	allocate_map(const char *filename, t_map *map, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		return (0);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
	{
		close(*fd);
		ft_printf("Error: Memory allocation failed.\n");
		return (0);
	}
	return (1);
}

static int	fill_map(t_map *map, int fd)
{
	int	y;

	y = 0;
	while (y < map->height)
	{
		map->grid[y] = get_next_line(fd);
		if (!map->grid[y] || map->grid[y][0] == '\n' || map->grid[y][0] == '\0')
		{
			ft_printf("ERROR: Empty line detected at row %d!\n", y);
			while (--y >= 0)
				free(map->grid[y]);
			free(map->grid);
			close(fd);
			return (0);
		}
		y++;
	}
	map->grid[y] = NULL;
	close(fd);
	return (1);
}

int	load_map(const char *filename, t_map *map)
{
	int	fd;

	if (!get_map_size(filename, map))
		return (0);
	if (!allocate_map(filename, map, &fd))
		return (0);
	if (!fill_map(map, fd))
		return (0);
	return (1);
}

void	free_map(t_map *map)
{
	int	y;

	y = 0;
	while (y < map->height)
		free(map->grid[y++]);
	free(map->grid);
}
