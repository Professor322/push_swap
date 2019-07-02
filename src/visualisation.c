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
		vec->data[find_max(vec, INDEX)] = i + 1;
	return (vec);
}

void	*create_elem(t_mlx *param, int value)
{
	void *img;
	int *data;
	int bits_per_pixel;
	int size_line;
	int endian;

	img = mlx_new_image(param->mlx_ptr, value * 50, 50);
	data = (int*)mlx_get_data_addr(img,&bits_per_pixel, &size_line, &endian);
	for (int i = 0; i < value * 50 * 50; i++)
		data[i] = 0xFFFFFF;
	return (img);
}


t_vec	*vis_vec(t_mlx *param, t_ivec *stack)
{
	t_vec	*vec;
	t_ivec	*rearrange;
	int 	i;

	i = -1;
	if (!(vec = ft_ptr_vec_init()))
		finish_him(MALLOC_ERROR);
	rearrange = rearrange_elems(stack);
	while ((size_t)++i < rearrange->length)
		if (!ft_ptr_vec_pushback(vec, create_elem(param, rearrange->data[i])))
		{
			ft_ptr_vec_del(&vec, del);
			finish_him(MALLOC_ERROR);
		}
	ft_int_vec_del(&rearrange);
	return (vec);
}

void	display_stack(t_mlx *param, t_vec *vec, char stack)
{
	int i;
	int y;
	int x;

	x = stack == 'a' ? 15 : 300;
	i = -1;
	y = 100;
	while ((size_t)++i < vec->length)
	{
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
				((void**)(vec->data))[i], x, y);
		y += 70;
	}
}