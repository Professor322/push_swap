FLAGS = -Wall -Wextra  #-Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = checker
RESOURCES = main.c ../src/*
OBJ = $(RESOURCES:.c=.o)
all: $(NAME)
$(NAME): $(OBJ)
	@make -C ../libft/ all
	@gcc $(FLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJ)  -I ../includes/ ../libft/libft.a
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
