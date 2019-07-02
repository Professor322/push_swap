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
	t_mlx mlx;

	if (argc > 1)
	{
		check_integers(argc, argv);
		mlx.a.val_vec = create_stack(argc, argv);
		if (!(mlx.b.val_vec = ft_int_vec_init()))
		{
			ft_int_vec_del(&mlx.a.val_vec);
			finish_him(MALLOC_ERROR);
		}
		mlx.height = 1000;
		mlx.width = 1000;
		mlx.color_a = 0x48D1CC;
		mlx.color_b = 0xF0E68C;
		mlx.len = mlx.a.val_vec->length;
		mlx.mlx_ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.width, mlx.height, "chlen");
		mlx.a.img_vec = vis_vec(&mlx, mlx.a.val_vec);
		mlx.b.img_vec = ft_ptr_vec_init();
		mlx.a.stack = 'a';
		mlx.b.stack = 'b';
		display_stack(&mlx, mlx.a.img_vec, mlx.a.stack);
		display_stack(&mlx, mlx.b.img_vec, mlx.b.stack);
		//get_input(&mlx);
	//	check_order(mlx.a.val_vec, mlx.b.val_vec, FINAL) ? ft_printf("OK\n") : ft_printf("KO\n");
		mlx_loop_hook(mlx.mlx_ptr, viz_stack, &mlx);
		mlx_loop(mlx.mlx_ptr);
	/*	check_order(dt_a.val_vec, dt_b.val_vec, FINAL) ? ft_printf("OK\n") : ft_printf("KO\n");
		ft_int_vec_del(&dt_a.val_vec);
		ft_int_vec_del(&dt_b.val_vec);
		ft_ptr_vec_del(&dt_a.img_vec, del);
		ft_ptr_vec_del(&dt_a.img_vec, del);*/
	}
	return (0);
}