# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/29 18:59:27 by sabdelra          #+#    #+#              #
#    Updated: 2023/04/06 05:52:36 by sabdelra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### COLORS
COLOR_GREEN=\033[0;32m
COLOR_RED=\033[0;31m
COLOR_BLUE=\033[0;34m
COLOR_END=\033[0m
###

CCFLAGS:= -Wall -Werror -Wextra -g

SRC:= utils.c map.c map_utils.c draw.c transform.c wires.c error.c events.c test.c events_utils.c

OBJ:= utils.o map.o map_utils.o draw.o transform.o wires.o error.o events.o test.o events_utils.o

NAME:= fdf

INC_DIR:= ./include

GNL_DIR:= ./get_next_line

all: gnl $(NAME)

bonus: all

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -Lmlx -lmlx -L$(GNL_DIR) -lgnl -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(COLOR_GREEN)FDF ready$(COLOR_END)"

%.o: %.c
	@$(CC) $(CCFLAGS) -c -I $(INC_DIR) -Imlx $^ -o $@

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

