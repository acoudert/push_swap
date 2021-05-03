/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_last_px.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 10:43:43 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 10:57:48 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	define_last_px(t_stack *stacks, char const *buf, t_last *last)
{
	(void)stacks;
	if (ft_strcmp(buf, "pa") == 0)
	{
		last->n = 1;
		last->i[0] = 0;
		last->s[0] = 0;
	}
	else if (ft_strcmp(buf, "pb") == 0)
	{
		last->n = 1;
		last->i[0] = 0;
		last->s[0] = 1;
	}
}
