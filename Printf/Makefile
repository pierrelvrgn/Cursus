# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/16 11:13:11 by plavergn          #+#    #+#              #
#    Updated: 2021/11/17 12:36:50 by plavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =  ft_printf.c \
        utils/print.c\
		printer/ft_print_c.c\
		printer/ft_print_i.c\
		printer/ft_print_percent.c\
		printer/ft_print_u.c\
		utils/ft_putnbr.c\
		utils/ft_putstr.c\
		printer/ft_print_d.c\
		printer/ft_print_p.c\
		printer/ft_print_s.c\
		printer/ft_print_x.c\
		utils/ft_putchar.c\
		utils/ft_putnbr_base.c

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
