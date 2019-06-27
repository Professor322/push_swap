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

static int 	search_through(t_ivec *vec, int value)
{
	int i;

	if (vec->length == 1)
		return (0);
	i = -1;
	while ((size_t)++i < vec->length)
		if (vec->data[i] == value)
			return (1);
	return (0);
}

static void check_new_value(t_ivec **vec, char **temp)
{
	long		value;
	const char	**save_ptr = (const char**)temp;

	while (**temp)
	{
		value = ft_atoi_move(temp);
		if (value > INT_MAX || value < INT_MIN || search_through(*vec, value))
		{
			ft_memdel((void**)vec);
			ft_memdel((void**)save_ptr);
			finish_him(INPUT_ERROR);
		}
		ft_int_vec_pushback(*vec, value);
	}
	ft_memdel((void**)save_ptr);
}

void	check_integers(int argc, char **argv)
{
	int		 i;
	char	*temp;
	t_ivec	*vec;

	if (!(vec = ft_int_vec_init()))
	{
		ft_memdel((void**)&vec);
		finish_him(MALLOC_ERROR);
	}
	i = 0;
	while (++i < argc)
	{
		if (!(temp = ft_strtrim(argv[i])))
		{
			ft_memdel((void**)&vec);
			finish_him(MALLOC_ERROR);
		}
		check_new_value(&vec, &temp);
	/*	save_ptr = temp;
		while (*temp)
		{
			value = ft_atoi_move(&temp);
			if (value > INT_MAX || value < INT_MIN || search_through(vec, value))
			{
				ft_memdel((void**)&vec);
				ft_memdel((void**)&save_ptr);
				finish_him(INPUT_ERROR);
			}
			ft_int_vec_pushback(vec, value);
		}
		ft_memdel((void**)&save_ptr);*/
	}
	ft_int_vec_del(&vec);
}