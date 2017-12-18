# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: proshchy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/18 18:36:49 by proshchy          #+#    #+#              #
#    Updated: 2017/12/18 18:36:51 by proshchy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = get_next_line.c get_next_line.h libft.a
NAME = gnl

all: $(NAME)

$(NAME):
	@gcc $(SRC)

clean:
	rm -f *.gch

re: clean
	$(NAME)

.PHONY: all clean re