/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:04:23 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/07 16:09:49 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_rectangular(t_map *map)
{
	int	i;
	int	width;

	i = 0;
	width = (int)ft_strlen(map->grid[0]);
	while (i < map->height)
	{
		if ((int)ft_strlen(map->grid[i]) != width)
		{
			ft_printf("Error: Map is not rectangular\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	check_walls(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->width)
	{
		if (map->grid[0][i] != '1' || map->grid[map->height - 1][i] != '1')
		{
			ft_printf("Error: Map is not surrounded by walls\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < map->height)
	{
		if (map->grid[i][0] != '1' || map->grid[i][map->width - 1] != '1')
		{
			ft_printf("Error: Map is not surrounded by walls\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	count_element(t_map *map, char element)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->grid[i][j] == element)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static int	check_elements(t_map *map)
{
	int	player;
	int	collectibles;
	int	exits;

	player = count_element(map, 'P');
	collectibles = count_element(map, 'C');
	exits = count_element(map, 'E');
	if (player != 1)
	{
		ft_printf("Error: Map must contain exactly one 'P'\n");
		return (0);
	}
	if (collectibles < 1)
	{
		ft_printf("Error: Map must have at least one 'C'\n");
		return (0);
	}
	if (exits < 1)
	{
		ft_printf("Error: Map must contain at least one 'E'\n");
		return (0);
	}
	return (1);
}

int	validate_map(t_map *map)
{
	if (!check_rectangular(map))
		return (0);
	if (!check_walls(map))
		return (0);
	if (!check_elements(map))
		return (0);
	return (1);
}
