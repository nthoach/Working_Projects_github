# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 13:54:54 by honguyen          #+#    #+#              #
#    Updated: 2024/11/14 11:31:54 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex02
CC			= c++
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS_DIR 	= srcs
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.cpp")

OBJS		= $(SRCS:.cpp=.o)

INCS_DIR	= incl
INCS		= $(shell find $(INCS_DIR) -type f -name "*.hpp")

MAIN_INC	= -I$(INCS_DIR)

.cpp.o:
	${CC} ${CFLAGS} ${MAIN_INC} -c $< -o ${<:.cpp=.o}

all			: $(NAME)

$(NAME)		: $(OBJS) $(INCS)
	$(CC) $(OBJS) $(MAIN_INC) -o $(NAME)

clean		:
			@$(RM) $(OBJS)

fclean		: clean
			@$(RM) $(NAME)

re			: fclean all

run			: re
			@$(RM) $(OBJS)
			@./$(NAME)

.PHONY		: all clean fclean re