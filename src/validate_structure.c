/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_structure.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:18:45 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/17 23:25:41 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_valid_chars(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->grid[y][x] != '0' && map->grid[y][x] != '1' &&
				map->grid[y][x] != 'P' && map->grid[y][x] != 'C' &&
				map->grid[y][x] != 'E')
			{
				ft_printf("Error\n");
				ft_printf("Wrong characters\n");
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_rectangular(t_map *map)
{
	int	y;
	int	width;
	int	len;

	y = 0;
	width = ft_strlen(map->grid[0]);
	if (map->grid[0][width - 1] == '\n')
		width--;
	while (y < map->height)
	{
		len = ft_strlen(map->grid[y]);
		if (map->grid[y][len - 1] == '\n')
			len--;
		if (len != width)
		{
			ft_printf("Error\n");
			ft_printf("No rectangular\n");
			return (0);
		}
		y++;
	}
	return (1);
}

int	check_walls(t_map *map)
{
	int	x;

	x = 0;
	while (x < map->width)
	{
		if (map->grid[0][x] != '1' || map->grid[map->height - 1][x] != '1')
		{
			ft_printf("Error\n");
			ft_printf("Not surrounded by walls\n");
			return (0);
		}
		x++;
	}
	x = 0;
	while (x < map->height)
	{
		if (map->grid[x][0] != '1' || map->grid[x][map->width - 1] != '1')
		{
			ft_printf("Error\n");
			ft_printf("Not surrounded by walls\n");
			return (0);
		}
		x++;
	}
	return (1);
}

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

int	check_elements(t_map *map)
{
	int	player;
	int	collectibles;
	int	exits;

	player = count_element(map, 'P');
	collectibles = count_element(map, 'C');
	exits = count_element(map, 'E');
	if (player == 0)
	{
		ft_printf("Error\n");
		ft_printf("No player\n");
		return (0);
	}
	if (player > 1)
	{
		ft_printf("Error\n");
		ft_printf("Duplicate player\n");
		return (0);
	}
	if (collectibles < 1)
	{
		ft_printf("Error\n");
		ft_printf("No object\n");
		return (0);
	}
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
