/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_last_rx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 10:45:38 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 10:49:20 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	define_last_rx(t_stack *stacks, char const *buf, t_last *last)
{
	if (ft_strcmp(buf, "ra") == 0)
	{
		last->n = 1;
		last->i[0] = stacks[0].size - 1;
		last->s[0] = 0;
	}
	else if (ft_strcmp(buf, "rb") == 0)
	{
		last->n = 1;
		last->i[0] = stacks[1].size - 1;
		last->s[0] = 1;
	}
	else if (ft_strcmp(buf, "rr") == 0)
	{
		last->n = 2;
		last->i[0] = stacks[0].size - 1;
		last->i[1] = stacks[1].size - 1;
		last->s[0] = 0;
		last->s[1] = 1;
	}
}
