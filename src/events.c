/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:34:28 by nperez-d          #+#    #+#             */
/*   Updated: 2025/01/31 16:50:03 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Handle ESC key press
int	handle_key(int key, void *mlx)
{
	if (key == XK_Escape)
	{
		mlx_loop_end(mlx);
	}
	return (0);
}

// Handle close window button
int	handle_close(void *mlx)
{
	mlx_loop_end(mlx);
	return (0);
}
