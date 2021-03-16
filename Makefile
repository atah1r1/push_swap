# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/11 12:25:49 by atahiri           #+#    #+#              #
#    Updated: 2021/03/16 11:27:45 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1=	checker

NAME2=	push_swap

all:	$(NAME1) $(NAME2)

SRC1=	checker.c ft_error.c ft_strlen.c ft_atoi.c ft_isdigit.c check_args.c stack.c duplicate_element.c instructions_check.c

SRC2=	push_swap.c

OBJ1=	$(SRC1:.c=.o)

OBJ2=	$(SRC2:.c=.o)

$(NAME1):
	gcc -Wall -Werror -Wextra -c $(SRC1) $(INCLUDES)
	gcc -o $(NAME1) $(OBJ1)

$(NAME2):
	gcc -Wall -Werror -Wextra -c $(SRC2) $(INCLUDES)
	gcc -o $(NAME2) $(OBJ2)

clean:
	rm -f *.o

fclean:	clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re:	fclean all