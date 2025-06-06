CC := cc
INCLUDES_DIR := includes
CFLAGS = -Wall -Wextra -Werror -g3 -I$(INCLUDES_DIR)

SRC := ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strnstr.c \
		ft_bzero.c \
		ft_memset.c \
		ft_memchr.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memcmp.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_atoi.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		get_next_line.c

F_PRINTF_SRC := ft_fprintf.c \
		ft_conversions.c \
		ft_extension.c \
		ft_put.c

SRCS := $(addprefix srcs/,$(SRC))
SRCS += $(addprefix srcs/ft_fprintf/,$(F_PRINTF_SRC))
HEADERS := $(INCLUDES_DIR)/libft.h

OBJS := $(addprefix objs/,$(SRC:.c=.o))
F_FPRINTF_OBJS := $(addprefix objs/ft_fprintf/,$(F_PRINTF_SRC:.c=.o))
NAME := libft.a

# Misc.
RED := '\033[0;31m'
GREEN := '\033[0;32m'
DFLT := '\033[0m'

.PHONY: all clean fclean re objs

all: $(NAME)

$(NAME): | objs objs/ft_fprintf $(OBJS) $(F_FPRINTF_OBJS)
	@if ar -rcs $@ $(OBJS) $(F_FPRINTF_OBJS); then \
		printf "\n$(GREEN)Compiled libft!$(DFLT)\n"; \
	else \
		printf "\n$(RED)Failed to compile libft.$(DFLT)\n"; \
	fi

objs:
	@mkdir -p objs

objs/ft_fprintf:
	@mkdir -p objs/ft_fprintf

objs/%.o: srcs/%.c  $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

objs/ft_fprintf/%.o: srcs/ft_fprintf/%.c  $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf objs objs/ft_fprintf

fclean: clean
	@rm -rf $(NAME)

re: fclean $(NAME)
