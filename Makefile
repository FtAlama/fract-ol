# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alama <alama@student.s19.be>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 19:05:27 by alama             #+#    #+#              #
#    Updated: 2024/07/25 21:05:18 by alama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#############################################

GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
NC = \033[0m 
Magenta = \033[0;35m
CYAN = \033[0;36m
GRAY = \033[0;90m
RED = \033[0;31m
SPINNERS = "🔄 🔁 ↩️ ↪️ 🔄 🔁"

#############################################

NAME = fractol

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = src/main.c src/mlx_event.c src/fractol.c src/render.c src/zoom.c 

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

SRC_DIR = src

OBJ_DIR = .cache

PRINTF = ./printf/libftprintf.a

TOOLS = ./tools_lib/tools.a

LINK = -Lminilibx -lmlx -framework OpenGL -framework AppKit

#############################################

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(RED)"
	@echo "______              _        _ "
	@echo "|  ___|            | |      | |"
	@echo "| |_ _ __ __ _  ___| |_ ___ | |         __  "
	@echo "|  _| '__/ _  |/ __| __/ _ \| |     ___( o)>"
	@echo "| | | | | (_| | (__| || (_) | |     \ <_. ) "
	@echo "\_| |_|  \__,_|\___|\__\___/|_|...    ---'   By ALAMA"
	@echo "$(YELLOW)Building printf library...$(NC)"
	@make -C ./printf
	@echo "$(YELLOW)Building tools library...$(NC)"
	@make -C ./tools_lib
	@echo "$(YELLOW)Building minilibx library...$(GRAY)"
	@make -C ./minilibx 2>/dev/null
	@total=$(words $(OBJ)); \
	count=0; \
	for file in $(OBJ); do \
		$(CC) $(CFLAGS) -o $(NAME) $(PRINTF) $(TOOLS) $(LINK) $(SRC) -I./includes -I./printf -I./tools_lib; \
		count=$$((count + 1)); \
		percentage=$$((count * 100 / total)); \
		progress=$$((percentage / 2)); \
		spinner=$$(echo $(SPINNERS) | cut -d ' ' -f $$(($$count % 6 + 1))); \
		bar=""; \
		for i in $$(seq 1 $$progress); do bar="$${bar}█"; done; \
		for i in $$(seq $$progress 49); do bar="$${bar}░"; done; \
		if [ $$percentage -eq 100 ]; then \
			bar="███████████████████████████████████████████████████"; \
		fi; \
		printf "\r$(YELLOW)Compiling : $${bar} %d%% $${spinner}" $$percentage; \
		sleep 0.01; \
	done;\
	printf "\n"; \
	echo "$(GREEN)Compilation successful!$(NC)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@ -I./includes -I./printf -I./tools_lib

$(OBJ_DIR):
	@echo "C$(BLUE)ompiling $<..."
	@mkdir -p $(OBJ_DIR)
	@echo "$(GREEN)Bonus Compilation successful!$(NC)"

bonus:
	@echo "$(BLUE)Building bonus...$(Magenta)"
	@make -C ./bonus
	@mv ./bonus/fractol_bonus .

clean:
	@echo "$(YELLOW)Cleaning project...$(Magenta)"
	@make clean -C ./printf
	@make clean -C ./tools_lib
	@make clean -C ./minilibx
	@make clean -C ./bonus
	@rm -rf $(OBJ_DIR)
	@echo "$(GREEN)Clean successful!$(NC)"

fclean: clean
	@echo "$(YELLOW)Full clean of project...$(Magenta)"
	@make fclean -C ./printf
	@make fclean -C ./tools_lib
	@make fclean -C ./bonus
	@rm -f fractol_bonus
	@rm -f $(NAME) *.o
	@echo "$(GREEN)Fclean successful!$(NC)"

re: fclean $(NAME)

.PHONY: all fclean clean re printf bonus
