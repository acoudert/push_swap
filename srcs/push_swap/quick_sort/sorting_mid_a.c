/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_mid_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 08:40:14 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 09:09:43 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	check_a(t_quick_sort *quick_s, int mid)
{
	int		i;

	i = 0;
	while (i < quick_s->data->stacks[0].size)
	{
		if (quick_s->data->stacks[0].arr[i] <= quick_s->comp[0].arr[mid])
			return (1);
		i++;
	}
	return (0);
}

static void	stack_rot_a(t_quick_sort *quick_s, int rot_nb)
{
	if (rot_nb > 0)
	{
		if (rot_nb > quick_s->data->stacks[0].size / 2)
		{
			while (rot_nb != quick_s->data->stacks[0].size)
			{
				apply_move(quick_s->data, quick_s->data->stacks
					, &move_ra, quick_s->moves[RA].str);
				rot_nb += 1;
			}
		}
		else
		{
			while (rot_nb > 0)
			{
				apply_move(quick_s->data, quick_s->data->stacks
					, &move_rra, quick_s->moves[RRA].str);
				rot_nb -= 1;
			}
		}
	}
}

static void	move_a(t_quick_sort *quick_s, int const mid
				, int *rot_nb, int *len)
{
	if (*len == 1 && quick_s->data->stacks[0].arr[1]
			<= quick_s->comp[0].arr[mid])
	{
		apply_move(quick_s->data, quick_s->data->stacks
				, &move_sa, quick_s->moves[SA].str);
	}
	if (quick_s->data->stacks[0].arr[0] > quick_s->comp[0].arr[mid])
	{
		apply_move(quick_s->data, quick_s->data->stacks
				, &move_ra, quick_s->moves[RA].str);
		*rot_nb += 1;
	}
	else
	{
		*len -= 1;
		apply_move(quick_s->data, quick_s->data->stacks
				, &move_pb, quick_s->moves[PB].str);
	}
}

void		sorting_mid_a(t_quick_sort *quick_s, int low, int high)
{
	int		mid;
	int		rot_nb;
	int		len;

	if (low >= high)
		return ;
	if (is_sorted(quick_s->data->stacks))
		return ;
	mid = (low + high) / 2;
	rot_nb = 0;
	len = mid - low + 1;
	while (check_a(quick_s, mid))
		move_a(quick_s, mid, &rot_nb, &len);
	stack_rot_a(quick_s, rot_nb);
	sorting_mid_a(quick_s, mid + 1, high);
	sorting_mid_b(quick_s, low, mid);
}
