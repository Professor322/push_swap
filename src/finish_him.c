/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_him.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:44:31 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/04 17:44:31 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	finish_him(int t_error)
{
	if (t_error == MALLOC_ERROR)
	{
		write(2, "Malloc error\n", 13);
	}
	else if (t_error == INPUT_ERROR)
	{
		write(2, "Input error\n", 12);
	}
	exit(-1);
}
