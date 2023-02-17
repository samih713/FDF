# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 18:59:27 by sabdelra          #+#    #+#              #
#    Updated: 2023/02/17 15:42:50 by sabdelra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLORS
COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_END=\033[0m
###

SRC:= utils.c map.c transform.c wires.c

OBJ:= utils.o map.o transform.o wires.o

INC_DIR:= ./include

LIB_DIR:= ./lib

GNL_DIR:= ./get_next_line

CC_FLAGS:= -Wall -Werror -Wextra -std=c99 -g

MLX_FLAGS:=-lmlx_Linux -lXext -lX11 -lm -lz

NAME:= fdf

all: $(NAME) gnl

test: test.c all
	@$(CC) $< $(NAME) -I $(INC_DIR) -L $(LIB_DIR) -lgnl $(MLX_FLAGS) -o $@ -g
	@echo "$(COLOR_BLUE)>>test is ready$(COLOR_END)"

$(NAME): $(OBJ)
	@ar rcs $@ $^
	@echo "$(COLOR_GREEN)>>fdf ready$(COLOR_END)"

%.o: %.c
	@$(CC) $(CC_FLAGS) -c -I $(INC_DIR) -lgnl $^ -o $@

gnl:
	$(MAKE) -C $(GNL_DIR)
	$(MAKE) -C $(GNL_DIR) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(GNL_DIR) fclean
	@echo "$(COLOR_RED)full clean completed$(COLOR_END)"

clean:
	@rm -f $(OBJ)

re: fclean all

.PHONY: all test fclean clean re

