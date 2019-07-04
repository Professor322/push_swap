/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:36:10 by vlegros           #+#    #+#             */
/*   Updated: 2019/07/03 14:36:10 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		a_vec(t_manager *manager, t_data **new, int argc, char **argv)
{
	(*new)->stack = 'a';
	(*new)->img_vec = NULL;
	if (!((*new)->val_vec = create_stack(manager->start, argc, argv)))
	{
		ft_memdel((void**)new);
		return (0);
	}
	if (manager->visual)
		if (!((*new)->img_vec = vis_vec(manager, (*new)->val_vec)))
		{
			ft_int_vec_del(&(*new)->val_vec);
			ft_memdel((void**)new);
			return (0);
		}
	return (1);
}

static int		b_vec(t_manager *manager, t_data **new)
{
	(*new)->stack = 'b';
	(*new)->img_vec = NULL;
	if (!((*new)->val_vec = ft_int_vec_init()))
	{
		ft_memdel((void**)new);
		return (0);
	}
	if (manager->visual)
		if (!((*new)->img_vec = ft_ptr_vec_init()))
		{
			ft_int_vec_del(&(*new)->val_vec);
			ft_memdel((void**)new);
			return (0);
		}
	return (1);
}

static t_data	*t_data_init(t_manager *manager, int argc, char **argv,
		int flag)
{
	t_data *new;

	if (!(new = (t_data*)malloc(sizeof(t_data))))
		return (NULL);
	if (flag == A_ONLY)
	{
		if (!a_vec(manager, &new, argc, argv))
			return (NULL);
	}
	else if (flag == B_ONLY)
	{
		if (!b_vec(manager, &new))
			return (NULL);
	}
	return (new);
}

static void		visual_init(t_manager *manager)
{
	if (manager->visual)
	{
		manager->color_a = COLOR_A;
		manager->color_b = COLOR_B;
		manager->width = C_WIDTH;
		manager->height = C_HEIGHT;
		manager->mlx_ptr = mlx_init();
		manager->win_ptr = mlx_new_window(manager->mlx_ptr, C_WIDTH, C_HEIGHT,
				"checker_folder");
	}
}

t_manager		*manager_init(t_manager *manager, int argc, char **argv)
{
	visual_init(manager);
	if (!(manager->a = t_data_init(manager, argc, argv, A_ONLY)))
	{
		if (manager->visual)
			mlx_destroy_window(manager->mlx_ptr, manager->win_ptr);
		ft_memdel((void**)&manager);
		finish_him(MALLOC_ERROR);
	}
	manager->len = manager->a->val_vec->length;
	if (!(manager->b = t_data_init(manager, argc, argv, B_ONLY)))
	{
		if (manager->visual)
			mlx_destroy_window(manager->mlx_ptr, manager->win_ptr);
		t_data_del(manager, &manager->a);
		ft_memdel((void**)&manager);
		finish_him(MALLOC_ERROR);
	}
	return (manager);
}
