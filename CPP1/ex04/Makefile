# Compiler
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Project name (final executable)
NAME = sed42

# Sources and objects
SRCS	= main.cpp

OBJS = $(SRCS:.cpp=.o)

# Default rule
all: $(NAME)

# Build the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Compile .cpp into .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJS)

# Remove objects and executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
