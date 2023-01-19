CC = c++

CFLAGS = -g3 -std=c++98 -Wall -Wextra -Werror -MMD -Ofast

FILES = main.cpp

OBJS = $(FILES:.cpp=.o)

NAME = containers

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

-include $(FILES:%.cpp=%.d)