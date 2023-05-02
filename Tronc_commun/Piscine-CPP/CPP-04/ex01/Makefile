NAME		=	burn_the_world

INCLUDES	=	includes/Animal.hpp \
				includes/Brain.hpp \
				includes/WrongAnimal.hpp \
				includes/WrongCat.hpp \
				includes/Cat.hpp \
				includes/Dog.hpp

SRCS		=	srcs/Animal.cpp \
				srcs/WrongAnimal.cpp \
				srcs/WrongCat.cpp \
				srcs/Cat.cpp \
				srcs/Brain.cpp \
				srcs/Dog.cpp \
				srcs/main.cpp

OBJ = $(SRCS:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

%.o: %.cpp $(INCLUDES)
		c++ ${FLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) Makefile
		c++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
