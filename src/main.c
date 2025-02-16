/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:11:09 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/16 20:03:25 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_printf("Usage: ./so_long maps/mapa.ber\n");
		return (1);
	}
	if (!load_map(argv[1], &game.map))
	{
		ft_printf("Error: Couldn't load map\n");
		return (1);
	}
	if (!validate_map(&game))
	{
		free_map(&game.map);
		return (1);
	}
	if (!init_game(&game))
	{
		ft_printf("Error: Couldn't start game");
		free_map(&game.map);
		return (1);
	}
	render_map(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, handle_key, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
