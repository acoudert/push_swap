/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_t_opti_px.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:55:32 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/29 12:00:09 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_up_t_opti_pa(t_opti *moves_s, t_ft *moves)
{
	moves_s[3].move = moves[PA].str;
	moves_s[3].move_op = moves[PB].str;
	moves_s[3].cancel[0] = moves[SA].str;
	moves_s[3].cancel[1] = moves[SB].str;
	moves_s[3].cancel[2] = moves[SS].str;
	moves_s[3].cancel[3] = moves[PA].str;
	moves_s[3].cancel[4] = moves[RA].str;
	moves_s[3].cancel[5] = moves[RB].str;
	moves_s[3].cancel[6] = moves[RR].str;
	moves_s[3].cancel[7] = moves[RRA].str;
	moves_s[3].cancel[8] = moves[RRB].str;
	moves_s[3].cancel[9] = moves[RRR].str;
	moves_s[3].cancel[10] = NULL;
}

void	set_up_t_opti_pb(t_opti *moves_s, t_ft *moves)
{
	moves_s[4].move = moves[PB].str;
	moves_s[4].move_op = moves[PA].str;
	moves_s[4].cancel[0] = moves[SA].str;
	moves_s[4].cancel[1] = moves[SB].str;
	moves_s[4].cancel[2] = moves[SS].str;
	moves_s[4].cancel[3] = moves[PB].str;
	moves_s[4].cancel[4] = moves[RA].str;
	moves_s[4].cancel[5] = moves[RB].str;
	moves_s[4].cancel[6] = moves[RR].str;
	moves_s[4].cancel[7] = moves[RRA].str;
	moves_s[4].cancel[8] = moves[RRB].str;
	moves_s[4].cancel[9] = moves[RRR].str;
	moves_s[4].cancel[10] = NULL;
}
