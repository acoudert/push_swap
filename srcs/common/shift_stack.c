/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 15:38:53 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/01 21:24:15 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
** Shift stack:
** dir = 'u' | shift up dir (stack->arr[0] erased)
** dir = 'd' | shift down dir (stack->arr[0] not updated)
*/

void	shift_stack(t_stack *stack, char const dir)
{
	int		i;

	if (dir == 'u')
	{
		i = 0;
		while (i + 1 < stack->size)
		{
			stack->arr[i] = stack->arr[i + 1];
			i++;
		}
	}
	if (dir == 'd')
	{
		i = stack->size - 1;
		while (i > 0)
		{
			stack->arr[i] = stack->arr[i - 1];
			i--;
		}
	}
}
