NAME		=	identify

INCLUDES	=	includes/Base.hpp \
				includes/A.hpp \
				includes/B.hpp \
				includes/C.hpp

SRCS		=	src/main.cpp \
				src/generate.cpp \
				src/identify.cpp

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
