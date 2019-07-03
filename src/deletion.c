/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deletion.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 16:01:06 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/03 16:01:06 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void **elem)
{
	mlx_destroy_image((*((t_img**)(elem)))->mlx_ptr, (*((t_img**)(elem)))->img);
	ft_memdel(elem);
}

void	t_data_del(t_data **data)
{
	ft_int_vec_del(&(*data)->val_vec);
	ft_ptr_vec_del(&(*data)->img_vec, del);
}

void	finish_him(int t_error)
{
	if (t_error == MALLOC_ERROR)
	{
		write(2, "Malloc error\n", 13);
	}
	else if (t_error == INPUT_ERROR)
	{
		write(2, "Input error\n", 12);
	}
	exit(-1);
}