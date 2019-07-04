/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:26:32 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 15:26:32 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push(t_ivec *dst, t_ivec *src, int flag, char *action)
{
	if (!src || !dst)
		return (-1);
	if (!src->length)
		return (-1);
	if (flag == DO_OP)
		if (!(ft_int_vec_pushfront(dst, ft_int_vec_popfront(src))))
			return (0);
	if (action)
		ft_printf("%s\n", action);
	return (1);
}

int		swap(t_ivec *stack, char *action)
{
	int temp;

	if (!stack)
		return (0);
	if (stack->length < 2)
		return (0);
	temp = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = temp;
	if (action)
		ft_printf("%s\n", action);
	return (1);
}

int		rotate_up(t_ivec *stack, char *action)
{
	int	temp;

	if (!stack)
		return (0);
	if (stack->length < 2)
		return (0);
	temp = stack->data[0];
	ft_memmove(stack->data, stack->data + 1, sizeof(int) * stack->length);
	stack->data[stack->length - 1] = temp;
	if (action)
		ft_printf("%s\n", action);
	return (1);
}

int		rotate_down(t_ivec *stack, char *action)
{
	int	temp;

	if (!stack)
		return (0);
	if (stack->length < 2)
		return (0);
	temp = stack->data[stack->length - 1];
	ft_memmove(stack->data + 1, stack->data, sizeof(int) * (stack->length - 1));
	stack->data[0] = temp;
	if (action)
		ft_printf("%s\n", action);
	return (1);
}
