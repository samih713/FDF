# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 02:34:38 by sabdelra          #+#    #+#              #
#    Updated: 2023/02/06 02:57:44 by sabdelra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC:= main.c
OBJ:= main.o
NAME:= fdf
CCFLAGS:= -Wall -Werror -Wextra
GNLDIR:= ../gnl/
GNLLIB:= libgnl.a

all: $(NAME)

$(NAME): $(GNLLIB)
	$(CC) $(CCFLAGS) $(SRC) $(GNLDIR)$(GNLLIB) -o $@

$(GNLLIB):
	cd $(GNLDIR) && make

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all fclean re
