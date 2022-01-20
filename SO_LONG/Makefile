# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/13 10:38:53 by plavergn          #+#    #+#              #
#    Updated: 2022/01/19 07:16:23 by plavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = 	main.c \
		grass.c\
		get_next_line.c\
		get_next_line_utils.c\
		parser_map.c\
		utils.c\
		print_element.c\
		print_wall.c\
		ft_hook.c\
		ft_select_hook.c\

OBJ = $(SRC:.c=.o)
INCDIR = so_long.h
FLAGS = -Wall -Wextra -Werror
LINKS = libmlx.a -framework OpenGL -framework AppKit


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
