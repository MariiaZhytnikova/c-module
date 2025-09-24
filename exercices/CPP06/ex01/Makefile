NAME := Serializer

SRC := Serializer.cpp main.cpp
OBJ := $(SRC:.cpp=.o)
DEP := $(SRC:.cpp=.d)

CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++11 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re