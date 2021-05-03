/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_sx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:28:27 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/27 19:30:37 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	move_sx(t_stack *stack)
{
	int		tmp;

	if (stack->size <= 1)
		return ;
	tmp = stack->arr[0];
	stack->arr[0] = stack->arr[1];
	stack->arr[1] = tmp;
}

void		move_sa(t_stack *stacks)
{
	move_sx(&stacks[0]);
}

void		move_sb(t_stack *stacks)
{
	move_sx(&stacks[1]);
}

void		move_ss(t_stack *stacks)
{
	move_sx(&stacks[0]);
	move_sx(&stacks[1]);
}
