# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 20:32:25 by seozkan           #+#    #+#              #
#    Updated: 2023/05/23 22:47:42 by seozkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= megaphone
CC			= g++
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror -std=c++98

SRC			=	megaphone.cpp
OBJ			=	$(SRC:.cpp=.o)

CYAN 		= \033[1;36m
END			= \033[0m
CLEAR   	= \033[2K

.cpp.o:
	@printf "$(CLEAR)$(CYAN)Compiling: $<$(END)\r"
	@ ${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all: $(NAME)

$(NAME): $(OBJ)
	@ $(CC) -o $(NAME) $(OBJ)
	@echo "\n${NAME} compiled"

clean:
	@ ${RM} $(OBJ)

fclean: clean
	@ ${RM} $(NAME)

re: fclean all

.PHONY: all clean fclean re
