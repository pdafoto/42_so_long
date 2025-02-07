/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:39:50 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/07 11:04:08 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

int		handle_key(int key, void *mlx);
int		handle_close(void *mlx);
int		load_map(const char *filename, t_map *map);
void	free_map(t_map *map);
int		validate_map(t_map *map);

#endif
