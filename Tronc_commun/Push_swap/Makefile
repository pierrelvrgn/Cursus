# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:31:04 by plavergn          #+#    #+#              #
#    Updated: 2022/03/23 09:33:43 by plavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	main.c\
		utils.c\
		ft_init_pile.c\
		ft_pre_sort.c\
		operation.c\
		ft_check_len.c\
		ft_sort.c\
		ft_sort_for_five.c\

OBJ = $(SRC:.c=.o)
INCDIR = push_swap.h
FLAGS = -Wall -Wextra -Werror
LINKS = libft/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME) $(LINKS)

$(OBJ): $(SRC) $(INCDIR)
	gcc $(FLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
