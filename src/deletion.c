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
	if (!*elem)
		return ;
	mlx_destroy_image((*((t_img**)(elem)))->mlx_ptr, (*((t_img**)(elem)))->img);
	ft_memdel(elem);
}

void	t_data_del(t_manager *checker, t_data **data)
{
	ft_int_vec_del(&(*data)->val_vec);
	if (checker->visual)
		ft_ptr_vec_del(&(*data)->img_vec, del);
	ft_memdel((void**)data);
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

int		del_manager(void *manager)
{
	t_data_del(*((t_manager**)manager),&(*((t_manager**)manager))->a);
	t_data_del(*((t_manager**)manager),&(*((t_manager**)manager))->b);
	if ((*((t_manager**)manager))->visual)
		mlx_destroy_window((*((t_manager**)manager))->mlx_ptr,
			(*((t_manager**)manager))->win_ptr);
	if((*((t_manager**)((void**)manager)))->error == MALLOC_ERROR)
		write(2, "Malloc error\n", 13);
	else if ((*((t_manager**)((void**)manager)))->error == INPUT_ERROR)
		write(2, "Input error\n", 12);
	ft_memdel(((void**)manager));
	exit(0);
	return (0);
}
