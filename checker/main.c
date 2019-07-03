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
	t_manager *checker;
	if (argc > 1)
	{
		check_integers(argc, argv);
		checker = manager_init(argc, argv);
		mlx_loop_hook(checker->mlx_ptr, visualize, checker);
		mlx_loop(checker->mlx_ptr);
	/*	check_order(dt_a.val_vec, dt_b.val_vec, FINAL) ? ft_printf("OK\n") : ft_printf("KO\n");*/
	}
	return (0);
}