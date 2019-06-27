FLAGS = -Wall -Wextra #-Werror
NAME = checker
RESOURCES = main.c ../src/*
OBJ = $(RESOURCES:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	@make -C ../libft/ all
	@gcc $(FLAGS) -o $(NAME) $(OBJ)  -I ../includes/ ../libft/libft.a
%.o: %.c
	gcc $(FLAGS) -I ../includes/ -c $< -o $@
clean:
	@rm -f *.o
	@rm -f ../src/*.o
	@make -C ../libft/ clean
fclean: clean
	@rm -f $(NAME)
	@make -C ../libft/ fclean
re: fclean all
