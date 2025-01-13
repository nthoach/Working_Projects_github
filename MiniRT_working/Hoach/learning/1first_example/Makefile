CC = gcc
CFLAGS = #-Wall -Wextra -Werror
LDFLAGS = -L../mlx -lmlx -lX11 -lXext -lm

SRC = main.c
OBJ = $(SRC:.c=.o)
EXEC = a.out

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
