/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:23:30 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 15:23:30 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_ivec *a;
	t_ivec *b;

	if (argc > 1)
	{
		check_integers(argc, argv);
		a = create_stack(argc, argv);
		if (!(b = ft_int_vec_init()))
		{
			ft_int_vec_del(&a);
			finish_him(MALLOC_ERROR);
		}
		get_input(&a, &b);
		check_order(a, b, FINAL) ? ft_printf("OK\n") : ft_printf("KO\n");
		ft_int_vec_del(&a);
		ft_int_vec_del(&b);
	}
	return (0);
}