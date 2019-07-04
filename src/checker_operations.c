/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 18:41:08 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/01 18:41:08 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		vis_push(t_data *dst, t_data *src, char *action, t_manager *checker)
{
	if (!src || !dst)
		return (-1);
	if (!src->val_vec->length)
		return (-1);
	if (!(ft_int_vec_pushfront(dst->val_vec,
			ft_int_vec_popfront(src->val_vec))))
		return (0);
	if (checker->visual)
		if (!(ft_ptr_vec_pushfront(dst->img_vec,
				ft_ptr_vec_popfront(src->img_vec))))
			return (0);
	if (action)
		ft_printf("%s\n", action);
	return (1);
}

int		vis_swap(t_data *stack, char *action, t_manager *checker)
{
	int		temp;
	void	*temp_ptr;

	if (!stack)
		return (0);
	if (stack->val_vec->length < 2)
		return (0);
	temp = stack->val_vec->data[0];
	stack->val_vec->data[0] = stack->val_vec->data[1];
	stack->val_vec->data[1] = temp;
	if (checker->visual)
	{
		temp_ptr = ((void **)(stack->img_vec->data))[0];
		((void **)(stack->img_vec->data))[0] =
				((void **)(stack->img_vec->data))[1];
		((void **)(stack->img_vec->data))[1] = temp_ptr;
	}
	if (action)
		ft_printf("%s\n", action);
	return (1);
}

int		vis_rotate_up(t_data *stack, char *action, t_manager *checker)
{
	int		temp;
	void	*temp_ptr;
	int		i;

	if (!stack)
		return (0);
	if (stack->val_vec->length < 2)
		return (0);
	temp = stack->val_vec->data[0];
	ft_memmove(stack->val_vec->data, stack->val_vec->data + 1, sizeof(int) *
	stack->val_vec->length);
	stack->val_vec->data[stack->val_vec->length - 1] = temp;
	if (checker->visual)
	{
		i = -1;
		temp_ptr = ((void **)(stack->img_vec->data))[0];
		while ((size_t)++i < stack->img_vec->length - 1)
			((void **)(stack->img_vec->data))[i] =
					((void **)(stack->img_vec->data))[i + 1];
		((void **)(stack->img_vec->data))[stack->img_vec->length - 1] =
				temp_ptr;
	}
	if (action)
		ft_printf("%s\n", action);
	return (1);
}

int		vis_rotate_down(t_data *stack, char *action, t_manager *checker)
{
	int		temp;
	void	*temp_ptr;
	int		i;

	if (!stack)
		return (0);
	if (stack->val_vec->length < 2)
		return (0);
	temp = stack->val_vec->data[stack->val_vec->length - 1];
	ft_memmove(stack->val_vec->data + 1, stack->val_vec->data, sizeof(int) *
	(stack->val_vec->length - 1));
	stack->val_vec->data[0] = temp;
	if (checker->visual)
	{
		temp_ptr = ((void**)(stack->img_vec->data))[stack->img_vec->length - 1];
		i = stack->img_vec->length;
		while (--i > 0)
			((void **)(stack->img_vec->data))[i] =
					((void **)(stack->img_vec->data))[i - 1];
		((void **)(stack->img_vec->data))[0] = temp_ptr;
	}
	if (action)
		ft_printf("%s\n", action);
	return (1);
}
