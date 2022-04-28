# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/26 08:01:16 by plavergn          #+#    #+#              #
#    Updated: 2022/04/14 09:03:55 by plavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	srcs/main.c\
		srcs/utils.c\
		srcs/action.c\
		srcs/init_info.c\
		srcs/init_philo.c\
		srcs/init_thread.c\
		srcs/init_all.c\
		srcs/ft_free.c\
		srcs/ft_putstr.c\
		srcs/ft_atoi.c\

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror #-fsanitize=thread

%.o: %.c include/philo.h
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
