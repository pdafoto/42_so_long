/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:04:23 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/18 17:03:08 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game *game)
{
	if (!check_rectangular(&game->map)
		|| !check_walls(&game->map)
		|| !check_valid_chars(&game->map)
		|| !check_elements(&game->map))
		return (0);
	find_player_position(game);
	if (!can_collect_all(&game->map, game->player_x, game->player_y)
		|| !can_reach_exit(&game->map, game->player_x, game->player_y))
	{
		ft_printf("Error\n");
		ft_printf("No valid path\n");
		return (0);
	}
	return (1);
}
