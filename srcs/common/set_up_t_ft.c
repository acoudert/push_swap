/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_t_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 10:32:23 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 08:28:38 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	set_up_sx(t_ft *moves)
{
	int		i;

	i = -1;
	while (++i < 3)
		moves[i].str[0] = 's';
	moves[0].str[1] = 'a';
	moves[1].str[1] = 'b';
	moves[2].str[1] = 's';
	moves[0].str[2] = 0;
	moves[1].str[2] = 0;
	moves[2].str[2] = 0;
	moves[0].ft = &move_sa;
	moves[1].ft = &move_sb;
	moves[2].ft = &move_ss;
	moves[0].op = &move_sa;
	moves[1].op = &move_sb;
	moves[2].op = &move_ss;
}

static void	set_up_px(t_ft *moves)
{
	int		i;

	i = 2;
	while (++i < 5)
		moves[i].str[0] = 'p';
	moves[3].str[1] = 'a';
	moves[4].str[1] = 'b';
	moves[3].str[2] = 0;
	moves[4].str[2] = 0;
	moves[3].ft = &move_pa;
	moves[4].ft = &move_pb;
	moves[3].op = &move_pb;
	moves[4].op = &move_pa;
}

static void	set_up_rx(t_ft *moves)
{
	int		i;

	i = 4;
	while (++i < 8)
		moves[i].str[0] = 'r';
	moves[5].str[1] = 'a';
	moves[6].str[1] = 'b';
	moves[7].str[1] = 'r';
	moves[5].str[2] = 0;
	moves[6].str[2] = 0;
	moves[7].str[2] = 0;
	moves[5].ft = &move_ra;
	moves[6].ft = &move_rb;
	moves[7].ft = &move_rr;
	moves[5].op = &move_rra;
	moves[6].op = &move_rrb;
	moves[7].op = &move_rrr;
}

static void	set_up_rrx(t_ft *moves)
{
	int		i;

	i = 7;
	while (++i < 11)
		moves[i].str[0] = 'r';
	moves[8].str[1] = 'r';
	moves[9].str[1] = 'r';
	moves[10].str[1] = 'r';
	moves[8].str[2] = 'a';
	moves[9].str[2] = 'b';
	moves[10].str[2] = 'r';
	moves[8].str[3] = 0;
	moves[9].str[3] = 0;
	moves[10].str[3] = 0;
	moves[8].ft = &move_rra;
	moves[9].ft = &move_rrb;
	moves[10].ft = &move_rrr;
	moves[8].op = &move_ra;
	moves[9].op = &move_rb;
	moves[10].op = &move_rr;
}

void		set_up_t_ft(t_ft *moves)
{
	set_up_sx(moves);
	set_up_px(moves);
	set_up_rx(moves);
	set_up_rrx(moves);
}
