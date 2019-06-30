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
# include <mlx.h>

# define DEBUG       1
# define MALLOC_ERROR 2
# define INPUT_ERROR  3
# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct	s_mlx
{
	int 	width;
	int 	height;
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;

}				t_mlx;

typedef struct	s_vis
{
	int		val;
	void	*img;
}				t_vis;

typedef enum	e_flags
{
	ANALYSIS,
	DO_OP,
	VALUE,
	INDEX,
	FINAL,
	A_ONLY
}				t_flags;

typedef enum	e_operations
{
	SWAP_A,
	SWAP_B,
	SWAP_BOTH,
	PUSH_A,
	PUSH_B,
	ROTATE_A_UP,
	ROTATE_B_UP,
	ROTATE_BOTH_UP,
	ROTATE_A_DOWN,
	ROTATE_B_DOWN,
	ROTATE_BOTH_DOWN,
}				t_operations;

/**
 * operations
 */
int 	push(t_ivec *dst, t_ivec *src, int flag,char *action);
int 	swap(t_ivec *stack, char *action);
int 	rotate_up(t_ivec *stack, char *action);
int 	rotate_down(t_ivec *stack, char *action);
/**
 *
 */
void	finish_him(int t_error);
long	ft_atoi_move(char **src);
void	check_integers(int argc, char **argv);
t_ivec	*create_stack(int argc, char **argv);

void	rotate_elems(t_ivec *a, t_ivec *b, int stack_to_rotate);
void	swap_stack_elems(t_ivec *a, t_ivec *b, int stack_to_swap);
void	push_on_stack(t_ivec **a, t_ivec **b, int stack_to_push);

/**
 * 	apply and debug
 */
void	swaps(t_ivec *a, t_ivec *b, int command_num);
void	pushes(t_ivec **a, t_ivec **b, int command_num);
void	rotations_up(t_ivec *a, t_ivec *b, int command_num);
void	rotations_down(t_ivec *a, t_ivec *b, int command_num);

void	get_input(t_ivec **a, t_ivec **b);
void	print_stack(t_ivec *a, t_ivec *b);
int 	check_order(t_ivec *a, t_ivec *b, int flag);

int 	find_max(t_ivec *stack, int flag);
int 	find_min(t_ivec *stack, int flag);
int 	find_index(t_ivec *stack, int value);
int 	smart_rotations(t_ivec *stack, char c, int elem, int output_flag);
size_t 	calculate_and_place(t_ivec **a, t_ivec **b, int elem, int flag);
void	merge(t_ivec **a, t_ivec **b);
void	sort(t_ivec **a, t_ivec **b);
size_t	rotate_analysis(t_ivec *a, t_ivec *b, int elem_a, int elem_b, int quiet);
/**
 * visualisation
 */
void	create_elem(t_mlx *param, int value);
t_ivec	*rearrange_elems(t_ivec *stack);
void	del(void **elem);

#endif
