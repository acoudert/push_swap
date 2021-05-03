/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closest_to_top.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 12:46:55 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/01 21:32:53 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_first_elem(t_stack *stack, t_stack *comp
					, t_chunk_sort *chunk_s, int i_start)
{
	int			i;
	int			j;

	i = -1;
	while (++i < stack->size)
	{
		j = i_start;
		while (j < i_start + chunk_s->size[chunk_s->i])
		{
			if (stack->arr[i] == comp[0].arr[j])
				return (i);
			j++;
		}
	}
	return (-1);
}

static int		find_last_elem(t_stack *stack, t_stack *comp
					, t_chunk_sort *chunk_s, int i_start)
{
	int			i;
	int			j;

	i = stack->size;
	while (--i >= 0)
	{
		j = i_start;
		while (j < i_start + chunk_s->size[chunk_s->i])
		{
			if (stack->arr[i] == comp[0].arr[j])
				return (i);
			j++;
		}
	}
	return (-1);
}

static int		find_closest_index(t_stack *stack, t_stack *comp
					, t_chunk_sort *chunk_s)
{
	int			i[2];
	int			i_start;

	i[0] = -1;
	i_start = 0;
	while (++i[0] < chunk_s->i)
		i_start += chunk_s->size[i[0]];
	i[0] = find_first_elem(stack, comp, chunk_s, i_start);
	i[1] = find_last_elem(stack, comp, chunk_s, i_start);
	if (i[0] == -1 || i[1] == -1)
		return (-1);
	if (i[0] <= stack->size - i[1])
		return (i[0]);
	else
		return (i[1]);
}

void			closest_to_top(t_data *data, t_stack *comp
					, t_chunk_sort *chunk_s, t_ft *moves)
{
	int			i;

	i = find_closest_index(&data->stacks[0], comp, chunk_s);
	if (i < 0)
		return ;
	while (i > 0)
	{
		if (i <= data->stacks[0].size / 2)
		{
			apply_move(data, data->stacks, &move_ra, moves[RA].str);
			i--;
		}
		else
		{
			apply_move(data, data->stacks, &move_rra, moves[RRA].str);
			i++;
			if (i == data->stacks[0].size)
				i = 0;
		}
	}
}
