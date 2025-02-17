/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 16:39:50 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/17 22:28:41 by nperez-d         ###   ########.fr       */
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
# include <errno.h>
# include <string.h>
# include "libft.h"
# include "includes/ft_printf.h"
# include "get_next_line.h"

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;
typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img_wall;
	void	*img_floor;
	void	*img_player;
	void	*img_collectible;
	void	*img_exit;
	int		img_size;
	t_map	map;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles_left;
}	t_game;

int		handle_key(int key, t_game *game);
int		handle_close(t_game *game);
int		load_map(const char *filename, t_map *map);
void	free_map(t_map *map);
int		validate_map(t_game *game);
int		check_valid_chars(t_map *map);
int		check_rectangular(t_map *map);
int		check_walls(t_map *map);
int		check_elements(t_map *map);
int		render_map(t_game *game);
int		init_game(t_game *game);
void	free_game(t_game *game);
void	find_player_position(t_game *game);

#endif
