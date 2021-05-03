/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 09:28:44 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 11:19:09 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_color(t_last *last, int const i, int const s)
{
	int		j;

	j = 0;
	while (j < last->n)
	{
		if (last->i[j] == i && last->s[j] == s)
			return (1);
		j++;
	}
	return (0);
}

static void	display_first_lines(t_stack *stacks, t_arg *arg
				, char const *buf, t_last *last)
{
	printf("Last: ");
	if (arg->color)
	{
		printf("%s%s%s\n", RED, buf, NC);
		printf("%s%12s%s | %s%-12s%s\n", BLUE, "Stack A", NC
				, BLUE, "Stack B", NC);
		define_last(stacks, buf, last);
	}
	else
	{
		printf("%s\n", buf);
		printf("%12s | %-12s\n", "Stack A", "Stack B");
	}
}

static void	display_line(t_stack *stacks, t_arg *arg
				, t_last *last, int const i)
{
	if (i < stacks[0].size)
	{
		if (arg->color && check_color(last, i, 0))
			printf("%s%12d%s |", GREEN, stacks[0].arr[i], NC);
		else
			printf("%12d |", stacks[0].arr[i]);
	}
	else
		printf("%*c |", 12, ' ');
	if (i < stacks[1].size)
	{
		if (arg->color && check_color(last, i, 1))
			printf("%s%-12d%s\n", GREEN, stacks[1].arr[i], NC);
		else
			printf("%-12d\n", stacks[1].arr[i]);
	}
	else
		printf("\n");
}

void		show_stack(t_stack *stacks, t_arg *arg, char const *buf)
{
	char	*term_str;
	int		i;
	t_last	last;

	term_str = tgetstr("cl", NULL);
	fputs(term_str, stdout);
	display_first_lines(stacks, arg, buf, &last);
	i = 0;
	while (i < stacks[0].size || i < stacks[1].size)
	{
		display_line(stacks, arg, &last, i);
		i++;
	}
	usleep(500000);
}
