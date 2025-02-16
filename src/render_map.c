/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:55:28 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/16 21:26:18 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, \
		x * game->img_size, y * game->img_size);
}

static void	put_tile(t_game *game, char tile, int x, int y)
{
	void	*img;

	img = NULL;
	if (tile == '1')
		img = game->img_wall;
	else if (tile == 'P')
		img = game->img_player;
	else if (tile == 'C')
		img = game->img_collectible;
	else if (tile == 'E')
		img = game->img_exit;
	put_image(game, game->img_floor, x, y);
	if (img)
		put_image(game, img, x, y);
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
			put_tile(game, game->map.grid[y][x], x, y);
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
