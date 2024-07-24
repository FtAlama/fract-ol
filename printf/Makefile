# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alama <alama@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 22:04:49 by alama             #+#    #+#              #
#    Updated: 2024/06/24 14:11:57 by alama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c ft_write.c ft_putnbr_base_unsigned.c ft_putnbr_ptr.c \
		ft_putnbr.c
		

OBJ = $(SRC:.c=.o)


AR		=	@ar -rc

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
