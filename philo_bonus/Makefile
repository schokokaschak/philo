NAME = philo_bonus

SRC = src/ft_atoi.c src/init.c src/main.c src/threads.c src/utils.c src/routine.c
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -pthread -g
RM = rm -rf

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[0;35m••••\033[0m\c"
	@echo "\033[0;35m••••\033[0m\c"
	@echo "\033[0;35m••••\033[0m\c"

$(NAME): $(OBJ) $(SRC)
		@$(CC) $(OBJ) -o $(NAME)
	@echo "\n\033[0;35m✨Philosophers successfully compiled!✨"
clean:
	@$(RM) $(OBJ)
	@echo "\033[0;34m✨Philosophers successfully cleaned!✨\033[0m"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean art re
