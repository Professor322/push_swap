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

void	swaps(t_data *a, t_data *b, int command_num, t_manager *checker)
{
	if (command_num == SWAP_A)
	{
		swap_stack_elems(a, b, command_num, checker);
		if (checker->debug)
		{
			ft_printf("\n________________________________");
			ft_printf("\n|{BLUE}swap a{GREY}|\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == SWAP_B)
	{
		swap_stack_elems(a, b, command_num, checker);
		if (checker->debug)
		{
			ft_printf("\n________________________________");
			ft_printf("\n|{BLUE}swap b{GREY}|\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == SWAP_BOTH)
	{
		swap_stack_elems(a, b, command_num, checker);
		if (checker->debug)
		{
			ft_printf("\n________________________________");
			ft_printf("\n|{BLUE}swap both{GREY}|\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
}

void	pushes(t_data *a, t_data *b, int command_num, t_manager *checker)
{
	if (command_num == PUSH_A)
	{
		push_on_stack(a, b, command_num, checker);
		if (checker->debug)
		{
			ft_printf("\n________________________________");
			ft_printf("\n|{BLUE}push a{GREY}|\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == PUSH_B)
	{
		push_on_stack(a, b, command_num, checker);
		if (checker->debug)
		{
			ft_printf("\n________________________________");
			ft_printf("\n|{BLUE}push b{GREY}|\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
}

void	rotations_up(t_data *a, t_data *b, int command_num, t_manager *checker)
{
	if (command_num == ROTATE_A_UP)
	{
		rotate_elems(a, b, command_num, checker);
		if (checker->debug)
		{
			ft_printf("\n________________________________");
			ft_printf("\n|{BLUE}rotate a up{GREY}|\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == ROTATE_B_UP)
	{
		rotate_elems(a, b, command_num, checker);
		if (checker->debug)
		{
			ft_printf("\n________________________________");
			ft_printf("\n|{BLUE}rotate b up{GREY}|\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == ROTATE_BOTH_UP)
	{
		rotate_elems(a, b, command_num, checker);
		if (checker->debug)
		{
			ft_printf("\n________________________________");
			ft_printf("\n|{BLUE}rotate both up{GREY}|\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
}

void	rotations_down(t_data *a, t_data *b, int command_num, t_manager *checker)
{
	if (command_num == ROTATE_A_DOWN)
	{
		rotate_elems(a, b, command_num, checker);
		if (checker->debug)
		{
			ft_printf("\n________________________________");
			ft_printf("\n|{BLUE}rotate a down{GREY}|\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == ROTATE_B_DOWN)
	{
		rotate_elems(a, b, command_num, checker);
		if (checker->debug)
		{
			ft_printf("\n________________________________");
			ft_printf("\n|{BLUE}rotate b down{GREY}|\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == ROTATE_BOTH_DOWN)
	{
		rotate_elems(a, b, command_num, checker);
		if (checker->debug)
		{
			ft_printf("\n________________________________");
			ft_printf("\n|{BLUE}rotate both down{GREY}|\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
}