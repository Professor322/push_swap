/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:22:44 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 16:22:44 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	dec_check(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	else
		finish_him(INPUT_ERROR);
	return (-1);
}

long		ft_atoi_move(char **src)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(**src))
		(*src)++;
	if ((**src == '+' || **src == '-') && dec_check(*((*src) + 1)))
		*((*src)++) == '-' ? (sign *= -1) : (sign *= 1);
	while (**src && !ft_isspace(**src))
		result = result * 10 + dec_check(*((*src)++));
	return (result * sign);
}
