NAME	= Animals

HEADER	= $(addprefix include/, Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp)
SRCS 	= $(addprefix src/, main.cpp Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp)
OBJS 	= $(SRCS:%.cpp=%.o)

CC 		= c++
CFLAGS 	= -Wall -Wextra -Werror -std=c++98

#----------RULES----------#

all:	$(NAME)

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "\n\033[32m\033[1mAnimals Compiled!\n\033[0m"

clean:
			rm -f $(OBJS)

fclean: 	clean
			@rm -f $(NAME)
			@echo "\n\033[32m\033[1mCleaned!\n\033[0m"
			@rm -rf *.dSYM

re:			fclean all

.PHONY: all clean fclean re
