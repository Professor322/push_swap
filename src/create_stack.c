/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:46:21 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 16:46:21 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ivec *create_stack(int argc, char **argv)
{
	t_ivec	*stack;
	int		i;
	char	*temp;
	char 	*save_ptr;

	i = 0;
	if (!(stack = ft_int_vec_init()))
		finish_him(MALLOC_ERROR);
	while (++i < argc)
	{
		if(!(temp = ft_strtrim(argv[i])))
		{
			ft_int_vec_del(&stack);
			finish_him(MALLOC_ERROR);
		}
		save_ptr = temp;
		while (*temp)
			if (!ft_int_vec_pushback(stack, ft_atoi_move(&temp)))
			{
				ft_int_vec_del(&stack);
				ft_memdel((void**)&save_ptr);
				finish_him(MALLOC_ERROR);
			}
		ft_memdel((void**)&save_ptr);
	}
	return (stack);
}