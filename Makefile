# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proshchy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 18:36:49 by proshchy          #+#    #+#              #
#    Updated: 2018/01/02 18:40:54 by proshchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = main.c get_next_line.c get_next_line.h libft.a
NAME = gnl
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	@gcc $(SRC) $(FLAGS)

clean:
	@rm -f *.gch

re: clean
	$(NAME)

.PHONY: all clean re
