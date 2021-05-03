/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:20:36 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 11:32:59 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char		is_arg(char const *str)
{
	if (ft_strncmp(str, "-h", ft_strlen(str)) == 0
			|| ft_strncmp(str, "-s", ft_strlen(str)) == 0
			|| ft_strncmp(str, "-m", ft_strlen(str)) == 0
			|| ft_strncmp(str, "-r", ft_strlen(str)) == 0
			|| ft_strncmp(str, "-c", ft_strlen(str)) == 0
			|| ft_strncmp(str, "-q", ft_strlen(str)) == 0)
		return (1);
	return (0);
}

static void	display_help(void)
{
	ft_printf("Usage: ./push_swap [OPTION]... [...]\n\n");
	ft_printf("Options:\n");
	ft_printf("\t-h : This help\n");
	ft_printf("\t-s : Display solution sizes\n");
	ft_printf("\t-m : Force min sort\n");
	ft_printf("\t-r : Force recursive sort\n");
	ft_printf("\t-c : Force chunk recursive sort\n");
	ft_printf("\t-q : Force quick sort\n");
	exit(0);
}

static void	init_arg(t_arg *arg)
{
	arg->size = 0;
	arg->min_sort = 0;
	arg->recursive_sort = 0;
	arg->chunk_recursive_sort = 0;
	arg->quick_sort = 0;
	arg->all_sort = 0;
}

void		set_up_arg(t_arg *arg, char const **av)
{
	int		i;

	init_arg(arg);
	i = 1;
	while (av[i])
	{
		if (ft_strncmp(av[i], "-h", ft_strlen(av[i])) == 0)
			display_help();
		if (ft_strncmp(av[i], "-s", ft_strlen(av[i])) == 0)
			arg->size = 1;
		if (ft_strncmp(av[i], "-m", ft_strlen(av[i])) == 0)
			arg->min_sort = 1;
		if (ft_strncmp(av[i], "-r", ft_strlen(av[i])) == 0)
			arg->recursive_sort = 1;
		if (ft_strncmp(av[i], "-c", ft_strlen(av[i])) == 0)
			arg->chunk_recursive_sort = 1;
		if (ft_strncmp(av[i], "-q", ft_strlen(av[i])) == 0)
			arg->quick_sort = 1;
		i++;
	}
	if (arg->min_sort == 0 && arg->recursive_sort == 0
			&& arg->chunk_recursive_sort == 0 && arg->quick_sort == 0)
		arg->all_sort = 1;
}
