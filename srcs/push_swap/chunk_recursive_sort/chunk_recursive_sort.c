/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_recursive_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:22:34 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 08:32:33 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_b_to_a(t_data *data, t_ft *moves)
{
	while (data->stacks[1].size > 0)
		apply_move(data, data->stacks, &move_pa, moves[PA].str);
}

static int	get_upper_bound(t_chunk_sort *chunk_rs, t_stack *comp)
{
	int		i;
	int		j;

	i = -1;
	j = chunk_rs->i;
	while (j-- > 0)
		i += CHUNK_SIZE_B;
	return (comp[0].arr[i]);
}

static void	update_stack_a(t_data *data, t_ft *moves
				, t_chunk_sort *chunk_rs, t_stack *comp)
{
	int		i;
	int		val;

	if (chunk_rs->i == 0)
		return ;
	val = get_upper_bound(chunk_rs, comp);
	i = find_low_index(val, &data->stacks[0]);
	if (i <= data->stacks[0].size / 2)
	{
		while (i > 0)
		{
			apply_move(data, data->stacks, &move_ra, moves[RA].str);
			i--;
		}
	}
	else
	{
		while (i != data->stacks[0].size)
		{
			apply_move(data, data->stacks, &move_rra, moves[RRA].str);
			i++;
		}
	}
}

static void	sorting_algorithm(t_data *data, t_chunk_sort *chunk_rs
		, t_ft *moves)
{
	int		elems;
	t_stack	*comp;

	comp = chunk_rs->comp;
	while (chunk_rs->i < chunk_rs->nb)
	{
		elems = chunk_rs->size[chunk_rs->i];
		while (elems > 0)
		{
			closest_to_top(data, comp, chunk_rs, moves);
			apply_move(data, data->stacks, &move_pb, moves[PB].str);
			opti_rsb(data, data->stacks, moves, chunk_rs);
			elems -= 1;
		}
		update_stack_a(data, moves, chunk_rs, comp);
		if (!(stack_b_recursion_launcher(data, moves)))
			return ;
		stack_b_to_a(data, moves);
		chunk_rs->i += 1;
	}
	if (is_sorted(data->stacks))
		data->found = 1;
}

void		chunk_recursive_sort(t_data *data, t_ft *moves)
{
	t_chunk_sort	chunk_rs;

	set_up_chunk_rs(data, &chunk_rs);
	sorting_algorithm(data, &chunk_rs, moves);
	if (chunk_rs.size)
		free(chunk_rs.size);
	free_stacks(chunk_rs.comp);
}
