/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_actions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:56:45 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 19:56:45 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t 	calculate_and_place(t_ivec *a, t_ivec *b, int elem, int flag)
{
	size_t		actions;
	int 		min;
	int 		max;
	int 		i;

	max = find_max(a, VALUE);
	min = find_min(a, VALUE);
	actions = smart_rotations(b, 'b', find_index(b, elem), flag);
	if (elem < min || elem > max)
	{
		actions += smart_rotations(a, 'a', find_index(a, min), flag);
	}
	else
	{
		i = -1;
		while ((size_t)++i < a->length - 1)
		{
			if (elem > a->data[i] && elem < a->data[i + 1])
			{
				actions += smart_rotations(a, 'a', i + 1, flag);
				break;
			}
			/*if ((size_t)i + 2 == a->length)
			{
				if (elem > a->data[i] && elem < a->data[0])
					actions += smart_rotations(a, 'a', 0, ANALYSIS);
			}*/
		}
	}
	if (!(push(a, b, flag, flag == ANALYSIS ? NULL : "pa")))
	{
		//free memory
	}
	return (actions + 1);
}
