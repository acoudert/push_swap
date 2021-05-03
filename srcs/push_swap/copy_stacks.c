/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 17:47:56 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/28 18:15:18 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	copy_stacks(t_stack *src, t_stack *copy)
{
	int		i;

	copy[0].arr = NULL;
	copy[1].arr = NULL;
	if (!(copy[0].arr = (int*)malloc(sizeof(int) * src[0].size)))
		return ;
	if (!(copy[1].arr = (int*)malloc(sizeof(int) * src[0].size)))
		return ;
	i = -1;
	while (++i < src[0].size)
		copy[0].arr[i] = src[0].arr[i];
	i = -1;
	while (++i < src[1].size)
		copy[1].arr[i] = src[1].arr[i];
	copy[0].size = src[0].size;
	copy[1].size = src[1].size;
}
