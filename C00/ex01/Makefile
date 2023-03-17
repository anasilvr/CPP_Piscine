NAME	= yellowpages
HEADER	= $(addprefix include/, Yellowpages.hpp Contact.hpp)

SRCS 	= $(addprefix src/, YellowPages.cpp Contact.cpp)
OBJS 	= $(SRCS:.cpp=.o)

CC 		= c++
CFLAGS 	= -Wall -Wextra -Werror -std=c++98

#----------RULES----------#

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) main.cpp $(OBJS) -o $(NAME)
			@echo "\n\033[32m\033[1mYour new phonebook is ready!\n\033[0m"

clean:
			rm -f $(OBJS)
			rm -f main.o

fclean: 	clean
			@rm -f $(NAME)
			@echo "\n\033[32m\033[1mClean Done!\n\033[0m"

re:			fclean all

.cpp.o:
			$(CC) $(CFLAGS)  -c $< -o $(<:.cpp=.o)

.PHONY: all clean fclean re test