# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moseddik <moseddik@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 15:32:08 by moseddik          #+#    #+#              #
#    Updated: 2023/01/04 15:00:55 by moseddik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# *********************************** Colors ***********************************
NC				:= \033[m
RED				:= \033[0;31m
GREEN			:= \033[1;32m
YELLOW			:= \033[1;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[1;35m
CYAN			:= \033[1;36m

# ******************************** Directories *********************************
SRC_DIR			:= src
OBJ_DIR			:= obj

# *********************************** Files ************************************
NAME			:= Bureaucrat
INC				:= Bureaucrat.hpp
SRC				:= main.cpp Bureaucrat.cpp
OBJ				:= $(SRC:.cpp=.o)

# ****************************** Compiler Options ******************************
CXX				:= c++
CXXFLAGS		:= -Wall -Wextra -Werror -std=c++98

# ******************************* Other commands *******************************
RM				:= rm -rf
MKDIR			:= mkdir -p

# ******************************** Dependencies ********************************
OBJ_DEP			:= $(addprefix $(OBJ_DIR)/, $(OBJ))

# ********************************** Targets ***********************************
all: $(NAME)

$(NAME): $(OBJ_DEP)
	@echo "$(BLUE)Building	$(PURPLE)$(NAME)$(NC)"
	@$(CXX) $(CXXFLAGS) $(OBJ_DEP) -o $(NAME)

$(OBJ_DIR)/%.o:%.cpp $(INC)
	@$(MKDIR) $(OBJ_DIR)
	@echo "$(GREEN)Compiling	$(YELLOW)$(shell basename $<)$(NC)"
	@$(CXX) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)Removing	$(YELLOW)Object files$(NC)"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing	$(PURPLE)$(NAME)$(NC)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re