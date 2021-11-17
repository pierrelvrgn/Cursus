# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plavergn <plavergn@student.42lyon.fr >     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/05 09:55:39 by plavergn          #+#    #+#              #
#    Updated: 2021/11/11 14:44:30 by plavergn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =  ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
        ft_isprint.c ft_memset.c ft_strlen.c ft_memcpy.c ft_memmove.c \
        ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
        ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
        ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
        ft_split.c ft_itoa.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
        ft_putstr_fd.c ft_striteri.c ft_strmapi.c

BONUS =  ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS = ${SRCS:.c=.o}

BONUS_OBJS = ${BONUS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

%.o: %.c libft.h
		gcc ${CFLAGS} -c $< -o $@

${NAME}: ${OBJS}
		ar rcs $@ $^

all: ${NAME}

clean:
		rm -rf ${OBJS} ${BONUS_OBJS}

fclean: clean
		rm -rf ${NAME}

re: fclean all

bonus:  ${OBJS} ${BONUS_OBJS}
		ar rcs ${NAME} ${OBJS} ${BONUS:.c=.o}

.PHONY: all %.o clean fclean re bonus
