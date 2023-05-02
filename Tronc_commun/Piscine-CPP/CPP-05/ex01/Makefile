NAME		=	gonna_eat_paper

INCLUDES	=	Bureaucrat.hpp \
				Form.hpp

SRCS		=	main.cpp \
				Bureaucrat.cpp \
				Form.cpp

OBJ = $(SRCS:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

%.o: %.cpp
		c++ ${FLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) Makefile $(INCLUDES)
		c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
