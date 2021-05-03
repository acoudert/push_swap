/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:06:51 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/27 19:30:19 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	move_rx(t_stack *stack)
{
	int		tmp;

	tmp = stack->arr[0];
	shift_stack(stack, 'u');
	stack->arr[stack->size - 1] = tmp;
}

void		move_ra(t_stack *stacks)
{
	if (stacks[0].size > 1)
		move_rx(&stacks[0]);
}

void		move_rb(t_stack *stacks)
{
	if (stacks[1].size > 1)
		move_rx(&stacks[1]);
}

void		move_rr(t_stack *stacks)
{
	move_ra(stacks);
	move_rb(stacks);
}
