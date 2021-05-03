/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cancelling_moves_opti.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:05:39 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/01 21:28:47 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Returns 1 if opti done
*/

static char	check_next_elems(t_list *cur, t_list *next
				, t_opti *moves_s, int i)
{
	static int		t = 0;
	int				j;

	while (next && next->content != NULL)
	{
		if (ft_strcmp((char*)next->content, moves_s[i].move_op) == 0)
		{
			cur->content = NULL;
			next->content = NULL;
			return (1);
		}
		j = 0;
		while (moves_s[i].cancel[j] && ft_strcmp((char*)next->content
				, moves_s[i].cancel[j]) != 0)
			j++;
		if (moves_s[i].cancel[j] != NULL)
		{
			t += 1;
			break ;
		}
		next = next->next;
		if (!find_next_elem(&next))
			break ;
	}
	return (0);
}

void		cancelling_moves_opti(t_list *sol, int *opti, t_opti *moves_s)
{
	int				i;
	t_list			*cur;
	t_list			*next;

	cur = sol;
	if (!find_next_elem(&cur))
		return ;
	while (cur->content)
	{
		i = 0;
		while (ft_strcmp((char*)cur->content, moves_s[i].move) != 0)
			i++;
		next = cur->next;
		if (!find_next_elem(&next))
			return ;
		if (check_next_elems(cur, next, moves_s, i))
			*opti = 1;
		cur = cur->next;
		if (!find_next_elem(&cur))
			return ;
	}
}
