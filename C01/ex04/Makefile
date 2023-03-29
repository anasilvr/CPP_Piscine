NAME	= sed

HEADER	= $(addprefix include/, sed.hpp)
SRCS 	= $(addprefix src/, main.cpp sed.cpp )
OBJS 	= $(SRCS:%.cpp=%.o)

CC 		= c++
CFLAGS 	= -Wall -Wextra -Werror -std=c++98

#----------RULES----------#

all:	$(NAME)

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "\n\033[32m\033[1mSed is ready to change your files!\n\033[0m"
clean:
			rm -f $(OBJS)

fclean: 	clean
			@rm -f $(NAME)
			@echo "\n\033[32m\033[1mClean Done!\n\033[0m"

re:			fclean all

.PHONY: all clean fclean re