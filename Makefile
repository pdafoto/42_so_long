# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/31 14:59:06 by nperez-d          #+#    #+#              #
#    Updated: 2025/02/20 19:02:40 by nperez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Project name
NAME 		= so_long

# Folders
SRC_DIR		= src/
OBJ_DIR		= objects/
INC			= includes/
MLX_DIR		= .minilibx-linux/
LIBFT_DIR	= libft/
PRINTF_DIR	= ft_printf/

#Source files
SRCS 	= $(SRC_DIR)main.c $(SRC_DIR)events.c $(SRC_DIR)init_game.c \
			$(SRC_DIR)load_map.c $(SRC_DIR)map_size_utils.c \
			$(SRC_DIR)flood_fill_utils.c $(SRC_DIR)path_check.c\
			$(SRC_DIR)validate_map.c $(SRC_DIR)validate_structure.c \
			$(SRC_DIR)validate_elements.c $(SRC_DIR)render_map.c \
			$(SRC_DIR)get_next_line.c $(SRC_DIR)get_next_line_utils.c
OBJS 	= $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Compiler flags
CC 		= gcc
CFLAGS 	= -Wall -Wextra -Werror -I$(INC) -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# MiniLibx, libft & ft_printf
MLX				= $(MLX_DIR)libmlx_linux.a
MLX_FLAGS 		= -L$(MLX_DIR) -lmlx -lX11 -lXext -lm
LIBFT			= $(LIBFT_DIR)libft.a
LIBFT_FLAGS		= -L$(LIBFT_DIR) -lft
PRINTF			= $(PRINTF_DIR)libftprintf.a
PRINTF_FLAGS	= -L$(PRINTF_DIR) -lftprintf

# Main rule
all:	$(LIBFT) $(PRINTF) $(MLX) $(NAME)

# Compile libft, ft_printf  & MiniLibX if they don't exist
$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF):
	make -C $(PRINTF_DIR)

$(MLX):
	make -C $(MLX_DIR)
	touch $(MLX)

# Compile executable
$(NAME):	$(OBJS) $(LIBFT) $(PRINTF) $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) $(PRINTF_FLAGS) -o $(NAME)

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
	make -C $(PRINTF_DIR) clean

# Clean everything
fclean: 	clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

# Re-compile from scratch
re: 		fclean all

.PHONY:		all clean fclean re
