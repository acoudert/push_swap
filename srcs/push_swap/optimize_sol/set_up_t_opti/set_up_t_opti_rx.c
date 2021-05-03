/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_t_opti_rx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:55:32 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/29 12:02:22 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_up_t_opti_ra(t_opti *moves_s, t_ft *moves)
{
	moves_s[5].move = moves[RA].str;
	moves_s[5].move_op = moves[RRA].str;
	moves_s[5].cancel[0] = moves[SA].str;
	moves_s[5].cancel[1] = moves[SS].str;
	moves_s[5].cancel[2] = moves[PA].str;
	moves_s[5].cancel[3] = moves[PB].str;
	moves_s[5].cancel[4] = moves[RA].str;
	moves_s[5].cancel[5] = moves[RR].str;
	moves_s[5].cancel[6] = moves[RRR].str;
	moves_s[5].cancel[7] = NULL;
}

void	set_up_t_opti_rb(t_opti *moves_s, t_ft *moves)
{
	moves_s[6].move = moves[RB].str;
	moves_s[6].move_op = moves[RRB].str;
	moves_s[6].cancel[0] = moves[SB].str;
	moves_s[6].cancel[1] = moves[SS].str;
	moves_s[6].cancel[2] = moves[PA].str;
	moves_s[6].cancel[3] = moves[PB].str;
	moves_s[6].cancel[4] = moves[RB].str;
	moves_s[6].cancel[5] = moves[RR].str;
	moves_s[6].cancel[6] = moves[RRR].str;
	moves_s[6].cancel[7] = NULL;
}

void	set_up_t_opti_rr(t_opti *moves_s, t_ft *moves)
{
	moves_s[7].move = moves[RR].str;
	moves_s[7].move_op = moves[RRR].str;
	moves_s[7].cancel[0] = moves[SA].str;
	moves_s[7].cancel[1] = moves[SB].str;
	moves_s[7].cancel[2] = moves[SS].str;
	moves_s[7].cancel[3] = moves[PA].str;
	moves_s[7].cancel[4] = moves[PB].str;
	moves_s[7].cancel[5] = moves[RA].str;
	moves_s[7].cancel[6] = moves[RB].str;
	moves_s[7].cancel[7] = moves[RR].str;
	moves_s[7].cancel[8] = moves[RRA].str;
	moves_s[7].cancel[9] = moves[RRB].str;
	moves_s[7].cancel[10] = NULL;
}
