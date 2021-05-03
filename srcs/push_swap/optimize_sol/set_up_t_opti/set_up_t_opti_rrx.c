/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_t_opti_rrx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:55:32 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/29 12:04:16 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_up_t_opti_rra(t_opti *moves_s, t_ft *moves)
{
	moves_s[8].move = moves[RRA].str;
	moves_s[8].move_op = moves[RA].str;
	moves_s[8].cancel[0] = moves[SA].str;
	moves_s[8].cancel[1] = moves[SS].str;
	moves_s[8].cancel[2] = moves[PA].str;
	moves_s[8].cancel[3] = moves[PB].str;
	moves_s[8].cancel[4] = moves[RR].str;
	moves_s[8].cancel[5] = moves[RRA].str;
	moves_s[8].cancel[6] = moves[RRR].str;
	moves_s[8].cancel[7] = NULL;
}

void	set_up_t_opti_rrb(t_opti *moves_s, t_ft *moves)
{
	moves_s[9].move = moves[RRB].str;
	moves_s[9].move_op = moves[RB].str;
	moves_s[9].cancel[0] = moves[SB].str;
	moves_s[9].cancel[1] = moves[SS].str;
	moves_s[9].cancel[2] = moves[PA].str;
	moves_s[9].cancel[3] = moves[PB].str;
	moves_s[9].cancel[4] = moves[RR].str;
	moves_s[9].cancel[5] = moves[RRB].str;
	moves_s[9].cancel[6] = moves[RRR].str;
	moves_s[9].cancel[7] = NULL;
}

void	set_up_t_opti_rrr(t_opti *moves_s, t_ft *moves)
{
	moves_s[10].move = moves[RRR].str;
	moves_s[10].move_op = moves[RR].str;
	moves_s[10].cancel[0] = moves[SA].str;
	moves_s[10].cancel[1] = moves[SB].str;
	moves_s[10].cancel[2] = moves[SS].str;
	moves_s[10].cancel[3] = moves[PA].str;
	moves_s[10].cancel[4] = moves[PB].str;
	moves_s[10].cancel[5] = moves[RA].str;
	moves_s[10].cancel[6] = moves[RB].str;
	moves_s[10].cancel[7] = moves[RRA].str;
	moves_s[10].cancel[8] = moves[RRB].str;
	moves_s[10].cancel[9] = moves[RRR].str;
	moves_s[10].cancel[10] = NULL;
}
