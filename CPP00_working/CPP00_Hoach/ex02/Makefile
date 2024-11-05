# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: honguyen <honguyen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 09:10:57 by honguyen          #+#    #+#              #
#    Updated: 2024/11/05 18:46:17 by honguyen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	tests

SRCS		=	tests.cpp Account.cpp
HEADERS		=   Account.hpp

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

OBJS		=	$(SRCS:.cpp=.o)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)
	@echo '$(NAME) compiled!'

fclean		: clean
	$(RM) $(NAME)

clean		:
	$(RM) $(OBJS)

re			:	fclean all

.PHONY		:	all clean fclean re