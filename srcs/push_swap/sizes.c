/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 08:55:43 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 09:12:24 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		display_unique_size(char *str, int size)
{
	printf("%-20s: %d moves\n", str, size);
}

void			display_sizes(t_data *data, int *size)
{
	if (data[0].found)
		display_unique_size("Min sort", size[0]);
	if (data[1].found)
		display_unique_size("Recursive sort", size[1]);
	if (data[2].found)
		display_unique_size("Chunk recursive sort", size[2]);
	if (data[3].found)
		display_unique_size("Quick sort", size[3]);
}

int				actual_size(t_list const *sol)
{
	int		size;

	size = 0;
	while (sol)
	{
		if (sol->content != NULL)
			size += 1;
		sol = sol->next;
	}
	return (size);
}
