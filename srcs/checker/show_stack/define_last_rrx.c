/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_last_rrx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 10:46:53 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 10:50:08 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	define_last_rrx(t_stack *stacks, char const *buf, t_last *last)
{
	(void)stacks;
	if (ft_strcmp(buf, "rra") == 0)
	{
		last->n = 1;
		last->i[0] = 0;
		last->s[0] = 0;
	}
	else if (ft_strcmp(buf, "rrb") == 0)
	{
		last->n = 1;
		last->i[0] = 0;
		last->s[0] = 1;
	}
	else if (ft_strcmp(buf, "rrr") == 0)
	{
		last->n = 2;
		last->i[0] = 0;
		last->i[1] = 0;
		last->s[0] = 0;
		last->s[1] = 1;
	}
}
