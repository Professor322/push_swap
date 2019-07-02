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

# define DEBUG        0
# define MALLOC_ERROR 2
# define INPUT_ERROR  3
# define INT_MAX 2147483647
# define INT_MIN -2147483648

#define A ((t_mlx*)param)->a
#define	A_VAL ((t_mlx*)param)->a.val_vec
#define	A_IMG ((t_mlx*)param)->a.img_vec
#define B      ((t_mlx*)param)->b
#define B_VAL  ((t_mlx*)param)->b.val_vec
#define B_IMG  ((t_mlx*)param)->b.img_vec

#define P_RED 0xFF555E
#define ORANGE 0xFF8650
#define P_YELLOW 0xFFE981
#define P_GREEN 0x8BF18B
#define LIGHT_BLUE 0x83B2FF
#define P_BLUE 0x203D85
#define PURPLE 0x9B6EF3

typedef struct	s_img
{
	void	*img;
	int 	i_width;
	int 	i_height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_img;

typedef struct	s_data
{
	t_ivec	*val_vec;
	t_vec	*img_vec;
	char 	stack;
}				t_data;

typedef struct	s_mlx
{
	int 	width;
	int 	height;
	t_data 	a;
	t_data	b;
	void	*mlx_ptr;
	void	*win_ptr;
	size_t 	len;
	int 	debug;
	int 	visual;
	int 	color_a;
	int 	color_b;
	int 	counter;
}				t_mlx;

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

void	rotate_elems(t_data *a, t_data *b, int stack_to_rotate, t_mlx *mlx);
void	swap_stack_elems(t_data *a, t_data *b, int stack_to_swap, t_mlx *mlx);
void	push_on_stack(t_data *a, t_data *b, int stack_to_push, t_mlx *mlx);

/**
 * 	apply and debug
 */
void	swaps(t_data *a, t_data *b, int command_num, t_mlx *mlx);
void	pushes(t_data *a, t_data *b, int command_num, t_mlx *mlx);
void	rotations_up(t_data *a, t_data *b, int command_num, t_mlx *mlx);
void	rotations_down(t_data *a, t_data *b, int command_num, t_mlx *mlx);

void	get_input(t_mlx *mlx);
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
int 	search_through(t_ivec *vec, int value);
/**
 * visualisation
 */
void	*create_elem(t_mlx *param, int length,int value);
t_ivec	*rearrange_elems(t_ivec *stack);
void	del(void **elem);
t_vec	*vis_vec(t_mlx *param, t_ivec *stack);
void	display_stack(t_mlx *param, t_vec *vec, char stack);
int 	vis_push(t_data *dst, t_data *src, char *action);
int 	vis_swap(t_data *stack, char *action);
int 	vis_rotate_up(t_data *stack, char *action);
int 	vis_rotate_down(t_data *stack, char *action);
int 	gc(void *param);
int		viz_stack(void * param);
void	change_color(t_vec *vec, int from, int to, int color);
void 	rainbow(t_vec *vec);


#endif
