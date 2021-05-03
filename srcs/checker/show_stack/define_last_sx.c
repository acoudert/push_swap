/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_last_sx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 10:40:28 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 10:57:55 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void		define_last_sa(char const *buf, t_last *last)
{
	if (ft_strcmp(buf, "sa") == 0)
	{
		last->n = 2;
		last->i[0] = 0;
		last->i[1] = 1;
		last->s[0] = 0;
		last->s[1] = 0;
	}
}

static void		define_last_sb(char const *buf, t_last *last)
{
	if (ft_strcmp(buf, "sb") == 0)
	{
		last->n = 2;
		last->i[0] = 0;
		last->i[1] = 1;
		last->s[0] = 1;
		last->s[1] = 1;
	}
}

static void		define_last_ss(char const *buf, t_last *last)
{
	if (ft_strcmp(buf, "ss") == 0)
	{
		last->n = 4;
		last->i[0] = 0;
		last->i[1] = 1;
		last->i[2] = 0;
		last->i[3] = 1;
		last->s[0] = 0;
		last->s[1] = 0;
		last->s[2] = 1;
		last->s[3] = 1;
	}
}

void			define_last_sx(t_stack *stacks, char const *buf
					, t_last *last)
{
	(void)stacks;
	define_last_sa(buf, last);
	define_last_sb(buf, last);
	define_last_ss(buf, last);
}
