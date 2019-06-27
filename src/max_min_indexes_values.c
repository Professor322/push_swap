/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:23:21 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 19:23:21 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	find_min(t_ivec *stack, int flag)
{
	int i;
	int min;
	int index;

	if (!stack->length)
		return (-1);
	min = stack->data[0];
	index = 0;
	i = 0;
	while ((size_t)++i < stack->length)
		if (stack->data[i] < min)
		{
			min = stack->data[i];
			index = i;
		}
	return (flag == VALUE ? min : index);
}

int 	find_max(t_ivec *stack, int flag)
{
	int i;
	int max;
	int index;

	if (!stack->length)
		return (-1);
	max = stack->data[0];
	index = 0;
	i = 0;
	while ((size_t)++i < stack->length)
		if (stack->data[i] > max)
		{
			max = stack->data[i];
			index = i;
		}
	return (flag == VALUE ? max : index);
}

int		find_index(t_ivec *stack, int value)
{
	int i;

	i = -1;
	while ((size_t)++i < stack->length)
		if (stack->data[i] == value)
			return (i);
	return (-1);
}