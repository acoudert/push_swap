/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_b_sorted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 08:23:06 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 08:23:22 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	is_b_sorted(t_stack *stacks)
{
	int		i;

	i = 0;
	while (i < stacks[1].size)
	{
		if (i + 1 < stacks[1].size && stacks[1].arr[i] < stacks[1].arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
