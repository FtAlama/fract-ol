# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alama <alama@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:41:06 by alama             #+#    #+#              #
#    Updated: 2024/06/20 21:29:20 by alama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c math_utils.c mlx_event.c render.c tools.utils.c

OBJ = $(SRC:.c=.o)

LINK = -Lminilibx -lmlx -framework OpenGL -framework AppKit


all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(LINK)

$(OBJ) :
	$(CC) $(CFLAGS) -c $(@:.o=.c) 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all fclean clean re
