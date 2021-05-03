/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rrx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 16:06:51 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/27 19:32:35 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	move_rrx(t_stack *stack)
{
	int		tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->arr[stack->size - 1];
	shift_stack(stack, 'd');
	stack->arr[0] = tmp;
}

void		move_rra(t_stack *stacks)
{
	move_rrx(&stacks[0]);
}

void		move_rrb(t_stack *stacks)
{
	move_rrx(&stacks[1]);
}

void		move_rrr(t_stack *stacks)
{
	move_rra(stacks);
	move_rrb(stacks);
}
