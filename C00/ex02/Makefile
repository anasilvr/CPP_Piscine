NAME	= Account
SRCS 	= Account.cpp tests.cpp
INC		= include
OBJS 	= $(SRCS:.cpp=.o)

CC 		= c++
CFLAGS 	= -Wall -Wextra -Werror -std=c++98 -I$(INC)

#----------RULES----------#

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "\n\033[32m\033[1mCompiled!\n\033[0m"

clean:
			rm -f $(OBJS)

fclean: 	clean
			@rm -f $(NAME)
			@echo "\n\033[32m\033[1mClean Done!\n\033[0m"

re:			fclean all

.PHONY: all clean fclean re test