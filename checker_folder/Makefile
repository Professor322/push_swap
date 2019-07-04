COMPILER = gcc
CHECK_FLAGS = -Wall -Wextra -Werror
COMPILE_FLAGS =  -lmlx -framework OpenGL -framework AppKit
NAME = checker
ADD_SRC = ../src/
RESOURCES = apply_and_debug.c \
atoi_move.c \
checker_operations.c \
deletion.c \
init.c \
visualisation1.c \
apply_action.c \
args_check.c \
create_stack.c \
get_input.c \
print_stack.c \
rearrange_elems.c \
visualisation2.c \
finish_him.c \
check_options.c
SRC_S = main.c $(addprefix $(ADD_SRC), $(RESOURCES))
OBJ = $(SRC_S:.c=.o)
ADD_INC = ../includes/
ADD_LIB_H = ../libft/
ADD_LIBFT = ../libft/libft.a
ADD_MLX = ../minilibx_macos

all: $(NAME)

$(NAME):  $(OBJ)
	@make  -C ../libft all
	@$(COMPILER) -o $(NAME) $(CHECK_FLAGS) $(COMPILE_FLAGS) $(OBJ) $(ADD_LIBFT) -L $(ADD_MLX)
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

