/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:50:20 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 11:49:04 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	apply_move(t_stack *stacks, t_ft *moves, char *buf)
{
	int			i;

	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(moves[i].str, buf, ft_strlen(buf)) == 0)
		{
			moves[i].ft(stacks);
			return (1);
		}
		i++;
	}
	return (0);
}

static char	checker(t_stack *stacks, t_ft *moves, t_arg *arg)
{
	int			ret;
	char		*buf;

	buf = NULL;
	while ((ret = get_next_line(STDIN_FILENO, &buf)) > 0)
	{
		if (!apply_move(stacks, moves, buf))
		{
			free(buf);
			return (0);
		}
		if (arg->verbose)
			show_stack(stacks, arg, buf);
		free(buf);
		buf = NULL;
	}
	if (ret == 0)
		free(buf);
	return (1);
}

/*
** stacks[0] = Stack A | stacks[1] = Stack B
*/

int			main(int ac, char const **av)
{
	t_stack		stacks[2];
	t_ft		moves[11];
	t_arg		arg;
	char		buf[1024];

	if (ac == 1)
		return (0);
	if (!convert_input(ac, av, stacks, &is_arg))
		return (error(stacks));
	set_up_arg(&arg, av);
	if (arg.verbose)
		tgetent(buf, getenv("TERM"));
	set_up_t_ft(moves);
	if (!checker(stacks, moves, &arg))
		return (error(stacks));
	if (is_sorted(stacks))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stacks(stacks);
	return (0);
}
