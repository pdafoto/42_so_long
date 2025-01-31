# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 14:59:06 by nperez-d          #+#    #+#              #
#    Updated: 2025/01/31 16:56:20 by nperez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

SRCS 		= src/main.c src/events.c
OBJS 		= $(SRCS:.c=.o)

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -Iincludes -Iminilibx-linux

MLX_DIR 	= minilibx-linux
MLX_FLAGS 	= -L$(MLX_DIR) -lmlx -lX11 -lXext -lmlx

all: 		$(NAME)

$(NAME): 	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

clean:
			rm -f $(OBJS)

fclean: 	clean
			rm -f $(NAME)

re: 		fclean all
