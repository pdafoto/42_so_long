/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:11:09 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/07 12:00:33 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	map;
	int		i;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long maps/mapa.ber\n");
		return (1);
	}
	if (!load_map(argv[1], &map))
	{
		ft_printf("Error: Couldn't load map\n");
		return (1);
	}
	i = 0;
	while (i < map.height)
	{
		ft_printf("%s\n", map.grid[i]);
		i++;
	}
	free_map(&map);
	return (0);
}
