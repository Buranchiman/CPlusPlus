# Compiler
CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3 -MMD -MP

# Project name (final executable)
NAME = materia

# Sources and objects
SRCS = AMateria.cpp \
	   Character.cpp \
	   MateriaSource.cpp \
	   Ice.cpp \
	   Cure.cpp \
       main.cpp

OBJS_DIR = objs
OBJS = $(addprefix $(OBJS_DIR)/, $(SRCS:.cpp=.o))
DEPS = $(OBJS:.o=.d)

# Default rule
all: $(NAME)

# Link the executable
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile each .cpp to objs/%.o and generate deps
$(OBJS_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include dependency files if they exist
-include $(DEPS)

# Clean object files and dependency files
clean:
	rm -rf $(OBJS_DIR)

# Clean everything
fclean: clean
	rm -f $(NAME)

# Rebuild all
re: fclean all

.PHONY: all clean fclean re
