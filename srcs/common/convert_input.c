/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:12:29 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/01 21:25:57 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static char		prepare_stacks(int ac, t_stack *stacks)
{
	stacks[0].arr = NULL;
	stacks[1].arr = NULL;
	stacks[0].size = 0;
	stacks[1].size = 0;
	if (!(stacks[0].arr = (int*)malloc(sizeof(int) * (ac - 1))))
		return (0);
	if (!(stacks[1].arr = (int*)malloc(sizeof(int) * (ac - 1))))
		return (0);
	return (1);
}

/*
** Check if str is a number
** Return: 0 if error | 1 if ok
*/

static char		is_nb(char const *str)
{
	size_t		i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] != '-' && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static char		duplicate(t_stack *stacks)
{
	int			i;
	int			j;

	i = 0;
	while (i < stacks[0].size)
	{
		j = 0;
		while (j < i)
		{
			if (stacks[0].arr[j] == stacks[0].arr[i])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
** Convert av into list
** Return: 0 if error | 1 if ok
*/

char			convert_input(int ac, char const **av, t_stack *stacks
					, t_is_arg_ft ft)
{
	size_t		i;
	size_t		j;

	if (!prepare_stacks(ac, stacks))
		return (0);
	if (ac == 1)
		return (0);
	i = 0;
	j = 0;
	while (av[++i])
	{
		if (is_nb(av[i]) && ft_atoi(av[i]) >= -2147483648
						&& ft_atoi(av[i]) <= 2147483647)
		{
			stacks[0].arr[i - j - 1] = ft_atoi(av[i]);
			stacks[0].size += 1;
		}
		else if ((*ft)(av[i]))
			j += 1;
		else
			return (0);
	}
	if (duplicate(stacks))
		return (0);
	return (1);
}
