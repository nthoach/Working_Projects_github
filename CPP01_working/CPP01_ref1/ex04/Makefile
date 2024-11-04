# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seozkan <seozkan@student.42kocaeli.com.tr> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 08:58:20 by seozkan           #+#    #+#              #
#    Updated: 2023/05/29 11:46:41 by seozkan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= sed
CC			= g++
RM			= rm -rf
CFLAGS		=  -std=c++98

SRCS_DIR 	= .
SRCS		= $(shell find $(SRCS_DIR) -type f -name "*.cpp")

OBJS		= $(SRCS:.cpp=.o)

CYAN 		= \033[1;36m
END			= \033[0m
CLEAR    	= \033[2K

.cpp.o:
	@printf "$(CLEAR)$(CYAN)Compiling: $<$(END)\r"
	@ ${CC} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all			: $(NAME)

$(NAME)		: $(OBJS)
			@$(CC) $(OBJS) -o $(NAME)
			@echo "\n${NAME} compiled"

clean		:
			@$(RM) $(OBJS)

fclean		: clean
			@$(RM) $(NAME) *.replace

re			: fclean all

.PHONY		: all clean fclean re