# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 09:10:57 by honguyen          #+#    #+#              #
#    Updated: 2024/11/11 16:09:57 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	ex02

SRCS		=	tests.cpp Account.cpp
HEADERS		=   Account.hpp

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

OBJS		=	$(SRCS:.cpp=.o)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo '$(NAME) compiled!'

fclean		: clean
	$(RM) $(NAME)

clean		:
	$(RM) $(OBJS)

re			:	fclean all

run			: re clean
	./$(NAME)

.PHONY		:	all clean fclean re