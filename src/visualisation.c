/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 19:43:38 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/29 19:43:38 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ivec	*rearrange_elems(t_ivec *stack)
{
	t_ivec *vec;
	int	i;

	i = -1;
	if (!(vec = ft_int_vec_init()))
		finish_him(MALLOC_ERROR);
	while ((size_t)++i < stack->length)
		if (!ft_int_vec_pushback(vec, stack->data[i]))
		{
			ft_int_vec_del(&vec);
			finish_him(MALLOC_ERROR);
		}
	i = stack->length;
	while (--i >= 0)
		vec->data[find_max(vec, INDEX)] = i;
	return (vec);
}

void	create_elem(t_mlx *param, int value)
{
	void *img;
	int *data;
	int bits_per_pixel;
	int size_line;
	int endian;

	img = mlx_new_image(param->mlx_ptr, value * 10, 20);
	data = (int*)mlx_get_data_addr(img,&bits_per_pixel, &size_line, &endian);
	for (int i = 0; i < value * 10 * 20; i++)
		data[i] = 0xFFFFFF;
	mlx_put_image_to_window(param->mlx_ptr,param->win_ptr, img, 40, 40);
}
