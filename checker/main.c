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


void	del(void **elem)
{
	ft_memdel(elem);
}

int		main(int argc, char **argv)
{
	t_data dt_a;
	t_data dt_b;
	t_mlx mlx;

	if (argc > 1)
	{
		check_integers(argc, argv);
		dt_a.val_vec = create_stack(argc, argv);
		if (!(dt_b.val_vec = ft_int_vec_init()))
		{
			ft_int_vec_del(&dt_a.val_vec);
			finish_him(MALLOC_ERROR);
		}
		mlx.mlx_ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1000, 1000, "chlen");
		dt_a.img_vec = vis_vec(&mlx, dt_a.val_vec);
		dt_b.img_vec = ft_ptr_vec_init();
		dt_a.stack = 'a';
		dt_b.stack = 'b';
		display_stack(&mlx, dt_a.img_vec, dt_a.stack);
		display_stack(&mlx, dt_b.img_vec, dt_b.stack);
		//get_input(&dt_a, &dt_b, &mlx);
		mlx_loop(mlx.mlx_ptr);
		check_order(dt_a.val_vec, dt_b.val_vec, FINAL) ? ft_printf("OK\n") : ft_printf("KO\n");
		ft_int_vec_del(&dt_a.val_vec);
		ft_int_vec_del(&dt_b.val_vec);
		ft_ptr_vec_del(&dt_a.img_vec, del);
		ft_ptr_vec_del(&dt_a.img_vec, del);
	}
	return (0);
}