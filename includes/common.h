/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:22:15 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 11:50:58 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H

# include "libft.h"

# define SA		0
# define SB		1
# define SS		2
# define PA		3
# define PB		4
# define RA		5
# define RB		6
# define RR		7
# define RRA	8
# define RRB	9
# define RRR	10

typedef struct	s_stack
{
	int			*arr;
	int			size;
}				t_stack;

typedef void	(*t_move_ft)(t_stack *stacks);

typedef struct	s_ft
{
	char		str[4];
	t_move_ft	ft;
	t_move_ft	op;
}				t_ft;

typedef char	(*t_is_arg_ft)(char const *str);

char			convert_input(int ac, char const **av, t_stack *stacks
					, t_is_arg_ft ft);
void			set_up_t_ft(t_ft *moves);
void			display_stacks(t_stack const *stacks);
int				error(t_stack *stacks);
void			free_stacks(t_stack *stacks);
char			is_sorted(t_stack const *stacks);
void			shift_stack(t_stack *stack, char const dir);

void			move_sa(t_stack *stacks);
void			move_sb(t_stack *stacks);
void			move_ss(t_stack *stacks);
void			move_pa(t_stack *stacks);
void			move_pb(t_stack *stacks);
void			move_ra(t_stack *stacks);
void			move_rb(t_stack *stacks);
void			move_rr(t_stack *stacks);
void			move_rra(t_stack *stacks);
void			move_rrb(t_stack *stacks);
void			move_rrr(t_stack *stacks);

#endif
