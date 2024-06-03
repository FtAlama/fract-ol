# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alama <alama@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 14:41:06 by alama             #+#    #+#              #
#    Updated: 2024/06/03 15:20:05 by alama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c

OBJ = $(SRC:.c=.o)

LINK = -l -lmlx -framework OpenGL -framework AppKit


all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(LINK)

$(OBJ) :
	$(CFLAGS) -c $(@:.o=.c) 

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all fclean clean re
