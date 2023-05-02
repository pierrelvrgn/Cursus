NAME		=	execuuuute

INCLUDES	=	includes/Bureaucrat.hpp \
				includes/Form.hpp \
				includes/ShrubberyCreationForm.hpp \
				includes/RobotomyRequestForm.hpp \
				includes/PresidentialPardonForm.hpp

SRCS		=	src/main.cpp \
				src/Bureaucrat.cpp \
				src/Form.cpp \
				src/ShrubberyCreationForm.cpp \
				src/RobotomyRequestForm.cpp \
				src/PresidentialPardonForm.cpp

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
