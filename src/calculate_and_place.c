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
	actions = 0;
	if (elem < min || elem > max)
		actions = rotate_analysis(a, b,find_index(a, min), find_index(b, elem), flag);
	else
	{
		i = -1;
		while ((size_t)++i < a->length - 1)
		{
			if (elem > a->data[i] && elem < a->data[i + 1])
			{
				actions = rotate_analysis(a, b, i + 1, find_index(b, elem),
						flag);
				break;
			}
			if ((size_t)i + 2 == a->length)
				if(elem > a->data[i + 1] && elem < a->data[0])
					actions = rotate_analysis(a, b, 0, find_index(b, elem), flag);
		}
	}
	if (!(push(a, b, flag, flag == ANALYSIS ? NULL : "pa")))
	{
		//free memory
	}
	return (actions + 1);
}
