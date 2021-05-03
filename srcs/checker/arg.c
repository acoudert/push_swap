/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 11:20:36 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 11:52:15 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char		is_arg(char const *str)
{
	if (ft_strncmp(str, "-h", ft_strlen(str)) == 0
			|| ft_strncmp(str, "-v", ft_strlen(str)) == 0
			|| ft_strncmp(str, "-c", ft_strlen(str)) == 0)
		return (1);
	return (0);
}

static void	display_help(void)
{
	ft_printf("Usage: ./checker [OPTION]... [...]\n\n");
	ft_printf("Options:\n");
	ft_printf("\t-h : This help\n");
	ft_printf("\t-v : Produce verbose output\n");
	ft_printf("\t-c : Display colors if verbose mode on\n");
	exit(0);
}

void		set_up_arg(t_arg *arg, char const **av)
{
	int		i;

	arg->verbose = 0;
	arg->color = 0;
	i = 1;
	while (av[i])
	{
		if (ft_strncmp(av[i], "-h", ft_strlen(av[i])) == 0)
			display_help();
		if (ft_strncmp(av[i], "-v", ft_strlen(av[i])) == 0)
			arg->verbose = 1;
		if (ft_strncmp(av[i], "-c", ft_strlen(av[i])) == 0)
			arg->color = 1;
		i++;
	}
}
