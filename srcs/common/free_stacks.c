/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:51:53 by acoudert          #+#    #+#             */
/*   Updated: 2021/04/27 13:18:13 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	free_stacks(t_stack *stacks)
{
	if (stacks[0].arr)
		free(stacks[0].arr);
	if (stacks[1].arr)
		free(stacks[1].arr);
}
