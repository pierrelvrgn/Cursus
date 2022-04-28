# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/27 20:13:14 by plavergn          #+#    #+#              #
#    Updated: 2022/04/28 11:45:50 by plavergn         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = morpion

SRC =	srcs/main.c\
		srcs/init_struct.c\
		srcs/init_board.c\
		srcs/ft_free.c\

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror #-fsanitize=address

%.o: %.c include/morpion.h
		gcc ${CFLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) Makefile
	gcc $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
