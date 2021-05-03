/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:34:55 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/27 13:24:40 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include <stdio.h>

void	display_stacks(t_stack const *stacks)
{
	int		i;

	i = 0;
	printf("Stack A (%3d): ", stacks[0].size);
	while (i < stacks[0].size)
	{
		printf("%d ", stacks[0].arr[i]);
		i++;
	}
	printf("\n");
	i = 0;
	printf("Stack B (%3d): ", stacks[1].size);
	while (i < stacks[1].size)
	{
		printf("%d ", stacks[1].arr[i]);
		i++;
	}
	printf("\n");
}
