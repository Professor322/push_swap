/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:00:27 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 17:00:27 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_commands(char *argv)
{
	const char *commands[11] = { "sa", "sb", "ss", "pa", "pb", "ra", "rb",
								 "rr", "rra", "rrb", "rrr"};
	int i;

	i = -1;
	while (++i < 11)
		if (!ft_strcmp(argv, commands[i]))
			return (i);
	return (-1);
}

static void		apply_command(t_data *a, t_data *b, int command_num,
		t_manager *checker)
{
	swaps(a, b, command_num, checker);
	pushes(a, b, command_num, checker);
	rotations_up(a, b, command_num, checker);
	rotations_down(a, b, command_num, checker);
}

void	delay(int number_of_seconds)
{
	const int milli_seconds = 50000 * number_of_seconds;

	clock_t start_time = clock();

	while (clock() < start_time + milli_seconds)
		;
}

int		visualize(void *param)
{
	static int counter = 0;

	if (!PAUSE)
	{
		delay(SPEED);
		mlx_clear_window(MLX_PTR, WIN_PTR);
		if (!get_command(param))
		{
			rainbow(A_IMG);
			display_stack(*((void **)param), A_IMG, A->stack);
			mlx_string_put(MLX_PTR, WIN_PTR, C_WIDTH - 100, C_HEIGHT - 50,
					P_GREEN, ft_itoa(counter));
			return (1);
		}
		else
		{
			change_color(A_IMG, 0, A_IMG->length, COLOR_A);
			display_stack(*((void **)param), A_IMG, A->stack);
			change_color(B_IMG, 0, B_IMG->length, COLOR_B);
			display_stack(*((void **)param), B_IMG, B->stack);
			mlx_string_put(MLX_PTR, WIN_PTR, C_WIDTH - 100, C_HEIGHT - 50,
					P_RED, ft_itoa(++counter));
		}
	}
	return (0);
}

int get_command(void *param)
{
	char *command;
	int	command_num;

	command = NULL;
	if (get_next_line(0, &command))
	{
		command_num = check_commands(command);
		ft_printf("%s\n", command);
		ft_memdel((void **)&command);
		if (command_num == -1)
		{
			(*((t_manager**)((void**)param)))->error = INPUT_ERROR;
			del_manager(param);
		}
		apply_command(A, B, command_num, *((t_manager**)((void**)param)));
		return (1);
	}
	return (0);
}

void	get_input(t_manager **checker)
{
	while (get_command((void**)checker))
		;

}
