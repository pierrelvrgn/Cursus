# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/19 16:31:04 by plavergn          #+#    #+#              #
#    Updated: 2022/03/01 18:33:24 by plavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC =	main.c\
		utils.c\
		ft_init_pile.c\
		ft_pre_sort.c\

OBJ = $(SRC:.c=.o)
INCDIR = includes/
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
