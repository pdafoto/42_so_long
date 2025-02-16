/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 22:03:00 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/16 18:52:40 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	find_player_position(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			if (game->map.grid[y][x] == 'P')
			{
				game->player_x = x;
				game->player_y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

static void	*load_image(void *mlx, char *path, int size)
{
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &size, &size);
	if (!img)
		ft_printf("Error: Failed to load texture %s\n", path);
	return (img);
}

static int	load_all_images(t_game *game)
{
	game->img_wall = load_image(game->mlx, "textures/wall.xpm", game->img_size);
	game->img_floor = load_image(game->mlx, "textures/floor.xpm", \
		game->img_size);
	game->img_player = load_image(game->mlx, "textures/player.xpm", \
		game->img_size);
	game->img_collectible = load_image(game->mlx, "textures/collectible.xpm", \
		game->img_size);
	game->img_exit = load_image(game->mlx, "textures/exit.xpm", game->img_size);
	if (!game->img_wall || !game->img_floor || !game->img_player || \
		!game->img_collectible || !game->img_exit)
	{
		free_game(game);
		return (0);
	}
	return (1);
}

int	init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->moves = 0;
	find_player_position(game);
	game->img_wall = NULL;
	game->img_floor = NULL;
	game->img_player = NULL;
	game->img_collectible = NULL;
	game->img_exit = NULL;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->img_size = 32;
	game->win = mlx_new_window(game->mlx, game->map.width * game->img_size, \
		game->map.height * game->img_size, "so_long");
	if (!game->win || !load_all_images(game))
	{
		free_game(game);
		return (0);
	}
	return (1);
}
