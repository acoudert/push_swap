/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_mid_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 08:41:03 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 08:53:22 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	check_b(t_quick_sort *quick_s, int mid)
{
	int		i;

	i = 0;
	while (i < quick_s->data->stacks[1].size)
	{
		if (quick_s->data->stacks[1].arr[i] >= quick_s->comp[0].arr[mid])
			return (1);
		i++;
	}
	return (0);
}

static void	stack_rot_b(t_quick_sort *quick_s, int rot_nb)
{
	if (rot_nb > 0)
	{
		if (rot_nb > quick_s->data->stacks[1].size / 2)
		{
			while (rot_nb != quick_s->data->stacks[1].size)
			{
				apply_move(quick_s->data, quick_s->data->stacks
					, &move_rb, quick_s->moves[RB].str);
				rot_nb += 1;
			}
		}
		else
		{
			while (rot_nb > 0)
			{
				apply_move(quick_s->data, quick_s->data->stacks
					, &move_rrb, quick_s->moves[RRB].str);
				rot_nb -= 1;
			}
		}
	}
}

static void	move_b(t_quick_sort *quick_s, int const mid
				, int *rot_nb, int *len)
{
	if (quick_s->data->stacks[1].size && *len == 1
			&& quick_s->data->stacks[1].arr[1]
				>= quick_s->comp[0].arr[mid])
	{
		apply_move(quick_s->data, quick_s->data->stacks
		, &move_sb, quick_s->moves[SB].str);
	}
	if (quick_s->data->stacks[1].arr[0] < quick_s->comp[0].arr[mid])
	{
		apply_move(quick_s->data, quick_s->data->stacks
				, &move_rb, quick_s->moves[RB].str);
		*rot_nb += 1;
	}
	else
	{
		*len -= 1;
		apply_move(quick_s->data, quick_s->data->stacks
				, &move_pa, quick_s->moves[PA].str);
	}
}

void		sorting_mid_b(t_quick_sort *quick_s, int low, int high)
{
	int		mid;
	int		rot_nb;
	int		len;

	if (low > high)
		return ;
	if (is_sorted(quick_s->data->stacks))
		return ;
	mid = (low + high) / 2;
	rot_nb = 0;
	len = high - mid + 1;
	while (check_b(quick_s, mid))
		move_b(quick_s, mid, &rot_nb, &len);
	stack_rot_b(quick_s, rot_nb);
	sorting_mid_a(quick_s, mid, high);
	sorting_mid_b(quick_s, low, mid - 1);
}
