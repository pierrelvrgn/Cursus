NAME		=	phonebook

SRC			=	srcs/Contact.cpp\
				srcs/main.cpp\
				srcs/PhoneBook.cpp

INCLUDES	=	includes/Contact.hpp\
				includes/PhoneBook.hpp

OBJ			=	$(SRC:.cpp=.o)

FLAGS		=	-Wall -Wextra -Werror -std=c++98 #-fsanitize=address

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
