/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 19:14:47 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 19:14:47 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	main(int argc, char **argv)
{
	t_ivec *a;
	t_ivec *b;

	if (argc > 1)
	{
		check_integers(1, argc, argv);
		a = create_stack(1, argc, argv);
		if (!(b = ft_int_vec_init()))
		{
			ft_int_vec_del(&a);
			finish_him(MALLOC_ERROR);
		}
		sort(&a, &b);
		ft_int_vec_del(&a);
		ft_int_vec_del(&b);
	}

	return (0);
}