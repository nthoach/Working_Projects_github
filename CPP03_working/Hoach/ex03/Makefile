# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 13:54:54 by honguyen          #+#    #+#              #
#    Updated: 2024/11/22 13:01:48 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex03
CC			= c++
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow

SRCS_DIR 	= srcs
SRCS		= $(addprefix $(SRCS_DIR)/, ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp main.cpp)

OBJS_DIR	= objs
OBJS		= $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.cpp=.o)))

INCS_DIR	= incl
INCS		= $(addprefix $(INCS_DIR)/, ScavTrap.hpp ClapTrap.hpp FragTrap.hpp DiamondTrap.hpp)

MAIN_INC	= -I$(INCS_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.cpp
	mkdir -p $(OBJS_DIR)
	${CC} ${CFLAGS} ${MAIN_INC} -c $< -o $@

all			: $(NAME)

$(NAME)		: $(OBJS) $(INCS)
	$(CC) $(OBJS) ${CFLAGS} $(MAIN_INC) -o $(NAME)

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

.PHONY		: all clean fclean re
