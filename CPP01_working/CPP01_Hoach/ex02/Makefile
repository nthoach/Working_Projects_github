# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/10 13:54:54 by honguyen          #+#    #+#              #
#    Updated: 2024/11/10 17:08:43 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ex02
CC			= c++
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRCS_DIR 	= .
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.cpp")

OBJS		= $(SRCS:.cpp=.o)

INCS_DIR	= .
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

.PHONY		: all clean fclean re