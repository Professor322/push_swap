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

void	*create_elem(t_manager *param, int length, int value)
{
	const int	multiplier = (C_WIDTH / 2) / length;
	const int	width = value * multiplier;
	const int	height = (C_HEIGHT - C_HEIGHT / 5) / length;
	t_img		*new_img;
	int			i;

	if (!(new_img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	new_img->mlx_ptr = param->mlx_ptr;
	new_img->img = mlx_new_image(param->mlx_ptr, width, height);
	new_img->data = (int*)mlx_get_data_addr(new_img->img,
			&new_img->bits_per_pixel, &new_img->size_line, &new_img->endian);
	i = -1;
	while (++i < width * height)
		new_img->data[i] = param->color_a;
	new_img->i_height = height;
	new_img->i_width = width;
	return (new_img);
}

t_vec	*vis_vec(t_manager *param, t_ivec *stack)
{
	t_vec	*vec;
	t_ivec	*rearrange;
	int		i;

	i = -1;
	if (!(vec = ft_ptr_vec_init()))
		return (NULL);
	rearrange = rearrange_elems(stack, stack->length);
	while ((size_t)++i < rearrange->length)
		if (!ft_ptr_vec_pushback(vec, create_elem(param, rearrange->length,
				rearrange->data[i])))
		{
			ft_ptr_vec_del(&vec, del);
			return (NULL);
		}
	ft_int_vec_del(&rearrange);
	return (vec);
}

void	display_stack(t_manager *param, t_vec *vec, char stack)
{
	int			i;
	int			y;
	int			move;
	const int	x = stack == 'a' ? 0 : C_WIDTH / 2;
	const int	figure_height = (C_HEIGHT - C_HEIGHT / 5) / param->len;

	i = -1;
	y = 0;
	move = !((C_HEIGHT / 5) / param->len) ? 1 : (C_HEIGHT / 5) / param->len;
	while ((size_t)++i < vec->length)
	{
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
				((t_img*)(((void**)(vec->data))[i]))->img, x, y);
		y += move + figure_height;
	}
}
