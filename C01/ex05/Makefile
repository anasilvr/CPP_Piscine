NAME	= sed

SRCS 	= $(addprefix src/, main.cpp )
OBJS 	= $(SRCS:%.cpp=%.o)

CC 		= c++
CFLAGS 	= -Wall -Wextra -Werror -std=c++98

#----------RULES----------#

all:	$(NAME)

.cpp.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.cpp=.o)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "\n\033[32m\033[1m./Sed is ready to change your files!\033[0m"
			@echo "\033[1musage:\033[0m ./sed [filename] [word_to_search] [replacing_word]"
clean:
			rm -f $(OBJS)

fclean: 	clean
			@rm -f $(NAME)
			@echo "\n\033[32m\033[1mClean Done!\n\033[0m"

re:			fclean all

.PHONY: all clean fclean re