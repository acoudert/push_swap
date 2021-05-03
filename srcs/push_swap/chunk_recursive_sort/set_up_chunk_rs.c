/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_chunk_rs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:39:25 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/30 19:33:25 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_up_chunk_rs_size(t_chunk_sort *chunk_rs)
{
	int		i;
	int		size;

	if (!(chunk_rs->size = (int*)malloc(sizeof(int) * (chunk_rs->nb + 1))))
		return ;
	i = 0;
	size = chunk_rs->comp[0].size;
	while (size > CHUNK_SIZE_B)
	{
		chunk_rs->size[i] = CHUNK_SIZE_B;
		size = size - CHUNK_SIZE_B;
		i++;
	}
	if (size == CHUNK_SIZE_B)
		chunk_rs->size[i] = CHUNK_SIZE_B;
	else if (chunk_rs->comp[0].size % CHUNK_SIZE_B)
		chunk_rs->size[i] = chunk_rs->comp[0].size % CHUNK_SIZE_B;
}

void		set_up_chunk_rs(t_data *data, t_chunk_sort *chunk_rs)
{
	copy_stacks(data->stacks, chunk_rs->comp);
	quick_sort_desc(chunk_rs->comp, 0, chunk_rs->comp[0].size - 1);
	chunk_rs->i = 0;
	chunk_rs->nb = 0;
	chunk_rs->size = NULL;
	if (chunk_rs->comp[0].size <= 3)
		return ;
	chunk_rs->nb = chunk_rs->comp[0].size / CHUNK_SIZE_B;
	if (chunk_rs->comp[0].size % CHUNK_SIZE_B)
		chunk_rs->nb += 1;
	set_up_chunk_rs_size(chunk_rs);
}
