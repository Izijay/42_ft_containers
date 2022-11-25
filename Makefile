
NAME			=	tester

CXX				=	c++

SRC_DIR			=	$(shell find ./testers -type d)

OBJ_DIR			=	.obj

vpath %.cpp $(foreach dir, $(SRC_DIR), $(dir):)

# library -----------------------------------------------------------

SRC			=	tester.cpp vector_test.cpp map_test.cpp stack_test.cpp 

INC			=	map.hpp \
				iterator_traits.hpp \
				iterator.hpp \
				stack.hpp \
				vector.hpp \
				RedBlackTree.hpp \
				reverse_iterator.hpp \
				utils.hpp 


OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.cpp=%.o))

# Compilation flags -------------------------------------------------

CPPFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g3
IFLAGS			=	 -I /usr/include

# Colors ------------------------------------------------------------

_GREY	=	$'\e[30m
_RED	=	$'\e[31m
_GREEN	=	$'\e[32m
_YELLOW	=	$'\e[33m
_BLUE	=	$'\e[34m
_PURPLE	=	$'\e[35m
_CYAN	=	$'\e[36m
_WHITE	=	$'\e[37m

# main part ---------------------------------------------------------

$(OBJ_DIR)/%.o : %.cpp $(INC)
		@echo "Compiling $(_YELLOW)$@$(_WHITE) ... \c"
		@mkdir -p $(OBJ_DIR)
		@$(CXX) $(CPPFLAGS)  -c $< -o $@
		@echo "$(_GREEN)DONE$(_WHITE)"


all: $(NAME)

$(NAME): $(OBJ)
		@echo "-----\nCreating Binary File $(_YELLOW)$@$(_WHITE) ... \c"
		$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)
		@echo "$(_GREEN)DONE$(_WHITE)\n-----"

clean:
		@echo "$(_WHITE)Deleting Objects Directory $(_YELLOW)$(OBJ_DIR)$(_WHITE) ... \c"
		@rm -rf $(OBJ_DIR) .valgrind_results *.txt
		@echo "$(_GREEN)DONE$(_WHITE)\n-----"

fclean: clean
		@echo "$(_WHITE)Deleting Binary File $(_YELLOW)$(NAME)$(_WHITE) ... \c"
		@rm -f $(NAME)
		@echo "$(_GREEN)DONE$(_WHITE)\n-----"

re:		fclean all

test: all
		@echo "-----\nRunning $(_YELLOW)$(NAME)$(_WHITE) ... \c"
		@mkdir -p .valgrind_results
		@valgrind --leak-check=full --track-origins=yes ./tester vector 2> .valgrind_results/vector.txt
		@valgrind --leak-check=full --track-origins=yes ./tester map 2> .valgrind_results/map.txt
		@valgrind --leak-check=full --track-origins=yes ./tester stack 2> .valgrind_results/stack.txt
		@echo "$(_GREEN)DONE$(_WHITE)\n-----"


.PHONY:		all clean fclean re test
