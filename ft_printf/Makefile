# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nperez-d <nperez-d@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/02 16:53:24 by nperez-d          #+#    #+#              #
#    Updated: 2025/02/20 18:33:06 by nperez-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRCS	= 	src/ft_printf.c \
			src/ft_printf_wrtutils.c \
			src/ft_printf_nbrutils.c

OBJS	= *.o

INC		= includes/

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -fPIC -g

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRCS) -I $(INC)
	@ar -rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@/bin/rm -rf $(OBJS)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
