/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlegros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:24:27 by vlegros           #+#    #+#             */
/*   Updated: 2019/06/27 15:24:27 by vlegros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

# define FALSE 		 0
# define TRUE		 1
# define MALLOC_ERROR 2
# define INPUT_ERROR  3
# define INT_MAX 2147483647
# define INT_MIN -2147483648

/**
 * operations
 */
int 	push(t_ivec *src, t_ivec *dst, char *action);
int 	swap(t_ivec *stack, char *action);
int 	rotate_up(t_ivec *stack, char *action);
int 	rotate_down(t_ivec *stack, char *action);
/**
 *
 */
void	finish_him(int t_error);
long	ft_atoi_move(char **src);
void	check_integers(int argc, char **argv);

#endif
