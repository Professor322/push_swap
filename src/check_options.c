/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:46:36 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/04 17:46:36 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			check_options(t_manager **manager, int argc, char **argv)
{
	int			i;
	int			from;
	const int	len = argc > 3 ? 3 : argc;

	i = 0;
	from = 1;
	while (++i < len)
		if (!ft_strcmp(argv[i], "-v") || !ft_strcmp(argv[i], "--visual"))
		{
			if ((*manager)->visual)
				del_manager(manager);
			(*manager)->visual = TRUE;
			from++;
		}
		else if (!ft_strcmp(argv[i], "-d") || !ft_strcmp(argv[i], "--debug"))
		{
			if ((*manager)->debug)
				del_manager(manager);
			(*manager)->debug = TRUE;
			from++;
		}
	return (from);
}
