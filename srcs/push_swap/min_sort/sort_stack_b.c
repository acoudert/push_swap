/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:48:06 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/29 09:48:40 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_b(t_data *data, t_ft *moves, t_stack *stacks)
{
	int		i;

	i = 0;
	while (i + 1 < stacks[1].size)
	{
		if (stacks[1].arr[i] < stacks[1].arr[i + 1])
			break ;
		i++;
	}
	i = stacks[1].size - i - 1;
	while (i > 0)
	{
		move_rrb(stacks);
		ft_lstadd_back(&data->sol, ft_lstnew(moves[9].str));
		i--;
	}
}
