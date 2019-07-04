/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:41:45 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/04 14:41:45 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		fill_with_color(t_img *elem, int color)
{
	int	*data;
	int	i;

	i = -1;
	data = (int*)mlx_get_data_addr(elem->img, &elem->bits_per_pixel,
			&elem->bits_per_pixel, &elem->endian);
	while (++i < elem->i_width * elem->i_height)
		data[i] = color;
}

void		change_color(t_vec *vec, int from, int to, int color)
{
	while (from < to)
	{
		fill_with_color(((void**)(vec->data))[from], color);
		from++;
	}
}

void		rainbow(t_vec *vec)
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
	else
		change_color(vec, 0, vec->length, P_GREEN);
}

static void	delay(int number_of_seconds)
{
	const int		milli_seconds = 50000 * number_of_seconds;
	const clock_t	start_time = clock();

	while (clock() < start_time + milli_seconds)
		;
}

int			visualize(void *param)
{
	static int counter = 0;

	if (!PAUSE)
	{
		delay(SPEED);
		mlx_clear_window(MLX_PTR, WIN_PTR);
		if (!get_command(param))
		{
			rainbow(A_IMG);
			display_stack(*((void **)param), A_IMG, A->stack);
			mlx_string_put(MLX_PTR, WIN_PTR, C_WIDTH - 100, C_HEIGHT - 50,
					P_GREEN, ft_itoa(counter));
			return (1);
		}
		else
		{
			change_color(A_IMG, 0, A_IMG->length, COLOR_A);
			display_stack(*((void **)param), A_IMG, A->stack);
			change_color(B_IMG, 0, B_IMG->length, COLOR_B);
			display_stack(*((void **)param), B_IMG, B->stack);
			mlx_string_put(MLX_PTR, WIN_PTR, C_WIDTH - 100, C_HEIGHT - 50,
					P_RED, ft_itoa(++counter));
		}
	}
	return (0);
}
