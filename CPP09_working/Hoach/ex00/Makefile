# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 13:54:54 by honguyen          #+#    #+#              #
#    Updated: 2025/05/01 21:30:40 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= btc
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98
RM			= rm -f

SRCS_DIR 	= srcs
SRCS		= $(addprefix $(SRCS_DIR)/, BitcoinExchange.cpp main.cpp)

OBJS_DIR	= objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.cpp=.o)))

INCS_DIR	= incl
INCS		= $(addprefix $(INCS_DIR)/, BitcoinExchange.hpp)

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
			@./$(NAME) ./input.txt
leaks		: re
			@$(RM) $(OBJS)
			valgrind --leak-check=full ./$(NAME)

runall		:
			make run;
			cd ../ex01/; make run;
			cd ../ex02/; make run;			
			cd ../ex00/;

leaksall	:
			make leaks;
			cd ../ex01/; make leaks;
			cd ../ex02/; make leaks;			
			cd ../ex00/;

fcleanall	:
			make fclean;
			cd ../ex01/; make fclean;
			cd ../ex02/; make fclean;			
			cd ../ex00/;
			
.PHONY		: all clean fclean re run leaks leaksall fcleanall runall
