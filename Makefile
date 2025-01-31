# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 14:59:06 by nperez-d          #+#    #+#              #
#    Updated: 2025/01/31 17:47:09 by nperez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

SRC_DIR		= src/
OBJ_DIR		= objects/
INC			= includes/
MLX_DIR		= minilibx-linux/

SRCS 		= $(SRC_DIR)main.c $(SRC_DIR)events.c
OBJS 		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -I$(INC) -I$(MLX_DIR)
MLX_FLAGS 	= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm

all: 			$(NAME)

$(NAME): 		$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(OBJS)

fclean: 	clean
	rm -f $(NAME)

re: 		fclean all
