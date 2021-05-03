/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_last.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 10:35:50 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 10:48:08 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void		define_last(t_stack *stacks, char const *buf, t_last *last)
{
	define_last_sx(stacks, buf, last);
	define_last_px(stacks, buf, last);
	define_last_rx(stacks, buf, last);
	define_last_rrx(stacks, buf, last);
}
