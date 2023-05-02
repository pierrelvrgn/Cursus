NAME	=	zombie

INCLUDES	=	Zombie.hpp

SRC		=	Zombie.cpp \
			newZombie.cpp \
			randomChump.cpp \
			main.cpp

OBJ = $(SRC:.cpp=.o)
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
