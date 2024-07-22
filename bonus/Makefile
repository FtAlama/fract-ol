# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alama <alama@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 19:05:27 by alama             #+#    #+#              #
#    Updated: 2024/07/22 19:52:03 by alama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/mlx_event.c src/fractol.c src/render.c src/zoom.c src/lorenz.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_DIR = src

OBJ_DIR = obj

PRINTF = ./printf/libftprintf.a

TOOLS = ./tools_lib/tools.a

LINK = -Lminilibx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./printf
	@make -C ./tools_lib
	@make -C ./minilibx 2>/dev/null
	@$(CC) $(CFLAGS) -o $(NAME) $(PRINTF) $(TOOLS) $(LINK) $(SRC) -I./includes -I./printf -I./tools_lib
	@echo "Compilation successful!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I./includes -I./printf -I./tools_lib

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@make clean -C ./printf
	@make clean -C ./tools_lib
	@make clean -C ./minilibx
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C ./printf
	@make fclean -C ./tools_lib
	@rm -f $(NAME) *.o

re: fclean $(NAME)

.PHONY: all fclean clean re printf
