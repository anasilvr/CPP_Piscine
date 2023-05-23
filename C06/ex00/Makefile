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
CFLAGS	=	-Wall -Werror -Wextra -I. -std=c++98 -g
RM		=	rm -rf

# Dir and file names
NAME	=	converter
SRCS	=	$(addprefix src/, main.cpp Converter.cpp)
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
	./$(NAME) 0
	@sleep 0.5

	@echo "\n"
	./$(NAME) 0.0
	@sleep 0.5

	@echo "\n"
	./$(NAME) 000000000000000000000000.00000000000000000000000
	@sleep 0.5

	@echo "\n"
	./$(NAME) 0.f
	@sleep 0.5

	@echo "\n"
	./$(NAME) nanf
	@sleep 0.5

	@echo "\n"
	./$(NAME) -inff
	@sleep 0.5

	@echo "\n"
	./$(NAME) +inff
	@sleep 0.5

	@echo "\n"
	./$(NAME) nan
	@sleep 0.5

	@echo "\n"
	./$(NAME) -inf
	@sleep 0.5

	@echo "\n"
	./$(NAME) +inf
	@sleep 0.5
	
	@echo "\n"
	./$(NAME) +inf
	@sleep 0.5

	@echo "\n"
	./$(NAME) 42.0f
	@sleep 0.5

	@echo "\n"
	./$(NAME) 2147483647
	@sleep 0.5

	@echo "\n"
	./$(NAME) 2147483648
	@sleep 0.5