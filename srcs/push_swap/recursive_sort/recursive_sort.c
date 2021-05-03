/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:22:34 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/01 21:27:19 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	set_up_rec_s(t_recursive_sort *rec_s)
{
	int					i;

	i = -1;
	while (++i < MAX_DEPTH)
	{
		rec_s->cur[i] = NULL;
		rec_s->best[i] = NULL;
	}
	rec_s->depth = 0;
	rec_s->max_depth = MAX_DEPTH;
}

static void	update_best(t_data *data, t_recursive_sort *rec_s)
{
	int					j;

	j = -1;
	rec_s->max_depth = rec_s->depth;
	while (++j < rec_s->depth)
		rec_s->best[j] = rec_s->cur[j];
	rec_s->best[j] = rec_s->cur[j];
	data->found = 1;
}

static void	sorting_algorithm(t_data *data, t_recursive_sort *rec_s
				, t_ft *moves)
{
	int					i;

	i = 0;
	while (i < 11)
	{
		if (!is_sorted(data->stacks) && rec_s->depth + 1 < rec_s->max_depth
				&& ((i != PA && i != PB)
				|| (i == PA && data->stacks[1].size != 0)
				|| (i == PB && data->stacks[0].size != 0)))
		{
			moves[i].ft(data->stacks);
			rec_s->cur[rec_s->depth] = moves[i].str;
			rec_s->depth += 1;
			if (is_sorted(data->stacks))
				update_best(data, rec_s);
			else
				sorting_algorithm(data, rec_s, moves);
			rec_s->depth -= 1;
			rec_s->cur[rec_s->depth] = NULL;
			moves[i].op(data->stacks);
		}
		i++;
	}
}

void		recursive_sort(t_data *data, t_ft *moves)
{
	int					i;
	t_recursive_sort	rec_s;

	set_up_rec_s(&rec_s);
	if (is_sorted(data->stacks))
	{
		data->found = 1;
		return ;
	}
	sorting_algorithm(data, &rec_s, moves);
	i = 0;
	while (rec_s.best[i])
	{
		ft_lstadd_back(&data->sol, ft_lstnew(rec_s.best[i]));
		i++;
	}
}
