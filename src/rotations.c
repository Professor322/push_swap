/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:37:03 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 19:37:03 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	smart_rotations(t_ivec *stack, char c, int elem, int output_flag)
{
	size_t i;

	i = -1;
	if ((size_t)elem < stack->length - elem)
	{
		while (++i < (size_t)elem && output_flag != ANALYSIS)
			rotate_up(stack, c == 'a' ? "ra" : "rb");
		return (elem);
	}
	else
	{
		while (++i < stack->length - elem && output_flag != ANALYSIS)
			rotate_down(stack, c == 'a' ? "rra" : "rrb");
		return (stack->length - elem);
	}
}