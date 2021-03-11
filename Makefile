# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 12:25:49 by atahiri           #+#    #+#              #
#    Updated: 2021/03/11 12:30:31 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = gcc
AR= ar
FLAGS = -Wall -Werror -Wextra
SRC = *.c
all:$(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(AR) rc $(NAME) *.o
	$(CC) $(SRC) $(NAME) -o checker
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME)
re:fclean all