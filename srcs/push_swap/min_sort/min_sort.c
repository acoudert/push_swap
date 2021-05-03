/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:54:24 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 08:37:06 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_up_min_s(t_data *data, t_min_sort *min_s)
{
	copy_stacks(data->stacks, min_s->comp);
	quick_sort_desc(min_s->comp, 0, min_s->comp[0].size - 1);
	min_s->highest_nb_index = 3;
	min_s->above_lowest_nb_pushed = 0;
}

static void	down_rot(t_data *data, t_min_sort *min_s, t_ft *moves)
{
	if (data->stacks[0].size > 4
			&& data->stacks[0].arr[0] == min_s->highest_nb)
	{
		apply_move(data, data->stacks, &move_pb, moves[PB].str);
		apply_move(data, data->stacks, &move_rb, moves[RB].str);
		min_s->highest_nb_index += 1;
	}
	else if (data->stacks[0].size > 4 && data->stacks[0].arr[0]
			== min_s->above_lowest_nb && min_s->above_lowest_nb_pushed == 0)
	{
		apply_move(data, data->stacks, &move_pb, moves[PB].str);
		min_s->above_lowest_nb_pushed = 1;
	}
	else if (min_s->i != 0)
		apply_move(data, data->stacks, &move_rra, moves[RRA].str);
	else
	{
		apply_move(data, data->stacks, &move_pb, moves[PB].str);
		if (min_s->above_lowest_nb_pushed == 1)
		{
			apply_move(data, data->stacks, &move_sb, moves[SB].str);
			min_s->above_lowest_nb_pushed = 0;
		}
		min_s->comp->size -= 1;
	}
}

static void	up_rot(t_data *data, t_min_sort *min_s, t_ft *moves)
{
	if (data->stacks[0].size > 4
			&& data->stacks[0].arr[0] == min_s->highest_nb)
	{
		apply_move(data, data->stacks, &move_pb, moves[PB].str);
		apply_move(data, data->stacks, &move_rb, moves[RB].str);
		min_s->highest_nb_index += 1;
	}
	else if (data->stacks[0].size > 4 && data->stacks[0].arr[0]
			== min_s->above_lowest_nb && min_s->above_lowest_nb_pushed == 0)
	{
		apply_move(data, data->stacks, &move_pb, moves[PB].str);
		min_s->above_lowest_nb_pushed = 1;
	}
	else if (min_s->i != 0)
		apply_move(data, data->stacks, &move_ra, moves[RA].str);
	else
	{
		apply_move(data, data->stacks, &move_pb, moves[PB].str);
		if (min_s->above_lowest_nb_pushed)
		{
			apply_move(data, data->stacks, &move_sb, moves[SB].str);
			min_s->above_lowest_nb_pushed = 0;
		}
		min_s->comp->size -= 1;
	}
}

static void	sorting_algorithm(t_data *data, t_min_sort *min_s, t_ft *moves)
{
	t_stack	*comp;

	comp = min_s->comp;
	while (data->stacks[0].size > 3)
	{
		min_s->lowest_nb = comp[0].arr[comp->size - 1];
		min_s->above_lowest_nb = comp[0].arr[comp->size - 2];
		min_s->highest_nb = comp[0].arr[min_s->highest_nb_index];
		min_s->i = find_low_index(comp->arr[comp->size - 1], &data->stacks[0]);
		if (min_s->i == data->stacks[0].size)
			comp->size -= 1;
		else if (min_s->i > data->stacks[0].size / 2)
			down_rot(data, min_s, moves);
		else if (min_s->i <= data->stacks[0].size / 2)
			up_rot(data, min_s, moves);
	}
	sort_stack_3_elems(data->stacks, data, moves);
	sort_stack_b(data, moves, data->stacks);
	while (data->stacks[1].size != 0)
		apply_move(data, data->stacks, &move_pa, moves[PA].str);
}

void		min_sort(t_data *data, t_ft *moves)
{
	t_min_sort	min_s;

	set_up_min_s(data, &min_s);
	sorting_algorithm(data, &min_s, moves);
	data->found = 1;
	free_stacks(min_s.comp);
}
