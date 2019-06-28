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

static void		apply_command(t_ivec **a, t_ivec **b, int command_num)
{
	swaps(*a, *b, command_num);
	pushes(a, b, command_num);
	rotations_up(*a, *b, command_num);
	rotations_down(*a, *b, command_num);
}

void	get_input(t_ivec **a, t_ivec **b)
{
	char *command;
	int	command_num;

	command = NULL;
	ft_printf("before %s", command);
	while (get_next_line(0, &command))
	{
		ft_printf("%s\n", command);
		command_num = check_commands(command);
		ft_memdel((void**)&command);
		if (command_num == -1)
		{
			ft_int_vec_del(a);
			ft_int_vec_del(b);
			finish_him(INPUT_ERROR);
		}
		apply_command(a, b, command_num);
	}

}
