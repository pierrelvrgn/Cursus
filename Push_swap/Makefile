# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:31:04 by plavergn          #+#    #+#              #
#    Updated: 2022/03/22 17:31:21 by plavergn         ###   ########.fr        #
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

OBJ = $(SRC:.c=.o)
INCDIR = push_swap.h
FLAGS = -Wall -Wextra -Werror -fsanitize=address
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


#
