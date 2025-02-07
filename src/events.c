/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:34:28 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/07 21:05:30 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Handle ESC key press
int	handle_key(int key, t_game *game)
{
	if (key == XK_Escape)
	{
		mlx_loop_end(game->mlx);
		free_game(game);
		exit(0);
	}
	return (0);
}

// Handle close window button
int	handle_close(t_game *game)
{
	mlx_loop_end(game->mlx);
	free_game(game);
	exit(0);
	return (0);
}
