CC = c++

CFLAGS = -g3 -std=c++98 -Wall -Wextra -Werror -MMD -O0
# CFLAGS = -g3 -MMD

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

bench:
	$(CC) benchmark98.cpp -march=native -g3 -o bench -std=c++98 -O3

.PHONY: all clean fclean re bench

-include $(FILES:%.cpp=%.d)