/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:41:53 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/01 21:09:50 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	32
# endif

# include <unistd.h>
# include <stdlib.h>

enum				e_ret_val
{
	READ_LINE = 1,
	END_FILE = 0,
	ERROR = -1
};

typedef struct		s_listgnl
{
	struct s_listgnl	*next;
	char				*str;
	int					fd;
}					t_listgnl;

int					get_next_line(int fd, char **line);

t_listgnl			*ft_gnlfd_in_lst(int fd, t_listgnl **file_lst);
int					ft_gnlread_line(int fd, t_listgnl *curr);
int					ft_gnlcreate_line(char **line, t_listgnl *curr);
void				ft_gnlfree_lst(int fd, t_listgnl **file_lst);

t_listgnl			*ft_gnllstnew(int fd);
char				*ft_gnlstrchr(char *s, int c);
char				*ft_gnlstrjoin(char *s1, char *s2);
char				*ft_gnlstrdup(char *s);

#endif
