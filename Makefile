CC = c++

CFLAGS = -g3 -std=c++98 -Wall -Wextra -Werror -MMD -O0 -D STD
# CFLAGS = -g3 -MMD

FILES = main.cpp

OBJS = $(FILES:.cpp=.o)

NAME = containers

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

std: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f main.d

fclean: clean
	rm -f $(NAME)
	rm -f bench

re: fclean all

bench:
	$(CC) benchmark98.cpp -march=native -Wall -Wextra -Werror -std=c++98 -g3 -o bench -Ofast

.PHONY: all clean fclean re bench

-include $(FILES:%.cpp=%.d)