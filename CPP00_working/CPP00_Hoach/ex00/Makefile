# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/03 09:10:57 by honguyen          #+#    #+#              #
#    Updated: 2024/11/11 15:35:26 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	ex00

SRCS		=	megaphone.cpp

CC			=	c++
CFLAGS		=	-Wall -Wextra -Werror -std=c++98

RM			=	rm -f

OBJS		=	$(SRCS:.cpp=.o)

%.o: %.cpp
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
	./$(NAME) "This is OK " " ..."

.PHONY		:	all clean fclean re