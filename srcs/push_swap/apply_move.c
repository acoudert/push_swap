/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 08:57:31 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/01 21:13:35 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	apply_move(t_data *data, t_stack *stacks, t_move_ft ft, char *str)
{
	(*ft)(stacks);
	ft_lstadd_back(&data->sol, ft_lstnew(str));
}
