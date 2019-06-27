/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_vec_pushback.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/18 18:03:09 by vlegros           #+#    #+#             */
/*   Updated: 2019/05/18 18:03:09 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_ptr_vec_pushback(t_vec *vec, void *value)
{
	if (!vec)
		return ;
	if (ft_ptr_vec_enlarge(vec))
		((void**)(vec->data))[vec->length++] = value;
}