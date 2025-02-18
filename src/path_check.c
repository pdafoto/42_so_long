/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:01:25 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/18 19:41:22 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	replace_exits_with_walls(char **mapcpy, int height, int width)
{
	int	y;
	int	x;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			if (mapcpy[y][x] == 'E')
				mapcpy[y][x] = '1';
			x++;
		}
		y++;
	}
}

static int	check_all_collectibles(t_map *orig, char **copy)
{
	int	x;
	int	y;

	y = 0;
	while (y < orig->height)
	{
		x = 0;
		while (x < orig->width)
		{
			if (orig->grid[y][x] == 'C' && copy[y][x] != 'X')
				return (0);
			x++;
		}
		y ++;
	}
	return (1);
}

int	can_collect_all(t_map *map, int px, int py)
{
	char	**copy;

	copy = copy_map(map);
	if (!copy)
		return (0);
	replace_exits_with_walls(copy, map->height, map->width);
	flood_fill(copy, px, py);
	if (!check_all_collectibles(map, copy))
	{
		free_map_copy(copy, map->height);
		return (0);
	}
	free_map_copy(copy, map->height);
	return (1);
}

int	can_reach_exit(t_map *map, int px, int py)
{
	char	**copy;
	int		x;
	int		y;
	int		found_exit;

	copy = copy_map(map);
	if (!copy)
		return (0);
	flood_fill(copy, px, py);
	found_exit = 0;
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			if (map->grid[y][x] == 'E' && copy[y][x] == 'X')
				found_exit = 1;
	}
	free_map_copy(copy, map->height);
	return (found_exit);
}

