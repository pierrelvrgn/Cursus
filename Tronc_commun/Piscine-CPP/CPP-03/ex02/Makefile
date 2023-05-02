NAME		=	claptrap

INCLUDES	=	ClapTrap.hpp \
				ScavTrap.hpp \
				FragTrap.hpp

SRCS		=	main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp

OBJ = $(SRCS:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

%.o: %.cpp $(INCLUDES)
		g++ ${FLAGS} -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) Makefile
		g++ $(FLAGS) $(OBJ) -o $(NAME)

clean:
		rm -rf $(OBJ)

fclean: clean
		rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
