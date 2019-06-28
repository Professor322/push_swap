/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 17:56:32 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 17:56:32 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	check_order(t_ivec *a, t_ivec *b, int flag)
{
	int i;

	if (flag == FINAL)
		if (b->length)
			return (0);
	i = -1;
	while ((size_t)++i < a->length - 1)
		if (a->data[i] > a->data[i + 1])
			return (0);
	return (1);
}

void	print_stack(t_ivec *a, t_ivec *b)
{
	int i;

	i = -1;
	ft_printf("\nstack a\n");
	while ((size_t)++i < a->length)
		ft_printf("|%d|", a->data[i]);
	ft_printf("\n");
	i = -1;
	ft_printf("\nstack b\n");
	while((size_t)++i < b->length)
		ft_printf("|%d|", b->data[i]);
	ft_printf("\n");
}