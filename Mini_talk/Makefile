# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 10:40:12 by plavergn          #+#    #+#              #
#    Updated: 2022/03/24 13:22:01 by plavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server

SRC_SERVER =	main_server.c\

OBJ_SERVER = $(SRC_SERVER:.c=.o)
INCDIR_SERVER = minitalk_server.h

NAME_CLIENT = client

SRC_CLIENT =	main_client.c\

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
INCDIR_CLIENT = minitalk_client.h

FLAGS = -Wall -Wextra -Werror

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER)
	gcc $(FLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	gcc $(FLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)

$(OBJ_SERVER): $(SRC_SERVER) $(INCDIR_SERVER)
	gcc $(FLAGS) -c $(SRC_SERVER)

$(OBJ_CLIENT): $(SRC_CLIENT) $(INCDIR_CLIENT)
	gcc $(FLAGS) -c $(SRC_CLIENT)

clean:
	rm -rf $(OBJ_SERVER)
	rm -rf $(OBJ_CLIENT)

fclean: clean
	rm -rf $(NAME_SERVER)
	rm -rf $(NAME_CLIENT)

re: fclean all
