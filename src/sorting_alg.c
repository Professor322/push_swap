/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_alg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:21:07 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 19:21:07 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void 	sort_the_remainder(t_ivec *a)
{
	const int	min = find_min(a, INDEX);
	const int 	max = find_max(a, INDEX);

	if (max == 0)
		rotate_up(a, "ra");
	else if (min == 2 || (min == 0 && max == 1))
		rotate_down(a, "rra");
	if (a->data[0] > a->data[1] &&
			a->data[0] < a->data[2])
		swap(a, "sa");
}

static void		small_stack_sort(t_ivec *a)
{
	if (a->length == 2)
	{
		if (a->data[0] > a->data[1])
			swap(a, "sa");
	}
	else if (a->length == 3)
		sort_the_remainder(a);
}

void	sort(t_ivec **a, t_ivec **b)
{
	if ((*a)->length <= 3)
		small_stack_sort(*a);
	else if (!check_order(*a, *b, FINAL))
	{
		while ((*a)->length > 3)
		{
			if (check_order(*a, *b, A_ONLY))
				break;
			push(*b, *a, DO_OP, "pb");
		}
		if ((*a)->length == 3)
			sort_the_remainder(*a);
		merge(a, b);
	}
}
