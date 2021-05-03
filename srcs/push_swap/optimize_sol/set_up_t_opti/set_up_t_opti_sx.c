/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_t_opti_sx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:55:32 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/29 11:58:45 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_up_t_opti_sa(t_opti *moves_s, t_ft *moves)
{
	moves_s[0].move = moves[SA].str;
	moves_s[0].move_op = moves[SA].str;
	moves_s[0].cancel[0] = moves[SS].str;
	moves_s[0].cancel[1] = moves[PA].str;
	moves_s[0].cancel[2] = moves[PB].str;
	moves_s[0].cancel[3] = moves[RA].str;
	moves_s[0].cancel[4] = moves[RR].str;
	moves_s[0].cancel[5] = moves[RRA].str;
	moves_s[0].cancel[6] = moves[RRR].str;
	moves_s[0].cancel[7] = NULL;
}

void	set_up_t_opti_sb(t_opti *moves_s, t_ft *moves)
{
	moves_s[1].move = moves[SB].str;
	moves_s[1].move_op = moves[SB].str;
	moves_s[1].cancel[0] = moves[SS].str;
	moves_s[1].cancel[1] = moves[PA].str;
	moves_s[1].cancel[2] = moves[PB].str;
	moves_s[1].cancel[3] = moves[RB].str;
	moves_s[1].cancel[4] = moves[RR].str;
	moves_s[1].cancel[5] = moves[RRB].str;
	moves_s[1].cancel[6] = moves[RRR].str;
	moves_s[1].cancel[7] = NULL;
}

void	set_up_t_opti_ss(t_opti *moves_s, t_ft *moves)
{
	moves_s[2].move = moves[SS].str;
	moves_s[2].move_op = moves[SS].str;
	moves_s[2].cancel[0] = moves[SA].str;
	moves_s[2].cancel[1] = moves[SB].str;
	moves_s[2].cancel[2] = moves[PA].str;
	moves_s[2].cancel[3] = moves[PB].str;
	moves_s[2].cancel[4] = moves[RA].str;
	moves_s[2].cancel[5] = moves[RB].str;
	moves_s[2].cancel[6] = moves[RR].str;
	moves_s[2].cancel[7] = moves[RRA].str;
	moves_s[2].cancel[8] = moves[RRB].str;
	moves_s[2].cancel[9] = moves[RRR].str;
	moves_s[2].cancel[10] = NULL;
}
