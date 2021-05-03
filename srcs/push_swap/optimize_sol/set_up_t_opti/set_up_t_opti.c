/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_up_t_opti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 11:52:35 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/29 12:04:30 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_up_t_opti(t_opti *moves_s, t_ft *moves)
{
	set_up_t_opti_sa(moves_s, moves);
	set_up_t_opti_sb(moves_s, moves);
	set_up_t_opti_ss(moves_s, moves);
	set_up_t_opti_pa(moves_s, moves);
	set_up_t_opti_pb(moves_s, moves);
	set_up_t_opti_ra(moves_s, moves);
	set_up_t_opti_rb(moves_s, moves);
	set_up_t_opti_rr(moves_s, moves);
	set_up_t_opti_rra(moves_s, moves);
	set_up_t_opti_rrb(moves_s, moves);
	set_up_t_opti_rrr(moves_s, moves);
}
