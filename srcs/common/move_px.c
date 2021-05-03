/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:35:04 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/27 19:32:08 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	move_px(t_stack *put, t_stack *pop)
{
	int		tmp;

	if (pop->size < 1)
		return ;
	tmp = pop->arr[0];
	shift_stack(pop, 'u');
	pop->size -= 1;
	put->size += 1;
	shift_stack(put, 'd');
	put->arr[0] = tmp;
}

void		move_pa(t_stack *stacks)
{
	move_px(&stacks[0], &stacks[1]);
}

void		move_pb(t_stack *stacks)
{
	move_px(&stacks[1], &stacks[0]);
}
