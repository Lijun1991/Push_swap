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
NAME1 = checker

SRC = main.c parse_arg.c handle_lst.c handle_data.c helper.c sort.c \
sort_helper.c check_arg.c 

SRC1 = checker.c parse_arg.c handle_lst.c handle_data.c helper.c sort.c \
sort_helper.c check_arg.c 

OBJ = $(SRC:.c=.o)

OBJ1 = $(SRC1:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -Ilibft
.PHONY: all clean fclean re

all: $(NAME) $(NAME1)

$(NAME): $(OBJ)
	make -C ./libft
	gcc $(CFLAGS) -o $(NAME) $(OBJ) -L libft/ -lft

$(NAME1): $(OBJ1)
	make -C ./libft
	gcc $(CFLAGS) -o $(NAME1) $(OBJ1) -L libft/ -lft

clean:
	make -C ./libft clean
	rm -f $(OBJ)
	rm -f $(OBJ1)

fclean:
	make -C ./libft fclean
	rm -f $(OBJ) $(NAME)
	rm -f $(OBJ1) $(NAME1)

re: fclean $(NAME) fclean $(NAME1)

