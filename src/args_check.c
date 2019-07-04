/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:31:18 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 16:31:18 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			search_through(t_ivec *vec, int value)
{
	int i;

	i = -1;
	while ((size_t)++i < vec->length)
		if (vec->data[i] == value)
			return (1);
	return (0);
}

static void	check_new_value(t_ivec **vec, char **temp, char **save_ptr)
{
	long		value;

	while (**temp)
	{
		value = ft_atoi_move(temp);
		if (value > INT_MAX || value < INT_MIN || search_through(*vec, value))
		{
			ft_int_vec_del(vec);
			ft_memdel((void**)save_ptr);
			finish_him(INPUT_ERROR);
		}
		ft_int_vec_pushback(*vec, value);
	}
	ft_memdel((void**)save_ptr);
}

int			check_integers(int from, int argc, char **argv)
{
	char	*temp;
	char	*save_ptr;
	t_ivec	*vec;
	int		flag;

	if (!(vec = ft_int_vec_init()))
		finish_him(MALLOC_ERROR);
	flag = 0;
	while (from < argc)
	{
		if (!(temp = ft_strtrim(argv[from])))
		{
			ft_int_vec_del(&vec);
			finish_him(MALLOC_ERROR);
		}
		save_ptr = temp;
		check_new_value(&vec, &temp, &save_ptr);
		from++;
		flag = 1;
	}
	ft_int_vec_del(&vec);
	return (flag);
}
