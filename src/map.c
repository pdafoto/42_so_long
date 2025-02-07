/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:02:12 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/07 11:15:23 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_size(const char *filename, t_map *map)
{
	int		fd;
	char	*line;
	int		width;

	width = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		printf("Error: Couldn't open file\n");
		
	}
}
