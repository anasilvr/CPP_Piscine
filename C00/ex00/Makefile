NAME	= megaphone
SRCS 	= megaphone.cpp
OBJS 	= $(SRCS:.cpp=.o)

CC 		= c++
CFLAGS 	= -Wall -Wextra -Werror -std=c++98

#----------RULES----------#

all:	$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "\n\033[32m\033[1mMegaphone compiled!\n\033[0m"

clean:
			rm -f $(OBJS)

fclean: 	clean
			@rm -f $(NAME)
			@echo "\n\033[32m\033[1mClean Done!\n\033[0m"

re:			fclean all

test: all
			@echo "\033[32m\033[1mTest 1\033[0m"
			./$(NAME) "shhhhh... I think the students are asleep..."
			@sleep 1

			@echo "\n\033[32m\033[1mTest 2\033[0m"
			./$(NAME) Damnit " ! " "Sorry students, I thought this thing was off."
			@sleep 1

			@echo "\n\033[32m\033[1mTest 3\033[0m"
			./$(NAME)
			@sleep 1
			@echo "\n\033[32m\033[1mDONE!\033[0m"
			@sleep 0.5

.cpp.o:
			$(CC) $(CFLAGS)  -c $< -o $(<:.cpp=.o)

.PHONY: all clean fclean re test