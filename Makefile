# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: makbulut <makbulut@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 13:24:52 by eagirman          #+#    #+#              #
#    Updated: 2022/03/06 11:25:41 by makbulut         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= $(wildcard *.c) $(wildcard libft/*.c)
OBJS		= $(SRCS:%.c=%.o)
$(NAME):	$(OBJS)
			make -C ./mlx
			mv ./mlx/libmlx.a ./libmlx.a
			$(CC) $(CFLAGS) $(SRCS) -framework OpenGL -framework AppKit libmlx.a -o $(NAME) -ggdb

all: 		$(NAME)

clean:
			make -C ./mlx clean
			rm -rf ./*.o libmlx.a so_long.o
			rm -rf ./libft/*.o

fclean: 	clean
			rm -rf so_long

re: 		fclean all

.PHONY: 	all clean fclean re