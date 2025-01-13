# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 13:54:54 by honguyen          #+#    #+#              #
#    Updated: 2024/12/05 15:37:18 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= miniRT
CC			= c
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

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

.PHONY		: all clean fclean re run leaks leaksall fcleanall runall
