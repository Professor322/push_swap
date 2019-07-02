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

void	swaps(t_data *a, t_data *b, int command_num, t_mlx *mlx)
{
	if (command_num == SWAP_A)
	{
		swap_stack_elems(a, b, command_num, mlx);
		if (DEBUG)
		{
			printf("\nswap a\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == SWAP_B)
	{
		swap_stack_elems(a, b, command_num, mlx);
		if (DEBUG)
		{
			printf("\nswap b\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == SWAP_BOTH)
	{
		swap_stack_elems(a, b, command_num, mlx);
		if (DEBUG)
		{
			printf("\nswap both\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
}

void	pushes(t_data *a, t_data *b, int command_num, t_mlx *mlx)
{
	if (command_num == PUSH_A)
	{
		push_on_stack(a, b, command_num, mlx);
		if (DEBUG)
		{
			printf("\npush a\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == PUSH_B)
	{
		push_on_stack(a, b, command_num, mlx);
		if (DEBUG)
		{
			printf("\npush b\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
}

void	rotations_up(t_data *a, t_data *b, int command_num, t_mlx *mlx)
{
	if (command_num == ROTATE_A_UP)
	{
		rotate_elems(a, b, command_num, mlx);
		if (DEBUG)
		{
			printf("\nrotate a up\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == ROTATE_B_UP)
	{
		rotate_elems(a, b, command_num, mlx);
		if (DEBUG)
		{
			printf("\nrotate b up\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == ROTATE_BOTH_UP)
	{
		rotate_elems(a, b, command_num, mlx);
		if (DEBUG)
		{
			printf("\nrotate both up\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
}

void	rotations_down(t_data *a, t_data *b, int command_num, t_mlx *mlx)
{
	if (command_num == ROTATE_A_DOWN)
	{
		rotate_elems(a, b, command_num, mlx);
		if (DEBUG)
		{
			printf("\nrotate a down\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == ROTATE_B_DOWN)
	{
		rotate_elems(a, b, command_num, mlx);
		if (DEBUG)
		{
			printf("\nrotate b down\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
	else if (command_num == ROTATE_BOTH_DOWN)
	{
		rotate_elems(a, b, command_num, mlx);
		if (DEBUG)
		{
			printf("\nrotate both down\n");
			print_stack(a->val_vec, b->val_vec);
		}
	}
}