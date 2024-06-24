#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alama <alama@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 19:05:27 by alama             #+#    #+#              #
#    Updated: 2024/06/24 14:09:21 by alama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c mlx_event.c fractol.c render.c

OBJ = $(SRC:.c=.o)

PRINTF = ./printf/libftprintf.a

TOOLS = ./tools_lib/tools.a

LINK = -Lminilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./printf
	@make -C ./tools_lib
	@$(CC) $(CFLAGS) -o $(NAME) $(PRINTF) $(TOOLS) $(LINK) $(SRC)
	@echo "Compilation successful!"

$(OBJ):
	@$(CC) $(CFLAGS) -c $(@:.o=.c)

clean:
	@make clean -C ./printf
	@make clean -C ./tools_lib
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C ./printf
	@make fclean -C ./tools_lib
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all fclean clean re printf
