# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alama <alama@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/23 19:28:32 by alama             #+#    #+#              #
#    Updated: 2024/06/24 17:27:04 by alama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tools.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = strings_utils.c calculs.c

OBJ = $(SRC:.c=.o)

AR = @ar -rc

all : $(NAME)

$(NAME) : $(OBJ)
	@$(AR) $(NAME) ${OBJ}

$(OBJ) :
	@$(CC) $(CFLAGS) -c $(@:.o=.c)

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean $(NAME)

.PHONY: all fclean clean re
