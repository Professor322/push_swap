/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:03:37 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 17:03:37 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_on_stack(t_ivec **a, t_ivec **b, int stack_to_push)
{
	if (!a || !b)
		return ;
	if (stack_to_push == PUSH_A)
	{
		if(!push(*a, *b, NULL))
		{
			ft_int_vec_del(a);
			ft_int_vec_del(b);
			finish_him(MALLOC_ERROR);
		}
	}
	else if (stack_to_push == PUSH_B)
	{
		if (!push(*b, *a, NULL))
		{
			ft_int_vec_del(a);
			ft_int_vec_del(b);
			finish_him(MALLOC_ERROR);
		}
	}
}

void	swap_stack_elems(t_ivec *a, t_ivec *b, int stack_to_swap)
{
	if (stack_to_swap == SWAP_A)
		swap(a, NULL);
	else if (stack_to_swap == SWAP_B)
		swap(b, NULL);
	else if (stack_to_swap == SWAP_BOTH)
	{
		swap(a, NULL);
		swap(b, NULL);
	}
}

void	rotate_elems(t_ivec *a, t_ivec *b, int stack_to_rotate)
{

	if (stack_to_rotate == ROTATE_A_UP)
		rotate_up(a, NULL);
	else if (stack_to_rotate == ROTATE_B_UP)
		rotate_up(b, NULL);
	else if (stack_to_rotate == ROTATE_BOTH_UP)
	{
		rotate_up(a, NULL);
		rotate_up(b, NULL);
	}
	else if (stack_to_rotate == ROTATE_A_DOWN)
		rotate_down(a, NULL);
	else if (stack_to_rotate == ROTATE_B_DOWN)
		rotate_down(b, NULL);
	else if (stack_to_rotate == ROTATE_BOTH_DOWN)
	{
		rotate_down(a, NULL);
		rotate_down(b, NULL);
	}
}