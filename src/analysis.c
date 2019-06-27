/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analysis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:37:14 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 19:37:14 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_ivec *a, t_ivec *b, int (*rotate)(t_ivec*, char*),
		char *action)
{
	rotate(a, NULL);
	rotate(b, NULL);
	if (action)
		ft_printf("%s\n", action);
}

static int 	first_case(t_ivec *a, t_ivec *b, int elem_a, int elem_b, int quiet)
{
	int i;

	i = 0;
	if (elem_a > elem_b)
	{
		while (i < elem_b && quiet != ANALYSIS)
		{
			rotate_both(a, b, rotate_up,"rr");
			i++;
		}
		while (i++ < elem_a && quiet != ANALYSIS)
			rotate_up(a, "ra");
		return (elem_a);
	}
	else
	{
		while (i < elem_a && quiet != ANALYSIS)
		{
			rotate_both(a, b, rotate_up, "rr");
			i++;
		}
		while (i++ < elem_b && quiet != ANALYSIS)
			rotate_up(b, "rb");
		return (elem_b);
	}
}

static int 		second_case(t_ivec *a, t_ivec *b, int elem_a, int elem_b, int quiet)
{
	int i;

	i = 0;
	if (a->length - elem_a > b->length - elem_b)
	{
		while ((size_t)i < b->length - elem_b && quiet != ANALYSIS)
		{
			rotate_both(a, b, rotate_down,"rrr");
			i++;
		}
		while ((size_t)i++ < a->length - elem_a && quiet != ANALYSIS)
			rotate_down(a, "rra");
		return (a->length - elem_a);
	}
	else
	{
		while ((size_t)i < a->length - elem_a && quiet != ANALYSIS)
		{
			rotate_both(a, b, rotate_down,"rrr");
			i++;
		}
		while ((size_t)i++ < b->length - elem_b && quiet != ANALYSIS)
			rotate_down(b, "rrb");
		return (b->length - elem_b);
	}
}

size_t		rotate_analysis(t_ivec *a, t_ivec *b, int elem_a, int elem_b, int quiet)
{
	if ((size_t)elem_a < a->length - elem_a
			&& (size_t)elem_b < b->length - elem_b)
		return (first_case(a, b, elem_a,elem_b, quiet));
	else if ((size_t)elem_a >= a->length - elem_a
			&& (size_t)elem_b >= b->length - elem_b)
		return (second_case(a, b, elem_a, elem_b, quiet));
	else
		return(smart_rotations(a, 'a', elem_a,quiet) +
				smart_rotations(b, 'b', elem_b, quiet));
}