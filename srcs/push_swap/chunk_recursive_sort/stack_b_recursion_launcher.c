/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_b_recursion_launcher.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:59:18 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 08:30:29 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_up_rec_s(t_recursive_sort *rec_s)
{
	int		i;

	i = -1;
	while (++i < MAX_DEPTH_B)
	{
		rec_s->cur_b[i] = NULL;
		rec_s->best_b[i] = NULL;
	}
	rec_s->depth = 0;
	rec_s->max_depth = MAX_DEPTH_B;
}

static void	update_best(t_data *data, t_recursive_sort *rec_s)
{
	int		j;

	(void)data;
	j = -1;
	rec_s->max_depth = rec_s->depth;
	while (++j < rec_s->depth)
		rec_s->best_b[j] = rec_s->cur_b[j];
	rec_s->best_b[j] = rec_s->cur_b[j];
}

static char	useless_move(t_recursive_sort *rec_s, int i)
{
	if (i == SA || i == SS || i == PA || i == PB
			|| i == RA || i == RR || i == RRA || i == RRR)
		return (1);
	if (rec_s->depth > 0 && i == SB
			&& ft_strcmp(rec_s->cur_b[rec_s->depth - 1], "sb") == 0)
		return (1);
	if (rec_s->depth > 0 && i == RB
			&& ft_strcmp(rec_s->cur_b[rec_s->depth - 1], "rrb") == 0)
		return (1);
	if (rec_s->depth > 0 && i == RRB
			&& ft_strcmp(rec_s->cur_b[rec_s->depth - 1], "rb") == 0)
		return (1);
	return (0);
}

static void	sorting_algorithm(t_data *data, t_recursive_sort *rec_s
				, t_ft *moves)
{
	int		i;

	i = -1;
	while (++i < 11)
	{
		if (useless_move(rec_s, i))
			continue ;
		if (!is_b_sorted(data->stacks)
				&& rec_s->depth + 1 < rec_s->max_depth)
		{
			moves[i].ft(data->stacks);
			rec_s->cur_b[rec_s->depth] = moves[i].str;
			rec_s->depth += 1;
			if (is_b_sorted(data->stacks))
				update_best(data, rec_s);
			else
				sorting_algorithm(data, rec_s, moves);
			rec_s->depth -= 1;
			rec_s->cur_b[rec_s->depth] = NULL;
			moves[i].op(data->stacks);
		}
	}
}

char		stack_b_recursion_launcher(t_data *data, t_ft *moves)
{
	int					i;
	int					j;
	t_recursive_sort	rec_s;

	set_up_rec_s(&rec_s);
	sorting_algorithm(data, &rec_s, moves);
	i = 0;
	while (rec_s.best_b[i])
	{
		ft_lstadd_back(&data->sol, ft_lstnew(rec_s.best_b[i]));
		j = 0;
		while (ft_strcmp(moves[j].str, rec_s.best_b[i]) != 0)
			j++;
		moves[j].ft(data->stacks);
		i++;
	}
	if (!is_b_sorted(data->stacks))
		return (0);
	return (1);
}
