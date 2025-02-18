/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_elements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:18:32 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/18 17:55:03 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_element(t_map *map, char element)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] == element)
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

static int	check_player_count(int players)
{
	if (players == 0)
	{
		ft_printf("Error\n");
		ft_printf("No player\n");
		return (0);
	}
	if (players > 1)
	{
		ft_printf("Error\n");
		ft_printf("Duplicate player\n");
		return (0);
	}
	return (1);
}

static int	check_collectible_count(int collectibles)
{
	if (collectibles < 1)
	{
		ft_printf("Error\n");
		ft_printf("No object\n");
		return (0);
	}
	return (1);
}

static int	check_exit_count(int exits)
{
	if (exits == 0)
	{
		ft_printf("Error\n");
		ft_printf("No exit\n");
		return (0);
	}
	if (exits > 1)
	{
		ft_printf("Error\n");
		ft_printf("Duplicate exit\n");
		return (0);
	}
	return (1);
}

int	check_elements(t_map *map)
{
	int	players;
	int	collectibles;
	int	exits;

	players = count_element(map, 'P');
	collectibles = count_element(map, 'C');
	exits = count_element(map, 'E');
	if (!check_player_count(players))
		return (0);
	if (!check_collectible_count(collectibles))
		return (0);
	if (!check_exit_count(exits))
		return (0);
	return (1);
}
