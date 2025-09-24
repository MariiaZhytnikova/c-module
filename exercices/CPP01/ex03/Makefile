NAME := Weapon

SRC := main.cpp HumanA.cpp HumanB.cpp Weapon.cpp

OBJ := $(SRC:.cpp=.o)

CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++11 -pedantic

HEADERS := -I.

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all