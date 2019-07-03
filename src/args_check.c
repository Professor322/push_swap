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

int 	search_through(t_ivec *vec, int value)
{
	int i;

	i = -1;
	while ((size_t)++i < vec->length)
		if (vec->data[i] == value)
			return (1);
	return (0);
}

static void check_new_value(t_ivec **vec, char **temp, char **save_ptr)
{
	long		value;

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

void		check_integers(int from, int argc, char **argv)
{
	char	*temp;
	char	*save_ptr;
	t_ivec	*vec;

	if (!(vec = ft_int_vec_init()))
		finish_him(MALLOC_ERROR);
	while (from < argc)
	{
		if (!(temp = ft_strtrim(argv[from])))
		{
			ft_memdel((void**)&vec);
			finish_him(MALLOC_ERROR);
		}
		save_ptr = temp;
		check_new_value(&vec, &temp, &save_ptr);
		from++;
	}
	ft_int_vec_del(&vec);
}

int		check_options(t_manager **manager, int argc, char **argv)
{
	int i;
	int from;
	const int len = argc > 3 ? 3 : argc;

	i = 0;
	from = 1;
	while (++i < len)
		if (!ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "--visual"))
		{
			if ((*manager)->visual)
				del_manager(manager);
			(*manager)->visual = TRUE;
			from++;
		}
		else if (!ft_strcmp(argv[i], "-d") || !ft_strcmp(argv[i], "--debug"))
		{
			if ((*manager)->debug)
				del_manager(manager);
			(*manager)->debug = TRUE;
			from++;
		}
	return (from);
}