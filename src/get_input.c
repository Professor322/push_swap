/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:00:27 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/04 14:46:11 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		check_commands(char *argv)
{
	const char	*commands[11] = { "sa", "sb", "ss", "pa", "pb", "ra", "rb",
									"rr", "rra", "rrb", "rrr"};
	int			i;

	i = -1;
	while (++i < 11)
		if (!ft_strcmp(argv, commands[i]))
			return (i);
	return (-1);
}

static void		apply_command(t_data *a, t_data *b, int command_num,
		t_manager **checker)
{
	swaps(a, b, command_num, *checker);
	pushes(a, b, command_num, checker);
	rotations_up(a, b, command_num, *checker);
	rotations_down(a, b, command_num, *checker);
}

int				get_command(void *param)
{
	char	*command;
	int		command_num;

	command = NULL;
	if (get_next_line(0, &command))
	{
		command_num = check_commands(command);
		ft_memdel((void **)&command);
		if (command_num == -1)
		{
			(*((t_manager**)((void**)param)))->error = INPUT_ERROR;
			del_manager(param);
		}
		apply_command(A, B, command_num, ((t_manager**)((void**)param)));
		return (1);
	}
	return (0);
}

void			get_input(t_manager **checker)
{
	while (get_command((void**)checker))
		;
}
