/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 15:11:09 by nperez-d          #+#    #+#             */
/*   Updated: 2025/01/31 16:49:34 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "so_long");

	mlx_hook(win, KeyPress, KeyPressMask, handle_key, mlx);
	mlx_hook(win, DestroyNotify, StructureNotifyMask, handle_close, mlx);
	mlx_loop(mlx);
	mlx_destroy_window(mlx, win);
	free(mlx);
	return (0);
}
