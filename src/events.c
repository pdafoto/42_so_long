/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:34:28 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/16 20:57:31 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == '1')
		return (0);
	if (game->map.grid[y][x] == 'E' && game->collectibles_left > 0)
	{
		ft_printf("You must collect all items before exiting!\n");
		return (0);
	}
	return (1);
}

static void	handle_collectible(t_game *game, int x, int y)
{
	if (game->map.grid[y][x] == 'C')
	{
		game->map.grid[y][x] = '0';
		game->collectibles_left--;
	}
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	if (!can_move(game, new_x, new_y))
		return ;
	handle_collectible(game, new_x, new_y);
	if (game->map.grid[new_y][new_x] == 'E' && game->collectibles_left == 0)
	{
		ft_printf("Congratulations!\n");
		ft_printf("You've completed the game in %d moves.\n", game->moves);
		mlx_loop_end(game->mlx);
		return ;
	}
	game->map.grid[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map.grid[new_y][new_x] = 'P';
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
	render_map(game);
}

int	handle_key(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		mlx_loop_end(game->mlx);
		free_game(game);
		exit(0);
	}
	else if (key == XK_w || key == XK_Up)
		move_player(game, game->player_x, game->player_y - 1);
	else if (key == XK_s || key == XK_Down)
		move_player(game, game->player_x, game->player_y + 1);
	else if (key == XK_a || key == XK_Left)
		move_player(game, game->player_x - 1, game->player_y);
	else if (key == XK_d || key == XK_Right)
		move_player(game, game->player_x + 1, game->player_y);
	return (0);
}

int	handle_close(t_game *game)
{
	mlx_loop_end(game->mlx);
	free_game(game);
	exit(0);
	return (0);
}
