/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:40:50 by nperez-d          #+#    #+#             */
/*   Updated: 2025/02/07 13:15:14 by nperez-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char			*get_next_line(int fd);
char			*gnl_strchr(const char *s, int c);
char			*gnl_strjoin(char *s1, char *s2);
unsigned int	gnl_strlcpy(char *dst, char *src, unsigned int dstsize);
size_t			gnl_strlen(const char *s);

#endif
