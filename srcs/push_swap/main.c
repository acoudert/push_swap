/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 11:50:20 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 11:21:14 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			display_sol(t_list *sol)
{
	int		i;

	i = 0;
	while (sol)
	{
		if (sol->content)
		{
			i += 1;
			ft_printf("%s\n", (char*)sol->content);
		}
		sol = sol->next;
	}
}

static void		sorting_algorithms_launcher(t_data *data
					, t_ft *moves, t_arg *arg)
{
	if (arg->min_sort || arg->all_sort)
		min_sort(&data[0], moves);
	if (arg->recursive_sort || arg->all_sort)
		recursive_sort(&data[1], moves);
	if (arg->chunk_recursive_sort)
		chunk_recursive_sort(&data[2], moves);
	if (arg->quick_sort || arg->all_sort)
		quick_sort(&data[3], moves);
}

static void		handle_sol(t_data *data, int const *size)
{
	int		i;
	int		j;
	int		smallest_sol;

	i = -1;
	j = 0;
	smallest_sol = 2147483647;
	while (++i < SORT_NB)
	{
		if (data[i].found && size[i] < smallest_sol)
		{
			smallest_sol = size[i];
			j = i;
		}
	}
	display_sol(data[j].sol);
}

/*
** data[0] | size[0] => min_sort
** data[1] | size[1] => recurisve_sort
** data[2] | size[2] => chunk_recursive_sort
** data[3] | size[3] => quick_sort
*/

static void		solve(t_stack *stacks, t_ft *moves, t_arg *arg)
{
	int		i;
	int		size[SORT_NB];
	t_data	data[SORT_NB];

	set_up_data(data, stacks);
	sorting_algorithms_launcher(data, moves, arg);
	i = -1;
	while (++i < SORT_NB)
	{
		optimize_sol(data[i].sol, moves);
		size[i] = actual_size(data[i].sol);
	}
	if (arg->size == 1)
		display_sizes(data, size);
	else
		handle_sol(data, size);
	free_data(data);
}

/*
** stacks[0] = Stack A | stacks[1] = Stack B
*/

int				main(int ac, char const **av)
{
	t_stack		stacks[2];
	t_ft		moves[11];
	t_arg		arg;

	if (ac == 1)
		return (0);
	if (!convert_input(ac, av, stacks, &is_arg))
		return (error(stacks));
	set_up_arg(&arg, av);
	set_up_t_ft(moves);
	solve(stacks, moves, &arg);
	free_stacks(stacks);
	return (0);
}
