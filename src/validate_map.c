/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:04:23 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/18 15:42:24 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_map_copy(char **copy, int height)
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

static char	**copy_map(t_map *map)
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

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

static int	can_collect_all(t_map *map, int px, int py)
{
	char	**copy;
	int		x;
	int		y;

	copy = copy_map(map);
	if (!copy)
		return (0);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
			if (copy[y][x] == 'E')
				copy[y][x] = '1';
	}
	flood_fill(copy, px, py);
	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			if (map->grid[y][x] == 'C' && copy[y][x] != 'X')
			{
				free_map_copy(copy, map->height);
				return (0);
			}
		}
	}
	free_map_copy(copy, map->height);
	return (1);
}

static int	can_reach_exit(t_map *map, int px, int py)
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

int	validate_map(t_game *game)
{
	if (!check_rectangular(&game->map)
		|| !check_walls(&game->map)
		|| !check_valid_chars(&game->map)
		|| !check_elements(&game->map))
		return (0);
	find_player_position(game);
	if (!can_collect_all(&game->map, game->player_x, game->player_y)
		|| !can_reach_exit(&game->map, game->player_x, game->player_y))
	{
		ft_printf("Error\n");
		ft_printf("No valid path\n");
		return (0);
	}
	return (1);
}
