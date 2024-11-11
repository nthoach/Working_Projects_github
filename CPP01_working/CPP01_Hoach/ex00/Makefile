# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 13:54:54 by honguyen          #+#    #+#              #
#    Updated: 2024/11/11 16:37:33 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex00
CC			= c++
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS_DIR 	= srcs
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.cpp")

OBJS		= $(SRCS:.cpp=.o)

INCS_DIR	= incl
INCS		= $(shell find $(INCS_DIR) -type f -name "*.hpp")

MAIN_INC	= -I$(INCS_DIR)

CYAN 		= \033[1;36m
END			= \033[0m
CLEAR    	= \033[2K

.cpp.o:
	@printf "$(CLEAR)$(CYAN)Compiling: $<$(END)\r"
	${CC} ${CFLAGS} ${MAIN_INC} -c $< -o ${<:.cpp=.o}

all			: $(NAME)

$(NAME)		: $(OBJS) $(INCS)
	$(CC) ${CFLAGS} $(OBJS) $(MAIN_INC) -o $(NAME)
	@echo "${NAME} compiled"

clean		:
			@$(RM) $(OBJS)

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

run			: re
			@$(RM) $(OBJS)
			@./$(NAME)
			

.PHONY		: all clean fclean re