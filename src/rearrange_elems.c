/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rearrange_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 15:41:16 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/03 15:41:16 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int 	advanced_find_max(t_ivec *vec, t_ivec *index_vec)
{
	int i;
	int max;
	int max_index;

	i = -1;
	while ((size_t)++i < vec->length)
		if (!search_through(index_vec, i))
		{
			max = vec->data[i];
			max_index = i;
			break;
		}
	i = -1;
	while ((size_t)++i < vec->length)
		if (vec->data[i] > max && !search_through(index_vec, i))
		{
			max = vec->data[i];
			max_index = i;
		}
	return (max_index);
}

static t_ivec	*copy_vec(t_ivec *stack)
{
	t_ivec *vec;
	int i;

	if (!(vec = ft_int_vec_init()))
		return (NULL);
	i = -1;
	while ((size_t)++i < stack->length)
		if (!ft_int_vec_pushback(vec, stack->data[i]))
		{
			ft_int_vec_del(&vec);
			return (NULL);
		}
	return (vec);
}

t_ivec	*rearrange_elems(t_ivec *stack)
{
	t_ivec *vec;
	t_ivec *index_vec;
	int index;
	int i;

	if (!(vec = copy_vec(stack)))
		return (NULL);
	if (!(index_vec = ft_int_vec_init()))
	{
		ft_int_vec_del(&vec);
		return (NULL);
	}
	i = vec->length;
	while (vec->length != index_vec->length)
	{
		index = advanced_find_max(vec, index_vec);
		vec->data[index] = i--;
		if (!ft_int_vec_pushback(index_vec, index))
		{
			ft_int_vec_del(&vec);
			ft_int_vec_del(&index_vec);
			return (NULL);
		}
	}
	ft_int_vec_del(&index_vec);
	return (vec);
}
