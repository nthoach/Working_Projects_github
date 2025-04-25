CC = c++ -Wall -Werror -Wextra -Wshadow -std=c++98
SRC = $(wildcard *.cpp)

all:
	$(CC) $(SRC)

leak:
	valgrind --leak-check=full ./a.out

fclean:
	rm -f ./a.out

re: fclean all 

.PHONY: all leak fclean re