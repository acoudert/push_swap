/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 10:51:20 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/01 21:24:26 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
** Return 1 if all elem in a and all are sorted
*/

char	is_sorted(t_stack const *stacks)
{
	int		i;

	if (stacks[1].size != 0)
		return (0);
	i = 0;
	while (i + 1 < stacks[0].size)
	{
		if (stacks[0].arr[i] > stacks[0].arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
