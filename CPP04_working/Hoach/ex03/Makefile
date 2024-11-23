# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 13:54:54 by honguyen          #+#    #+#              #
#    Updated: 2024/11/23 15:06:12 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex03
CC			= c++
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS_DIR 	= srcs
SRCS		= $(addprefix $(SRCS_DIR)/, Animal.cpp Cat.cpp Dog.cpp Brain.cpp main.cpp)

OBJS_DIR	= objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.cpp=.o)))

INCS_DIR	= incl
INCS		= $(addprefix $(INCS_DIR)/, Animal.hpp Cat.hpp Dog.hpp Brain.hpp)

MAIN_INC	= -I$(INCS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	@echo "Creating directory: $(OBJS_DIR)"
	@mkdir -p $(OBJS_DIR) || echo "Failed to create directory: $(OBJS_DIR)"
	${CC} ${CFLAGS} ${MAIN_INC} -c $< -o $@

all			: $(NAME)

$(NAME)		: $(OBJS) $(INCS)
	$(CC) $(OBJS) $(MAIN_INC) -o $(NAME)

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
			cd ../ex03/;

leaksall	:
			cd ../ex00/; make leaks;
			cd ../ex01/; make leaks;
			cd ../ex02/; make leaks;			
			cd ../ex03/; make leaks;
			cd ../ex03/;

fcleanall	:
			cd ../ex00/; make fclean;
			cd ../ex01/; make fclean;
			cd ../ex02/; make fclean;			
			cd ../ex03/; make fclean;
			cd ../ex03/;
			
.PHONY		: all clean fclean re run leaks leaksall fcleanall runall
