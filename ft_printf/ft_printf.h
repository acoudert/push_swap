/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 09:03:49 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 11:26:44 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef FT_TAB_SIZE
#  define FT_TAB_SIZE	10
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct		s_dataf
{
	int				count;
	int				curr_len;
	char			indic;
	int				width;
	char			dot;
	int				prec;
	char			size[2];
	char			type;
}					t_dataf;

typedef void		(*t_str)(t_dataf*, void *);

typedef struct		s_ftp
{
	char			type;
	t_str			ft;
}					t_ftp;

typedef struct		s_dbl
{
	long long		n1;
	long long		n2;
	int				n3;
	int				len1;
	int				len2;
}					t_dbl;

void				ft_free_struct(t_dataf *data);
int					ft_printf(const char *format, ...);

void				ft_init_dataf_struct(t_dataf *data);
void				ft_init_flags(t_dataf *data);
void				ft_init_ft_tab(t_ftp *ft_tab);

int					ft_parser(t_dataf *data, va_list args, char *format);
int					ft_flags(t_dataf *data, char *format, int i, va_list args);
int					ft_args(t_dataf *data, va_list args);

void				ft_char(t_dataf *data, void *arg);
void				ft_str(t_dataf *data, void *arg);
void				ft_ptr(t_dataf *data, void *arg);
void				ft_s_nb(t_dataf *data, void *arg);
void				ft_u_nb(t_dataf *data, void *arg);
void				ft_hex(t_dataf *data, void *arg);
void				ft_perc(t_dataf *data, void *arg);
void				ft_n(t_dataf *data, void *arg);

void				ft_init_f_struct(t_dataf *data, t_dbl *nb, double arg);
t_dbl				ft_f(t_dataf *data, double arg, int print);

void				ft_init_e_struct(t_dataf *data, t_dbl *nb, double arg);
t_dbl				ft_e(t_dataf *data, double arg, int print);

void				ft_g(t_dataf *data, double arg);

void				ft_putchar(char c);
void				ft_put_nspace(int n);
void				ft_put_nstr(char *str, int len);
void				ft_put_s_nb(long long nb, int len);
void				ft_put_u_nb(unsigned long long nb, int len);
void				ft_put_hex(unsigned long long nb, int len, int type);

int					ft_strlenp(char *str);
int					ft_s_nb_len(long long nb);
int					ft_u_nb_len(unsigned long long nb);
int					ft_hex_len(unsigned long long nb);

long long			ft_s_nb_cast(char *size, void *nb);
unsigned long long	ft_u_nb_cast(char *size, void *nb);

#endif
