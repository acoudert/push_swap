/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:32:54 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 11:19:55 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdio.h>
# include <termcap.h>

# include "libft.h"
# include "get_next_line.h"
# include "ft_printf.h"
# include "common.h"

# define RED	"\033[0;31m"
# define GREEN	"\033[0;32m"
# define BLUE	"\033[0;34m"
# define NC		"\033[0m"

typedef struct	s_arg
{
	char	verbose;
	char	color;
}				t_arg;

typedef struct	s_last
{
	int			n;
	int			i[4];
	int			s[4];
}				t_last;

char			is_arg(char const *str);
void			set_up_arg(t_arg *arg, char const **av);

void			show_stack(t_stack *stacks, t_arg *arg, char const *move);
void			define_last(t_stack *stacks, char const *buf, t_last *last);
void			define_last_sx(t_stack *stacks, char const *buf, t_last *last);
void			define_last_px(t_stack *stacks, char const *buf, t_last *last);
void			define_last_rx(t_stack *stacks, char const *buf, t_last *last);
void			define_last_rrx(t_stack *stacks, char const *buf, t_last *last);

#endif
