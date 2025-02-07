# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 14:59:06 by nperez-d          #+#    #+#              #
#    Updated: 2025/02/07 10:53:46 by nperez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= so_long

# Folders
SRC_DIR		= src/
OBJ_DIR		= objects/
INC			= includes/
MLX_DIR		= minilibx-linux/
LIBFT_DIR	= libft/libft/

#Source files
SRCS 		= $(SRC_DIR)main.c $(SRC_DIR)events.c
OBJS 		= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Compiler flags
CC 			= gcc
CFLAGS 		= -Wall -Wextra -Werror -I$(INC) -I$(MLX_DIR) -I$(LIBFT_DIR)

# MiniLibx $ libft
MLX_FLAGS 	= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
LIBFT		= $(LIBFT_DIR)libft.a
LIBFT_FLAGS	= -L$(LIBFT_DIR) -lft

# Main rule
all: 			$(NAME)

# Compile libft if it doesn't exist
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compile executable
$(NAME): 		$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -o $(NAME)

# Compile object files
$(OBJ_DIR)%.o:	$(SRC_DIR)%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create object folder if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Clean object files
clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

# Clean everything
fclean: 	clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

# Re-compile from scratch
re: 		fclean all

.PHONY:		all clean fclean re
