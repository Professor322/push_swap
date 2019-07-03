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

void	push_on_stack(t_data *a, t_data *b, int stack_to_push)
{
	if (!a || !b)
		return ;
	if (stack_to_push == PUSH_A)
	{
		if(!vis_push(a, b, NULL))
		{
			ft_int_vec_del(&a->val_vec);
			ft_int_vec_del(&b->val_vec);
			finish_him(MALLOC_ERROR);
		}
	}
	else if (stack_to_push == PUSH_B)
	{
		if (!vis_push(b, a, NULL))
		{
			ft_int_vec_del(&a->val_vec);
			ft_int_vec_del(&b->val_vec);
			finish_him(MALLOC_ERROR);
		}
	}
}

void	swap_stack_elems(t_data *a, t_data *b, int stack_to_swap)
{
	if (stack_to_swap == SWAP_A)
		vis_swap(a, NULL);
	else if (stack_to_swap == SWAP_B)
		vis_swap(b, NULL);
	else if (stack_to_swap == SWAP_BOTH)
	{
		vis_swap(a, NULL);
		vis_swap(b, NULL);
	}
}

void	rotate_elems(t_data *a, t_data *b, int stack_to_rotate)
{

	if (stack_to_rotate == ROTATE_A_UP)
		vis_rotate_up(a, NULL);
	else if (stack_to_rotate == ROTATE_B_UP)
		vis_rotate_up(b, NULL);
	else if (stack_to_rotate == ROTATE_BOTH_UP)
	{
		vis_rotate_up(a, NULL);
		vis_rotate_up(b, NULL);
	}
	else if (stack_to_rotate == ROTATE_A_DOWN)
		vis_rotate_down(a, NULL);
	else if (stack_to_rotate == ROTATE_B_DOWN)
		vis_rotate_down(b, NULL);
	else if (stack_to_rotate == ROTATE_BOTH_DOWN)
	{
		vis_rotate_down(a, NULL);
		vis_rotate_down(b, NULL);
	}
}