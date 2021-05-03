/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_sol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 10:04:19 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/30 13:37:02 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	find_next_elem(t_list **elem)
{
	while (*elem && (*elem)->content == NULL)
		*elem = (*elem)->next;
	if (*elem == NULL)
		return (0);
	return (1);
}

void	optimize_sol(t_list *sol, t_ft *moves)
{
	t_opti	moves_s[11];
	int		opti;

	set_up_t_opti(moves_s, moves);
	opti = 1;
	while (opti)
	{
		opti = 0;
		cancelling_moves_opti(sol, &opti, moves_s);
		double_moves_opti(sol, &opti, moves);
	}
}
