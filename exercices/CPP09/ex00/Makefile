NAME := btc

SRC := main.cpp BitcoinExchange.cpp
OBJPATH := ./obj

OBJ := $(SRC:%.cpp=$(OBJPATH)/%.o)
DEP := $(SRC:%.cpp=$(OBJPATH)/%.d)

CC := c++

CFLAGS := -Wall -Wextra -Werror -std=c++20 -pedantic

all: $(NAME)

$(NAME): $(OBJ) $(OBJPATH)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJPATH):
	@mkdir $(OBJPATH)

$(OBJPATH)/%.o: %.cpp | $(OBJPATH)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEP)

clean:
	rm -rf $(OBJPATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re