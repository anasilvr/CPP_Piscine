NAME	= FragTrap

HEADER	= $(addprefix include/, ClapTrap.hpp FragTrap.hpp ScavTrap.hpp)
SRCS 	= $(addprefix src/, main.cpp ClapTrap.cpp FragTrap.cpp ScavTrap.cpp)
OBJS 	= $(SRCS:%.cpp=%.o)

CC 		= c++
CFLAGS 	= -Wall -Wextra -Werror -std=c++98

#----------RULES----------#

all:	$(NAME)

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "\n\033[32m\033[1mFragTrap Compiled!\n\033[0m"

clean:
			rm -f $(OBJS)

fclean: 	clean
			@rm -f $(NAME)
			@echo "\n\033[32m\033[1mCleaned!\n\033[0m"

re:			fclean all

.PHONY: all clean fclean re
