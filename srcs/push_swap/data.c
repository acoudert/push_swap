/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 08:58:57 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 08:59:30 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_data(t_data *data)
{
	int		i;
	t_list	*next;

	i = 0;
	while (i < SORT_NB)
	{
		free_stacks(data[i].stacks);
		while (data[i].sol)
		{
			next = data[i].sol->next;
			free(data[i].sol);
			data[i].sol = next;
		}
		i++;
	}
}

void	set_up_data(t_data *data, t_stack *stacks)
{
	int		i;

	i = 0;
	while (i < SORT_NB)
	{
		copy_stacks(stacks, data[i].stacks);
		data[i].sol = NULL;
		data[i].found = 0;
		i++;
	}
}
