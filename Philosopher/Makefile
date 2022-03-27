# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 08:01:16 by plavergn          #+#    #+#              #
#    Updated: 2022/03/27 09:34:56 by plavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	main.c\
		ft_atoi.c\
		action.c\
		init.c\

OBJ = $(SRC:.c=.o)
INCDIR = philo.h
FLAGS = -Wall -Wextra -Werror #-fsanitize=thread

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

$(OBJ): $(SRC) $(INCDIR)
	gcc $(FLAGS) -c $(SRC)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
