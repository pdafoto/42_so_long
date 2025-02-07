/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:55:28 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/07 21:19:36 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	if (!game->win)
	{
		free_game(game);
		return (0);
	}
	if (!load_all_images(game))
	{
		free_game(game);
		return (0);
	}
	return (1);
}

static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, \
		x * game->img_size, y * game->img_size);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.height)
	{
		x = 0;
		while (x < game->map.width)
		{
			put_image(game, game->img_floor, x, y);
			if (game->map.grid[y][x] == '1')
				put_image(game, game->img_wall, x, y);
			else if (game->map.grid[y][x] == 'P')
				put_image(game, game->img_player, x, y);
			else if (game->map.grid[y][x] == 'C')
				put_image(game, game->img_collectible, x, y);
			else if (game->map.grid[y][x] == 'E')
				put_image(game, game->img_exit, x, y);
			x++;
		}
		y++;
	}
	return (1);
}

void	free_game(t_game *game)
{
	if (!game->mlx)
		return ;
	if (game->img_wall)
		mlx_destroy_image(game->mlx, game->img_wall);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player)
		mlx_destroy_image(game->mlx, game->img_player);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	game->mlx = NULL;
}
