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

void	push_on_stack(t_data *a, t_data *b, int stack_to_push, t_manager *checker)
{
	if (!a || !b)
		return ;
	if (stack_to_push == PUSH_A)
	{
		if(!vis_push(a, b, NULL, checker))
		{
			ft_int_vec_del(&a->val_vec);
			ft_int_vec_del(&b->val_vec);
			finish_him(MALLOC_ERROR);
		}
	}
	else if (stack_to_push == PUSH_B)
	{
		if (!vis_push(b, a, NULL, checker))
		{
			ft_int_vec_del(&a->val_vec);
			ft_int_vec_del(&b->val_vec);
			finish_him(MALLOC_ERROR);
		}
	}
}

void	swap_stack_elems(t_data *a, t_data *b, int stack_to_swap, t_manager *checker)
{
	if (stack_to_swap == SWAP_A)
		vis_swap(a, NULL, checker);
	else if (stack_to_swap == SWAP_B)
		vis_swap(b, NULL, checker);
	else if (stack_to_swap == SWAP_BOTH)
	{
		vis_swap(a, NULL, checker);
		vis_swap(b, NULL, checker);
	}
}

void	rotate_elems(t_data *a, t_data *b, int stack_to_rotate, t_manager *checker)
{

	if (stack_to_rotate == ROTATE_A_UP)
		vis_rotate_up(a, NULL, checker);
	else if (stack_to_rotate == ROTATE_B_UP)
		vis_rotate_up(b, NULL, checker);
	else if (stack_to_rotate == ROTATE_BOTH_UP)
	{
		vis_rotate_up(a, NULL, checker);
		vis_rotate_up(b, NULL, checker);
	}
	else if (stack_to_rotate == ROTATE_A_DOWN)
		vis_rotate_down(a, NULL, checker);
	else if (stack_to_rotate == ROTATE_B_DOWN)
		vis_rotate_down(b, NULL, checker);
	else if (stack_to_rotate == ROTATE_BOTH_DOWN)
	{
		vis_rotate_down(a, NULL, checker);
		vis_rotate_down(b, NULL, checker);
	}
}