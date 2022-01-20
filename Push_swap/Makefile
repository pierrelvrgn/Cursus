# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:31:04 by plavergn          #+#    #+#              #
#    Updated: 2022/01/19 16:54:07 by plavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = 	main.c \
		utils.c\

OBJ = $(SRC:.c=.o)
INCDIR = push_swap.h
FLAGS = -Wall -Wextra -Werror
LINKS = libft/libft.a


all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) $(LINKS) -o $(NAME)

$(OBJ): $(SRC) $(INCDIR)
	gcc $(FLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
