# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 08:50:49 by plavergn          #+#    #+#              #
#    Updated: 2022/12/02 09:56:39 by plavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	cub3D

MOVEMENT		=	src/movement/ft_select_hook.c \
					src/movement/movement.c \
					src/movement/movement_utils.c

GET_NEXT_LINE	=	src/get_next_line/get_next_line.c \
					src/get_next_line/get_next_line_utils.c

INIT			=	src/init/init_struct.c \
					src/init/ft_init_textures.c

PARSING			=	src/parsing/parsing_map.c \
					src/parsing/ft_check_filename.c \
					src/parsing/ft_check_map.c \
					src/parsing/parsing.c \
					src/parsing/ft_check_textures_utils.c \
					src/parsing/ft_check_textures.c \
					src/parsing/ft_check_color.c \
					src/parsing/init_textures.c \
					src/parsing/check_space.c

RAYCASTING		=	src/raycasting/raycasting.c \
					src/raycasting/textures.c


UTILS			=	src/utils/random_utils.c \
					src/utils/string_utils.c \
					src/utils/closing.c \
					src/utils/utils.c

SRC				=	src/main.c \
					$(MOVEMENT) \
					$(GET_NEXT_LINE) \
					$(INIT) \
					$(PARSING) \
					$(RAYCASTING) \
					$(UTILS)

INCS			=	includes/cub3d_define.h \
					includes/cub3d.h \
					includes/cub3d_functions.h \
					includes/cub3d_structures.h \
					includes/get_next_line.h

OBJ		=	$(SRC:.c=.o)



NAME_BONUS			=	cub3D_bonus

MOVEMENT_BONUS		=	bonus/src/movement/ft_select_hook.c \
						bonus/src/movement/movement.c \
						bonus/src/movement/movement_utils.c

GET_NEXT_LINE_BONUS	=	bonus/src/get_next_line/get_next_line.c \
						bonus/src/get_next_line/get_next_line_utils.c

INIT_BONUS			=	bonus/src/init/init_struct.c \
						bonus/src/init/ft_init_textures.c

PARSING_BONUS		=	bonus/src/parsing/parsing_map.c \
						bonus/src/parsing/ft_check_filename.c \
						bonus/src/parsing/ft_check_map.c \
						bonus/src/parsing/parsing.c \
						bonus/src/parsing/ft_check_textures_utils.c \
						bonus/src/parsing/ft_check_textures.c \
						bonus/src/parsing/ft_check_color.c \
						bonus/src/parsing/init_textures.c \
						bonus/src/parsing/check_space.c

RAYCASTING_BONUS	=	bonus/src/raycasting/raycasting.c \
						bonus/src/raycasting/textures.c

UTILS_BONUS			=	bonus/src/utils/random_utils.c \
						bonus/src/utils/string_utils.c \
						bonus/src/utils/closing.c \
						bonus/src/utils/utils.c

SRC_BONUS			=	bonus/src/main.c \
						$(MOVEMENT_BONUS) \
						$(GET_NEXT_LINE_BONUS) \
						$(INIT_BONUS) \
						$(PARSING_BONUS) \
						$(RAYCASTING_BONUS) \
						$(UTILS_BONUS)

INCS_BONUS			=	bonus/includes/cub3d_define.h \
						bonus/includes/cub3d.h \
						bonus/includes/cub3d_functions.h \
						bonus/includes/cub3d_structures.h \
						bonus/includes/get_next_line.h

OBJ_BONUS			=		$(SRC_BONUS:.c=.o)


FLAGS	=	-Wall -Wextra -Werror #-fsanitize=address
 
%.o: %.c
	gcc $(FLAGS) -Imlx -c $< -o $@

all: $(NAME)

$(NAME): $(INCS) $(OBJ) Makefile
	gcc $(OBJ) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) Makefile $(INCS_BONUS)
	gcc $(OBJ_BONUS) $(FLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS)

.PHONY: re clean fclean all bonus
