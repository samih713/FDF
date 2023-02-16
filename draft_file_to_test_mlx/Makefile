# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/24 14:50:51 by sabdelra          #+#    #+#              #
#    Updated: 2022/12/29 03:33:17 by sabdelra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC:= fdf.c helper.c #put sources here

OBJ:= $(SRC:.c=.o)

SRC_BONUS:= # can be same as SRC

OBJ_BONUS:=$(SRC_BONUS:.o=.c)

CC_FLAGS = -Wall -Wextra -Werror -O3

# gnl include
INC_DIR:= ./include

# gnl library
GNL_LIB:= ./lib/libgnl.a

GNL_DIR:= ./get_next_line

CC:= gcc

MLX_FLAGS:=-lmlx_Linux -lXext -lX11 -lm -lz

NAME:= fdf

all: $(NAME)

test: test.c gnl
	$(CC) test.c $(GNL_LIB) -o test -g

$(NAME): gnl $(OBJ)
	$(CC) $(CC_FLAGS) $(OBJ) -o $@ $(MLX_FLAGS) $(GNL_LIB)

gnl:
	cd ./$(GNL_DIR) && $(MAKE)
	$(clean)

fclean: clean
	rm $(NAME)

clean:
	@rm $(OBJ)

re: all fclean

.PHONY: re clean fclean gnl all
