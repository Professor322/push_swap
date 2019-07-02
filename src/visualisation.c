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

int 	advanced_find_max(t_ivec *vec, t_ivec *index_vec)
{
	int i;
	int max;
	int max_index;

	i = -1;
	while ((size_t)++i < vec->length)
		if (!search_through(index_vec, i))
		{
			max = vec->data[i];
			max_index = i;
			break;
		}
	i = -1;
	while ((size_t)++i < vec->length)
		if (vec->data[i] > max && !search_through(index_vec, i))
		{
			max = vec->data[i];
			max_index = i;
		}
	return (max_index);
}

t_ivec	*rearrange_elems(t_ivec *stack)
{
	t_ivec *vec;
	t_ivec *index_vec;
	int index;
	int i;

	i = -1;
	if (!(vec = ft_int_vec_init()))
		finish_him(MALLOC_ERROR);
	if (!(index_vec = ft_int_vec_init()))
	{
		ft_int_vec_del(&vec);
		finish_him(MALLOC_ERROR);
	}
	while ((size_t)++i < stack->length)
		if (!ft_int_vec_pushback(vec, stack->data[i]))
		{
			ft_int_vec_del(&vec);
			finish_him(MALLOC_ERROR);
		}
	i = vec->length;
	while (vec->length != index_vec->length)
	{
		index = advanced_find_max(vec, index_vec);
		vec->data[index] = i--;
		if (!ft_int_vec_pushback(index_vec, index))
		{
			ft_int_vec_del(&vec);
			ft_int_vec_del(&index_vec);
			finish_him(MALLOC_ERROR);
		}
	}
	ft_int_vec_del(&index_vec);
	return (vec);
}

void	*create_elem(t_mlx *param, int length, int value)
{
	t_img *new_img;
	int *data;
	int multiplier = 500 / length;
	int width = value * multiplier;
	int height = 800 / length;
	if (!(new_img = (t_img*)malloc(sizeof(t_img))))
		finish_him(MALLOC_ERROR);
	new_img->img = mlx_new_image(param->mlx_ptr, width, height);
	data = (int*)mlx_get_data_addr(new_img->img,&new_img->bits_per_pixel, &new_img->size_line, &new_img->endian);
	for (int i = 0; i < width * height; i++)
		data[i] = param->color_a;
	new_img->i_height = height;
	new_img->i_width = width;
	return (new_img);
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
		if (!ft_ptr_vec_pushback(vec, create_elem(param, rearrange->length, rearrange->data[i])))
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
	int chlen = !(200 / param->len) ? 1 : 200 / param->len;

	x = stack == 'a' ? 0 : 500;
	i = -1;
	y = 0;
	while ((size_t)++i < vec->length)
	{
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr,
				((t_img*)(((void**)(vec->data))[i]))->img, x, y);
		y += chlen + 800 / param->len;
	}
}

void	fill_with_color(t_img *elem, int color)
{
	int *data;
	int i = -1;

	data = (int*)mlx_get_data_addr(elem->img,&elem->bits_per_pixel, &elem->bits_per_pixel, &elem->endian);
	while (++i < elem->i_width * elem->i_height)
		data[i] = color;

}

void	change_color(t_vec *vec, int from, int to, int color)
{
	while (from < to)
	{
		fill_with_color(((void**)(vec->data))[from], color);
		from++;
	}
}

void rainbow(t_vec *vec)
{
	const int len = vec->length >= 7 ? vec->length / 7 : vec->length;

	if (vec->length >= 7)
	{
		change_color(vec, 0, len, P_RED);
		change_color(vec, len, len + len, ORANGE);
		change_color(vec, 2 * len, 3 * len, P_YELLOW);
		change_color(vec, 3 * len, 4 * len, P_GREEN);
		change_color(vec, 4 * len, 5 * len, LIGHT_BLUE);
		change_color(vec, 5 * len, 6 * len, P_BLUE);
		change_color(vec, 6 * len, vec->length, PURPLE);
	}
}