# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 12:25:49 by atahiri           #+#    #+#              #
#    Updated: 2021/03/11 14:29:42 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = gcc
AR= ar
FLAGS = -Wall -Werror -Wextra
SRC = includes/push_swap.h checker/*.c
all:$(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	$(AR) rc $(NAME) *.o
	$(CC) $(SRC) $(NAME)
clean:
	rm -rf *.o
fclean: clean
	rm -rf $(NAME) && rm -rf includes/push_swap.h.gch
re:fclean all