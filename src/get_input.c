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

static void		apply_command(t_data *a, t_data *b, int command_num, t_mlx *mlx)
{
	swaps(a, b, command_num, mlx);
	pushes(a, b, command_num, mlx);
	rotations_up(a, b, command_num, mlx);
	rotations_down(a, b, command_num, mlx);
}

int viz_stack(void * param)
{
	static int counter = 0;

	mlx_clear_window(((t_mlx*)param)->mlx_ptr, ((t_mlx*)param)->win_ptr);
	if (!gc(param))
	{
		rainbow(A_IMG);
		display_stack(param, A_IMG, ((t_mlx *)param)->a.stack);
		mlx_string_put(((t_mlx *)param)->mlx_ptr,  ((t_mlx *)param)->win_ptr,  ((t_mlx *)param)->width - 100,  ((t_mlx *)param)->height - 100, 0xFFFFFF, ft_itoa(counter));
	}
	else
	{
		change_color(A_IMG,0 ,A_IMG->length, ((t_mlx *)param)->color_a);
		display_stack(param, A_IMG, ((t_mlx *)param)->a.stack);
		change_color(B_IMG, 0,B_IMG->length, ((t_mlx *)param)->color_b);
		display_stack(param, B_IMG, ((t_mlx *)param)->b.stack);
		mlx_string_put(((t_mlx *)param)->mlx_ptr,  ((t_mlx *)param)->win_ptr,  ((t_mlx *)param)->width - 100, ((t_mlx *)param)->width - 50 , 0xFFFFFF, ft_itoa(++counter));
	}
}

int gc(void *param)
{
	char *command;
	int	command_num;

	command = NULL;
	if (get_next_line(0, &command))
	{
		command_num = check_commands(command);
		ft_memdel((void **)&command);
		if (command_num == -1)
		{
			ft_int_vec_del(&A_VAL);
			ft_int_vec_del(&B_VAL);
			finish_him(INPUT_ERROR);
		}
		apply_command(&A, &B, command_num, (t_mlx*)param);
		return (1);
	}
	return (0);
}

void	get_input(t_mlx *mlx)
{
	while (gc(mlx))
		;

}
