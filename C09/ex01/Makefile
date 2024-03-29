#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

# Special variables
DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re

# Hide calls
export VERBOSE	=	TRUE
ifeq ($(VERBOSE),TRUE)
	HIDE =
else
	HIDE = @
endif


#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

# Compiler and flags
CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I.
RM		=	rm -rf

# Dir and file names
NAME	=	RPN
SRCS	=	$(addprefix src/, main.cpp RPN.cpp)
OBJS	=	$(SRCS:.cpp=.o)
INC		=	$(addprefix include/, wildcard *.hpp)


#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(NAME)

# Generates output file
$(NAME): $(OBJS)
	$(HIDE)$(CC) $(CFLAGS) $(OBJS) -o $@

# Compiles sources into objects
.cpp.o: $(SRCS) $(INC)
	$(HIDE)$(CC) $(CFLAGS) -c $< -o $@

# Removes objects
clean:
	$(HIDE)$(RM) $(OBJS)

# Removes objects and executables
fclean: clean
	$(HIDE)$(RM) $(NAME)

# Removes objects and executables and remakes
re: fclean all

test: all
	@echo "\033[32m\033[1mTest 1\033[0m"
	./$(NAME) "3 4 * 5 6 * +"
	@echo "Answer: 42"
	@sleep 1

	@echo "\n\033[32m\033[1mTest 2\033[0m"
	./$(NAME) "8 2 / 8 2 / +"
	@echo "Answer: 8"
	@sleep 1

	@echo "\n\033[32m\033[1mTest 3\033[0m"
	./$(NAME) "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"
	@echo "Answer: 15"
	@sleep 1

	@echo "\n\033[32m\033[1mTest 4\033[0m"
	./$(NAME) "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "Answer: 42"
	
	@sleep 1
	@echo "\n\033[32m\033[1mDONE!\033[0m"
	@sleep 0.5