/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:32:54 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 11:20:08 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define MAX_DEPTH		9
# define MAX_DEPTH_B	18
# define CHUNK_SIZE_B	7
# define SORT_NB		4

# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include "ft_printf.h"
# include "common.h"

typedef struct	s_arg
{
	char		size;
	char		min_sort;
	char		recursive_sort;
	char		chunk_recursive_sort;
	char		quick_sort;
	char		all_sort;
}				t_arg;

typedef struct	s_data
{
	t_stack		stacks[2];
	t_list		*sol;
	char		found;
}				t_data;

typedef struct	s_opti
{
	char		*move;
	char		*move_op;
	char		*cancel[11];
}				t_opti;

typedef struct	s_min_sort
{
	t_stack		comp[2];
	int			lowest_nb;
	int			above_lowest_nb;
	int			highest_nb;
	int			i;
	int			highest_nb_index;
	int			above_lowest_nb_pushed;
}				t_min_sort;

typedef struct	s_recursive_sort
{
	char		*cur[MAX_DEPTH];
	char		*best[MAX_DEPTH];
	char		*cur_b[MAX_DEPTH_B];
	char		*best_b[MAX_DEPTH_B];
	int			depth;
	int			max_depth;
}				t_recursive_sort;

typedef struct	s_chunk_sort
{
	t_stack		comp[2];
	int			i;
	int			nb;
	int			*size;
}				t_chunk_sort;

typedef struct	s_quick_sort
{
	t_stack		comp[2];
	t_data		*data;
	t_ft		*moves;
	int			chunk_nb;
}				t_quick_sort;

char			is_arg(char const *str);
void			set_up_arg(t_arg *arg, char const **av);
void			copy_stacks(t_stack *src, t_stack *copy);

void			free_data(t_data *data);
void			set_up_data(t_data *data, t_stack *stacks);

void			display_sizes(t_data *data, int *size);
int				actual_size(t_list const *sol);

void			apply_move(t_data *data, t_stack *stacks
					, t_move_ft ft, char *str);
void			quick_sort_desc(t_stack *stack, int start, int end);
void			quick_sort_asc(t_stack *stack, int start, int end);
void			sort_stack_3_elems(t_stack *stacks, t_data *data
					, t_ft *moves);

void			min_sort(t_data *data, t_ft *moves);
int				find_low_index(int const low, t_stack *stack);
void			sort_stack_b(t_data *data, t_ft *moves, t_stack *stacks);

void			recursive_sort(t_data *data, t_ft *moves);

void			chunk_recursive_sort(t_data *data, t_ft *moves);
void			opti_rsb(t_data *data, t_stack *stacks, t_ft *moves
					, t_chunk_sort *chunk_s);
void			set_up_chunk_rs(t_data *data, t_chunk_sort *chunk_rs);
char			stack_b_recursion_launcher(t_data *data, t_ft *moves);
void			closest_to_top(t_data *data, t_stack *comp
					, t_chunk_sort *chunk_s, t_ft *moves);
char			is_b_sorted(t_stack *stacks);

void			quick_sort(t_data *data, t_ft *moves);
void			sorting_mid_a(t_quick_sort *quick_s, int low, int high);
void			sorting_mid_b(t_quick_sort *quick_s, int low, int high);

void			optimize_sol(t_list *sol, t_ft *moves);
char			find_next_elem(t_list **elem);
void			cancelling_moves_opti(t_list *sol, int *opti
					, t_opti *moves_s);
void			double_moves_opti(t_list *sol, int *opti, t_ft *moves);
void			set_up_t_opti(t_opti *moves_s, t_ft *moves);
void			set_up_t_opti_sa(t_opti *moves_s, t_ft *moves);
void			set_up_t_opti_sb(t_opti *moves_s, t_ft *moves);
void			set_up_t_opti_ss(t_opti *moves_s, t_ft *moves);
void			set_up_t_opti_pa(t_opti *moves_s, t_ft *moves);
void			set_up_t_opti_pb(t_opti *moves_s, t_ft *moves);
void			set_up_t_opti_ra(t_opti *moves_s, t_ft *moves);
void			set_up_t_opti_rb(t_opti *moves_s, t_ft *moves);
void			set_up_t_opti_rr(t_opti *moves_s, t_ft *moves);
void			set_up_t_opti_rra(t_opti *moves_s, t_ft *moves);
void			set_up_t_opti_rrb(t_opti *moves_s, t_ft *moves);
void			set_up_t_opti_rrr(t_opti *moves_s, t_ft *moves);

#endif
