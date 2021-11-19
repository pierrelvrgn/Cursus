# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/19 11:22:35 by plavergn          #+#    #+#              #
#    Updated: 2021/11/19 15:28:14 by plavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRCS =	ft_printf.c\
		printer/ft_printer.c\
		utils/ft_putchar.c\
		utils/ft_putnbr.c\
		utils/ft_putnbr_base.c\
		utils/ft_putstr.c\
		utils/ft_putnbr_unsigned.c\
		utils/ft_print_small_hexa.c\
		utils/ft_print_big_hexa.c\
		utils/ft_print_void_hexa.c\
		utils/ft_putnbr_base_void.c\

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

%.o: %.c ft_printf.h
		gcc ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		ar rcs $@ $^

all: ${NAME}

clean:
		rm -rf ${OBJS}

fclean: clean
		rm -rf ${NAME}

re: fclean all

.PHONY: all %.o clean fclean re
