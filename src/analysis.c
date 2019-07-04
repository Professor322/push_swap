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

static int	first_case(t_analysis *p)
{
	int i;

	i = 0;
	if (p->a_i > p->b_i)
	{
		while (i < p->b_i && p->s_flag != ANALYSIS)
		{
			rotate_both(p->a_v, p->b_v, rotate_up, "rr");
			i++;
		}
		while (i++ < p->a_i && p->s_flag != ANALYSIS)
			rotate_up(p->a_v, "ra");
		return (p->a_i);
	}
	else
	{
		while (i < p->a_i && p->s_flag != ANALYSIS)
		{
			rotate_both(p->a_v, p->b_v, rotate_up, "rr");
			i++;
		}
		while (i++ < p->b_i && p->s_flag != ANALYSIS)
			rotate_up(p->b_v, "rb");
		return (p->b_i);
	}
}

static int	second_case(t_analysis *p)
{
	int i;

	i = 0;
	if (p->a_v->length - p->a_i > p->b_v->length - p->b_i)
	{
		while ((size_t)i < p->b_v->length - p->b_i && p->s_flag != ANALYSIS)
		{
			rotate_both(p->a_v, p->b_v, rotate_down, "rrr");
			i++;
		}
		while ((size_t)i++ < p->a_v->length - p->a_i && p->s_flag != ANALYSIS)
			rotate_down(p->a_v, "rra");
		return (p->a_v->length - p->a_i);
	}
	else
	{
		while ((size_t)i < p->a_v->length - p->a_i && p->s_flag != ANALYSIS)
		{
			rotate_both(p->a_v, p->b_v, rotate_down, "rrr");
			i++;
		}
		while ((size_t)i++ < p->b_v->length - p->b_i && p->s_flag != ANALYSIS)
			rotate_down(p->b_v, "rrb");
		return (p->b_v->length - p->b_i);
	}
}

size_t		rotate_analysis(t_analysis *p)
{
	if ((size_t)p->a_i < p->a_v->length - p->a_i
			&& (size_t)p->b_i < p->b_v->length - p->b_i)
		return (first_case(p));
	else if ((size_t)p->a_i >= p->a_v->length - p->a_i
			&& (size_t)p->b_i >= p->b_v->length - p->b_i)
		return (second_case(p));
	else
		return (smart_rotations(p->a_v, 'a', p->a_i, p->s_flag) +
				smart_rotations(p->b_v, 'b', p->b_i, p->s_flag));
}
