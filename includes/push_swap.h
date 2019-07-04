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
# include <time.h>

#define TRUE			1
#define FALSE			0

# define DEBUG			0
# define MALLOC_ERROR	2
# define INPUT_ERROR	3
# define INT_MAX 2147483647
# define INT_MIN -2147483648

#define	PAUSE	(*((t_manager**)param))->pause
#define	SPEED	(*((t_manager**)param))->speed
#define MLX_PTR	(*((t_manager**)param))->mlx_ptr
#define WIN_PTR	(*((t_manager**)param))->win_ptr
#define A		(*((t_manager**)param))->a
#define	A_VAL	(*((t_manager**)param))->a->val_vec
#define	A_IMG	(*((t_manager**)param))->a->img_vec
#define B		(*((t_manager**)param))->b
#define B_VAL	(*((t_manager**)param))->b->val_vec
#define B_IMG	(*((t_manager**)param))->b->img_vec

#define	C_WIDTH		1000
#define C_HEIGHT	1000
#define COLOR_A		0x48D1CC
#define COLOR_B		0xF0E68C
#define P_RED		0xFF555E
#define ORANGE		0xFF8650
#define P_YELLOW	0xFFE981
#define P_GREEN		0x8BF18B
#define LIGHT_BLUE	0x83B2FF
#define P_BLUE		0x203D85
#define PURPLE		0x9B6EF3

typedef struct	s_img
{
	void	*img;
	void	*mlx_ptr;
	int 	*data;
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

typedef struct	s_analysis
{
	t_ivec *a_v;
	t_ivec *b_v;
	int 	a_i;
	int 	b_i;
	int 	s_flag;
}				t_analysis;

typedef struct	s_manager
{
	t_data 	*a;
	t_data	*b;
	size_t 	len;
	int 	debug;
	int 	visual;
	void	*mlx_ptr;
	void	*win_ptr;
	int 	color_a;
	int 	color_b;
	int		speed;
	int 	width;
	int 	height;
	int 	error;
	int 	start;
	int 	pause;
}				t_manager;

typedef enum	e_flags
{
	ANALYSIS,
	DO_OP,
	VALUE,
	INDEX,
	FINAL,
	A_ONLY,
	B_ONLY
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
void		check_integers(int from, int argc, char **argv);
t_ivec	*create_stack(int from, int argc, char **argv);

void	rotate_elems(t_data *a, t_data *b, int stack_to_rotate, t_manager *checker);
void	swap_stack_elems(t_data *a, t_data *b, int stack_to_swap, t_manager *checker);
void	push_on_stack(t_data *a, t_data *b, int stack_to_push, t_manager **checker);

/**
 * 	apply and debug
 */
void	swaps(t_data *a, t_data *b, int command_num, t_manager *checker);
void	pushes(t_data *a, t_data *b, int command_num, t_manager **checker);
void	rotations_up(t_data *a, t_data *b, int command_num, t_manager *checker);
void	rotations_down(t_data *a, t_data *b, int command_num, t_manager *checker);

void	get_input(t_manager **checker);
void	print_stack(t_ivec *a, t_ivec *b);
int 	check_order(t_ivec *a, t_ivec *b, int flag);

int 	find_max(t_ivec *stack, int flag);
int 	find_min(t_ivec *stack, int flag);
int 	find_index(t_ivec *stack, int value);
int 	smart_rotations(t_ivec *stack, char c, int elem, int output_flag);
size_t 	calculate_and_place(t_ivec **a, t_ivec **b, int elem, int flag);
void	merge(t_ivec **a, t_ivec **b);
void	sort(t_ivec **a, t_ivec **b);
size_t	rotate_analysis(t_analysis *param);
int 	search_through(t_ivec *vec, int value);
/**
 * visualisation
 */
void	*create_elem(t_manager *param, int length,int value);
t_ivec	*rearrange_elems(t_ivec *stack, size_t length);
void	del(void **elem);
t_vec	*vis_vec(t_manager *param, t_ivec *stack);
void	display_stack(t_manager *param, t_vec *vec, char stack);
int 	vis_push(t_data *dst, t_data *src, char *action, t_manager *manager);
int 	vis_swap(t_data *stack, char *action, t_manager *manager);
int 	vis_rotate_up(t_data *stack, char *action, t_manager *manager);
int 	vis_rotate_down(t_data *stack, char *action, t_manager *manager);
int 	get_command(void *param);
int		visualize(void *param);
void	change_color(t_vec *vec, int from, int to, int color);
void 	rainbow(t_vec *vec);
t_manager	*manager_init(t_manager *manager, int argc, char **argv);
void	t_data_del(t_manager *checker,t_data **data);
int		del_manager(void *manager);
int		check_options(t_manager **manager, int argc, char **argv);

#endif
