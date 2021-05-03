/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 09:25:15 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 08:53:55 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_up_quick_s(t_data *data, t_quick_sort *quick_s, t_ft *moves)
{
	copy_stacks(data->stacks, quick_s->comp);
	quick_sort_asc(quick_s->comp, 0, quick_s->comp[0].size - 1);
	quick_s->data = data;
	quick_s->moves = moves;
}

void		quick_sort(t_data *data, t_ft *moves)
{
	t_quick_sort	quick_s;

	set_up_quick_s(data, &quick_s, moves);
	if (data->stacks[0].size > 2)
	{
		sorting_mid_a(&quick_s, 0, quick_s.comp[0].size - 1);
		data->found = 1;
	}
	free_stacks(quick_s.comp);
}
