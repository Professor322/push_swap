COMPILER = gcc
CHECK_FLAGS = -Wall -Wextra -Werror
NAME = push_swap
ADD_SRC = ../src/
RESOURCES = analysis.c \
atoi_move.c \
push_swap_operations.c \
args_check.c \
create_stack.c \
calculate_and_place.c \
max_min_indexes_values.c \
merge.c \
rotations.c \
sorting_alg.c \
print_stack.c \
finish_him.c
SRC_S = main.c $(addprefix $(ADD_SRC), $(RESOURCES))
OBJ = $(SRC_S:.c=.o)
ADD_INC = ../includes/
ADD_LIB_H = ../libft/
ADD_LIBFT = ../libft/libft.a
ADD_MLX = ../minilibx_macos

all: $(NAME)

$(NAME):  $(OBJ)
	@make  -C ../libft all
	@$(COMPILER) -o $(NAME) $(CHECK_FLAGS) $(OBJ) $(ADD_LIBFT) -L $(ADD_MLX)
	@echo ======[Done]======
	@mv $(NAME) ../
%.o : %.c
	@echo "$(NAME) >>> Add/Update $<"
	@$(COMPILER) -c -o $@ -I $(ADD_INC) $(CHECK_FLAGS) $<
clean:
	@rm -f *.o
	@rm -f $(ADD_SRC)$(OBJ)
	@make  -C ../libft clean
fclean: clean
	@rm -f ../$(NAME)
	@make -C ../libft fclean
re: fclean all
