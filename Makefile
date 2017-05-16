# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lwang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/16 10:42:40 by lwang             #+#    #+#              #
#    Updated: 2017/05/16 10:42:42 by lwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c 

OBJ = $(SRC:.c=.o)


CFLAGS = -Wall -Wextra -Werror -g -Ilibft
.PHONY: all clean fclean re

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

all: $(NAME)

clean:
	make -C ./libft clean
	rm -f $(OBJ)

fclean:
	make -C ./libft fclean
	rm -f $(OBJ) $(NAME)

re: fclean $(NAME)

