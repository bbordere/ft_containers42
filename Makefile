NAME = ft_containers
STD_NAME = std_containers

CXX = c++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -g3 -MMD

OBJ_DIR = obj/
STD_OBJ_DIR = std_obj/

SRCS_DIR = srcs/
INC_DIR = includes/

FILES = $(SRCS_DIR)main.cpp $(SRCS_DIR)mainMap.cpp $(SRCS_DIR)mainSet.cpp $(SRCS_DIR)mainVector.cpp $(SRCS_DIR)mainStack.cpp
OBJS = $(patsubst $(SRCS_DIR)%.cpp, $(OBJ_DIR)%.o, $(FILES))
STD_OBJS = $(patsubst $(SRCS_DIR)%.cpp, $(STD_OBJ_DIR)%.o, $(FILES))

DEPS = $(OBJS:.o=.d)
STD_DEPS = $(STD_OBJS:.o=.d)

$(OBJ_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@ printf "$(YELLOW)Compiling: " $@ $(RESET)
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) -c $< -o $@

$(STD_OBJ_DIR)%.o: $(SRCS_DIR)%.cpp
	@mkdir -p $(STD_OBJ_DIR)
	@ printf "$(YELLOW)Compiling: " $@ $(RESET)
	$(CXX) $(CXXFLAGS) -D NP=std -I $(INC_DIR) -c $< -o $@

BLUE = \033[34m
RESET = \033[0m
GREEN =	\033[32m
YELLOW = \033[33m

all: $(NAME) $(STD_NAME)
	@ printf "$(BLUE)    ____________   __________  _   ___________    _____   ____________  _____ $(RESET) \n"
	@ printf "$(BLUE)   / ____/_  __/  / ____/ __ \/ | / /_  __/   |  /  _/ | / / ____/ __ \/ ___/ $(RESET) \n"
	@ printf "$(BLUE)  / /_    / /    / /   / / / /  |/ / / / / /| |  / //  |/ / __/ / /_/ /\__ \  $(RESET) \n"
	@ printf "$(BLUE) / __/   / /    / /___/ /_/ / /|  / / / / ___ |_/ // /|  / /___/ _, _/___/ /  $(RESET) \n"
	@ printf "$(BLUE)/_/     /_/     \____/\____/_/ |_/ /_/ /_/  |_/___/_/ |_/_____/_/ |_|/____/   $(RESET) \n"
                                                                             


$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -I $(INC_DIR) $(OBJS) -o $@

$(STD_NAME): $(STD_OBJS)
	$(CXX) $(CXXFLAGS) -D NP=std -I $(INC_DIR) $(STD_OBJS) -o $@

clean:
	@ rm -rf $(OBJ_DIR)
	@ rm -rf $(STD_OBJ_DIR)
	@ printf "$(GREEN)clean done ! $(RESET)\n"

fclean: clean
	@ rm -rf $(NAME)
	@ rm -rf $(STD_NAME)
	@ printf "$(GREEN)fclean done ! $(RESET)\n"

re: fclean all

.PHONY: re clean fclean all

-include $(DEPS) $(STD_DEPS)