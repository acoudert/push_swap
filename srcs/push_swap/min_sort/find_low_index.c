/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_low_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:46:07 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/30 11:06:46 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_low_index(int const low, t_stack *stack)
{
	int		i;

	i = 0;
	while (i < stack->size)
	{
		if (stack->arr[i] == low)
			return (i);
		i++;
	}
	return (i);
}
