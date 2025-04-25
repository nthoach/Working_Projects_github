<<<<<<< HEAD
# **************************************************************************** #
=======
#******************************************************************************#
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
<<<<<<< HEAD
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 13:54:54 by honguyen          #+#    #+#              #
#    Updated: 2025/04/25 16:16:50 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex00
=======
#    By: nthoach <nthoach@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 13:54:54 by honguyen          #+#    #+#              #
#    Updated: 2025/04/25 05:16:06 by nthoach          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= ex01
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRCS_DIR 	= srcs
SRCS		= $(addprefix $(SRCS_DIR)/, Bureaucrat.cpp Form.cpp main.cpp)

OBJS_DIR	= objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.cpp=.o)))

INCS_DIR	= incl
<<<<<<< HEAD
INCS		= $(addprefix $(INCS_DIR)/, Bureaucrat.hpp)
=======
INCS		= $(addprefix $(INCS_DIR)/, Bureaucrat.hpp Form.hpp)
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2

MAIN_INC	= -I$(INCS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@echo "Creating directory: $(OBJS_DIR)"
	@mkdir -p $(OBJS_DIR) || echo "Failed to create directory: $(OBJS_DIR)"
	${CXX} ${CXXFLAGS} ${MAIN_INC} -c $< -o $@

all			: $(NAME)

$(NAME)		: $(OBJS) $(INCS)
	$(CXX) $(CXXFLAGS) $(OBJS) $(MAIN_INC) -o $(NAME)

clean		:
			@$(RM) $(OBJS)
			@rmdir $(OBJS_DIR) 2>/dev/null || true

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

run			: re
			@$(RM) $(OBJS)
			@./$(NAME)

leaks		: re
			@$(RM) $(OBJS)
			valgrind --leak-check=full ./$(NAME)

runall		:
			cd ../ex00/; make run;
			cd ../ex01/; make run;
			cd ../ex02/; make run;			
			cd ../ex03/; make run;
			cd ../ex01/;

leaksall	:
<<<<<<< HEAD
			make leaks;
=======
>>>>>>> 3bf0f9260a7b8bdd9c5f7c2a2723d832354368b2
			cd ../ex00/; make leaks;
			cd ../ex01/; make leaks;
			cd ../ex02/; make leaks;			
			cd ../ex03/; make leaks;
			cd ../ex01/;

fcleanall	:
			cd ../ex00/; make fclean;
			cd ../ex01/; make fclean;
			cd ../ex02/; make fclean;			
			cd ../ex03/; make fclean;
			cd ../ex01/;
			
.PHONY		: all clean fclean re run leaks leaksall fcleanall runall
