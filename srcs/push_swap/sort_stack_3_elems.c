/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_3_elems.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:43:22 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/01 21:37:45 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_3_elems(t_stack *stacks, t_data *data, t_ft *moves)
{
	if (stacks[0].arr[0] > stacks[0].arr[1]
			&& stacks[0].arr[0] < stacks[0].arr[2])
		apply_move(data, data->stacks, &move_sa, moves[SA].str);
	else if (stacks[0].arr[0] > stacks[0].arr[1]
			&& stacks[0].arr[1] > stacks[0].arr[2])
	{
		apply_move(data, data->stacks, &move_sa, moves[SA].str);
		apply_move(data, data->stacks, &move_rra, moves[RRA].str);
	}
	else if (stacks[0].arr[0] > stacks[0].arr[2]
			&& stacks[0].arr[1] < stacks[0].arr[2])
		apply_move(data, data->stacks, &move_ra, moves[RA].str);
	else if (stacks[0].arr[0] < stacks[0].arr[2]
			&& stacks[0].arr[1] > stacks[0].arr[2])
	{
		apply_move(data, data->stacks, &move_sa, moves[SA].str);
		apply_move(data, data->stacks, &move_ra, moves[RA].str);
	}
	else if (stacks[0].arr[0] > stacks[0].arr[2]
			&& stacks[0].arr[0] < stacks[0].arr[1])
		apply_move(data, data->stacks, &move_rra, moves[RRA].str);
}
