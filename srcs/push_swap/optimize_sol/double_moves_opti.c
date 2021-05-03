/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_moves_opti.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:14:53 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/29 12:19:23 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	update(t_list *cur, char const *s1, t_list *next, char const *s2)
{
	if (ft_strcmp((char*)cur->content, s1) == 0
			&& ft_strcmp((char*)next->content, s2) == 0)
	{
		cur->content = NULL;
		next->content = NULL;
		return (1);
	}
	return (0);
}

static void	make_updates(t_list *cur, t_list *next, t_ft *moves, int *opti)
{
	if (update(cur, "sa", next, "sb") || update(cur, "sb", next, "sa"))
	{
		cur->content = moves[SS].str;
		*opti = 1;
	}
	if (update(cur, "ra", next, "rb") || update(cur, "rb", next, "ra"))
	{
		cur->content = moves[RR].str;
		*opti = 1;
	}
	if (update(cur, "rra", next, "rrb") || update(cur, "rrb", next, "rra"))
	{
		cur->content = moves[RRR].str;
		*opti = 1;
	}
}

void		double_moves_opti(t_list *sol, int *opti, t_ft *moves)
{
	t_list *cur;
	t_list *next;

	cur = sol;
	if (!find_next_elem(&cur))
		return ;
	while (cur->next)
	{
		next = cur->next;
		if (!find_next_elem(&next))
			return ;
		make_updates(cur, next, moves, opti);
		cur = next;
		if (!find_next_elem(&cur))
			return ;
	}
}
