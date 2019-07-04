/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_and_debug.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:24:56 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 17:24:56 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	debug_info(t_data *a, t_data *b, char *s)
{
	ft_printf("\n________________________________");
	ft_printf("\n|{BLUE}%s{GREY}|\n", s);
	print_stack(a->val_vec, b->val_vec);
}

void			swaps(t_data *a, t_data *b, int command_num,
		t_manager *checker)
{
	if (command_num == SWAP_A)
	{
		swap_stack_elems(a, b, command_num, checker);
		if (checker->debug)
			debug_info(a, b, "swap a");
	}
	else if (command_num == SWAP_B)
	{
		swap_stack_elems(a, b, command_num, checker);
		if (checker->debug)
			debug_info(a, b, "swap b");
	}
	else if (command_num == SWAP_BOTH)
	{
		swap_stack_elems(a, b, command_num, checker);
		if (checker->debug)
			debug_info(a, b, "swap both");
	}
}

void			pushes(t_data *a, t_data *b, int command_num,
		t_manager **checker)
{
	if (command_num == PUSH_A)
	{
		push_on_stack(a, b, command_num, checker);
		if ((*checker)->debug)
			debug_info(a, b, "push a");
	}
	else if (command_num == PUSH_B)
	{
		push_on_stack(a, b, command_num, checker);
		if ((*checker)->debug)
			debug_info(a, b, "push b");
	}
}

void			rotations_up(t_data *a, t_data *b, int command_num,
		t_manager *checker)
{
	if (command_num == ROTATE_A_UP)
	{
		rotate_elems(a, b, command_num, checker);
		if (checker->debug)
			debug_info(a, b, "rotate a up");
	}
	else if (command_num == ROTATE_B_UP)
	{
		rotate_elems(a, b, command_num, checker);
		if (checker->debug)
			debug_info(a, b, "rotate b up");
	}
	else if (command_num == ROTATE_BOTH_UP)
	{
		rotate_elems(a, b, command_num, checker);
		if (checker->debug)
			debug_info(a, b, "rotate both up");
	}
}

void			rotations_down(t_data *a, t_data *b, int command_num,
		t_manager *checker)
{
	if (command_num == ROTATE_A_DOWN)
	{
		rotate_elems(a, b, command_num, checker);
		if (checker->debug)
			debug_info(a, b, "rotate a down");
	}
	else if (command_num == ROTATE_B_DOWN)
	{
		rotate_elems(a, b, command_num, checker);
		if (checker->debug)
			debug_info(a, b, "rotate b down");
	}
	else if (command_num == ROTATE_BOTH_DOWN)
	{
		rotate_elems(a, b, command_num, checker);
		if (checker->debug)
			debug_info(a, b, "rotate both down");
	}
}
