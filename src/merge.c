/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 20:25:07 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 20:25:07 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_elem(t_ivec **a, t_ivec **b, int min, int elem_to_place)
{
	int i;
	int j;
	int actions_num;

	i = 1;
	while ((size_t)i < (*b)->length && i < min - 1)
	{
		if ((actions_num = calculate_and_place(a, b, (*b)->data[i], ANALYSIS)) < min)
		{
			min = actions_num;
			elem_to_place = (*b)->data[i];
		}
		i++;
	}
	if ((*b)->length > (size_t)min)
	{
		i = (*b)->length;
		j = -1;
		while (--i != 0 && ++j < min - 1)
			if ((actions_num = calculate_and_place(a, b, (*b)->data[i], ANALYSIS)) < min)
			{
				min = actions_num;
				elem_to_place = (*b)->data[i];
			}
	}
	return (elem_to_place);
}

void	merge(t_ivec **a, t_ivec **b)
{
	int 	elem_to_place;
	int min;

	while ((*b)->length)
	{
		elem_to_place = (*b)->data[0];
		min = calculate_and_place(a, b, elem_to_place, ANALYSIS);
		if (min == 1 || min == 2)
		{
			calculate_and_place(a, b, elem_to_place, DO_OP);
			continue;
		}
		calculate_and_place(a, b, find_elem(a, b, min, elem_to_place), DO_OP);
	}
	smart_rotations(*a, 'a', find_index(*a, find_min(*a, VALUE)), DO_OP);
}