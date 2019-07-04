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

static t_analysis	*analysis_init(t_ivec *a, t_ivec *b, int elem, int flag)
{
	t_analysis *analysis;

	if (!(analysis = (t_analysis*)malloc(sizeof(t_analysis))))
		return (NULL);
	analysis->a_v = a;
	analysis->b_v = b;
	analysis->b_i = find_index(b, elem);
	analysis->s_flag = flag;
	return (analysis);
}

static int			cycle(t_analysis *analysis, int elem)
{
	int i;
	int actions;

	i = -1;
	actions = 0;
	while ((size_t)++i < analysis->a_v->length - 1)
	{
		if (elem > analysis->a_v->data[i] &&
		elem < analysis->a_v->data[i + 1])
		{
			analysis->a_i = i + 1;
			actions = rotate_analysis(analysis);
			break ;
		}
		if ((size_t)i + 2 == analysis->a_v->length)
			if (elem > analysis->a_v->data[i + 1] &&
			elem < analysis->a_v->data[0])
			{
				analysis->a_i = 0;
				actions = rotate_analysis(analysis);
			}
	}
	return (actions);
}

static inline void	del_and_out(t_ivec **a, t_ivec **b)
{
	ft_int_vec_del(a);
	ft_int_vec_del(b);
	finish_him(MALLOC_ERROR);
}

size_t				calculate_and_place(t_ivec **a, t_ivec **b, int elem,
		int flag)
{
	t_analysis	*analysis;
	size_t		actions;
	int			min;
	int			max;

	if (!(analysis = analysis_init(*a, *b, elem, flag)))
		del_and_out(a, b);
	max = find_max(*a, VALUE);
	min = find_min(*a, VALUE);
	actions = 0;
	if (elem < min || elem > max)
	{
		analysis->a_i = find_index(*a, min);
		actions = rotate_analysis(analysis);
	}
	else
		actions = cycle(analysis, elem);
	if (!(push(*a, *b, flag, flag == ANALYSIS ? NULL : "pa")))
		del_and_out(a, b);
	return (actions + 1);
}
