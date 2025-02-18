/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 16:54:06 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/18 16:57:29 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_copy(char **copy, int height)
{
	int	y;

	y = 0;
	while (y < height)
	{
		free(copy[y]);
		y++;
	}
	free(copy);
}

char	**copy_map(t_map *map)
{
	char	**copy;
	int		y;

	copy = malloc(sizeof(char *) * (map->height + 1));
	if (!copy)
		return (NULL);
	y = 0;
	while (y < map->height)
	{
		copy[y] = ft_strdup(map->grid[y]);
		if (!copy[y])
		{
			free_map_copy(copy, y);
			return (NULL);
		}
		y++;
	}
	copy[y] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

