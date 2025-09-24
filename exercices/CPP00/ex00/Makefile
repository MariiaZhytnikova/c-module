NAME := Megaphone
SRC := megaphone.cpp
OBJ := megaphone.o
CC := c++ -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(SRC) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ):
	$(CC) $(SRC) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re