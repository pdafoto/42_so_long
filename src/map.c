/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:12 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/07 11:52:25 by nperez-d         ###   ########.fr       */
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
		ft_printf("Error: Couldn't open file\n");
		return (0);
	}
	map->height = 0;
	while ((line = get_next_line(fd)))
	{
		if (width == 0)
			width = ftstrlen(line) - 1;
		map->height++;
		free(line);
	}
	close(fd);
	map->width = width;
	return (map->height > 0);
}

int	load_map(const char *filename, t_map * map)
{
	int	fd;
	int	i;

	if (!get_map_size(filename, map))
		return (0);
	map->grid = malloc(sizeof(char *) * (map->height + 1));
	if (!map->grid)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while (i < map->height)
	{
		map->grid[i] = get_next_line(fd);
		if (!map->grid[i])
		{
			close(fd);
			return (0);
		}
		map->grid[i][map->width] = '\0';
		i++;
	}
	map->grid[i] = NULL;
	close(fd);
	return (1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
		free(map->grid[i++]);
	free(map->grid);
}
