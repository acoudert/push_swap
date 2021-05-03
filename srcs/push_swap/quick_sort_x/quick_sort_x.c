/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 16:55:28 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/01 09:24:46 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static int		partition_desc(t_stack *stack, int start, int end)
{
	int		pivot;
	int		i;
	int		j;

	pivot = stack->arr[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (stack->arr[j] > pivot)
		{
			i++;
			swap(&stack->arr[i], &stack->arr[j]);
		}
		j++;
	}
	swap(&stack->arr[i + 1], &stack->arr[end]);
	return (i + 1);
}

static int		partition_asc(t_stack *stack, int start, int end)
{
	int		pivot;
	int		i;
	int		j;

	pivot = stack->arr[end];
	i = start - 1;
	j = start;
	while (j <= end - 1)
	{
		if (stack->arr[j] < pivot)
		{
			i++;
			swap(&stack->arr[i], &stack->arr[j]);
		}
		j++;
	}
	swap(&stack->arr[i + 1], &stack->arr[end]);
	return (i + 1);
}

void			quick_sort_desc(t_stack *stack, int start, int end)
{
	int		pi;

	if (start < end)
	{
		pi = partition_desc(stack, start, end);
		quick_sort_desc(stack, start, pi - 1);
		quick_sort_desc(stack, pi + 1, end);
	}
}

void			quick_sort_asc(t_stack *stack, int start, int end)
{
	int		pi;

	if (start < end)
	{
		pi = partition_asc(stack, start, end);
		quick_sort_asc(stack, start, pi - 1);
		quick_sort_asc(stack, pi + 1, end);
	}
}
