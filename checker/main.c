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

void	hooks(t_manager **checker)
{
	mlx_hook((*checker)->win_ptr, 17, 0, del_manager, checker);
	mlx_loop_hook((*checker)->mlx_ptr, visualize, checker);
	mlx_loop((*checker)->mlx_ptr);
}

t_manager	*init(int argc, char **argv)
{
	t_manager *checker;

	if (!(checker = (t_manager*)malloc(sizeof(t_manager))))
		finish_him(MALLOC_ERROR);
	checker->debug = FALSE;
	checker->visual = FALSE;
	checker->error = -1;
	checker->start = 1;
	checker->start = check_options(&checker, argc, argv);
	check_integers(checker->start, argc, argv);
	checker = manager_init(checker, argc, argv);
	return (checker);
}

int		main(int argc, char **argv)
{
	t_manager	*checker;

	if (argc <= 1)
		return (0);
	checker = init(argc, argv);
	if (checker->visual)
	{
		display_stack(checker, checker->a->img_vec, checker->a->stack);
		hooks(&checker);
	}
	else
	{
		get_input(&checker);
		check_order(checker->a->val_vec, checker->b->val_vec, FINAL) ?
		ft_printf("OK\n") : ft_printf("KO\n");
	}
	return (0);
}