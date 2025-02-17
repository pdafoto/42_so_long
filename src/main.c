/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:11:09 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/17 22:37:45 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file_extension(char *filename)
{
	int		len;
	len = ft_strlen(filename);
	if (len < 5 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
	{
		ft_printf("Error\n");
		ft_printf("Bad extension\n");
		return (0);
	}
	return (1);
}

static int	parse_args(int argc)
{
	if (argc != 2)
	{
		ft_printf("Error: ./so_long maps/map*.ber\n");
		return (0);
	}
	return (1);
}

static int	setup_game(t_game *game, char *map_file)
{
	if (!load_map(map_file, &game->map))
		return (0);
	if (!validate_map(game))
	{
		free_map(&game->map);
		return (0);
	}
	if (!init_game(game))
	{
		ft_printf("Error: Couldn't start game.\n");
		free_map(&game->map);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (!parse_args(argc))
		return (1);
	if (!check_file_extension(argv[1]))
		return (1);
	if (!setup_game(&game, argv[1]))
		return (1);
	render_map(&game);
	mlx_hook(game.win, KeyPress, KeyPressMask, handle_key, &game);
	mlx_hook(game.win, DestroyNotify, StructureNotifyMask, handle_close, &game);
	mlx_loop(game.mlx);
	return (0);
}
