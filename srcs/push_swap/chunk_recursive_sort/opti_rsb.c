/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opti_rsb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 08:32:13 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 08:32:27 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opti_rsb(t_data *data, t_stack *stacks
			, t_ft *moves, t_chunk_sort *chunk_s)
{
	int		i;

	if (stacks[1].size <= 1)
		return ;
	i = 0;
	while (chunk_s->comp[0].arr[i] != stacks[1].arr[0])
		i++;
	if (i > 0 && stacks[1].arr[1] == chunk_s->comp[0].arr[i - 1])
		apply_move(data, data->stacks, &move_sb, moves[SB].str);
}
