/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acoudert <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:45:21 by acoudert          #+#    #+#             */
/*   Updated: 2021/05/02 11:48:18 by acoudert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_listgnl		*ft_gnlfd_in_lst(int fd, t_listgnl **file_lst)
{
	t_listgnl			*curr;

	if (*file_lst == 0)
		if (!(*file_lst = ft_gnllstnew(fd)))
			return (0);
	curr = *file_lst;
	while (curr)
	{
		if (curr->fd == fd)
			return (curr);
		else if (curr->next == 0)
			if (!(curr->next = ft_gnllstnew(fd)))
				return (0);
		curr = curr->next;
	}
	return (0);
}

int				ft_gnlread_line(int fd, t_listgnl *curr)
{
	int					bytes;
	char				*buffer;
	char				*str_to_free;

	if (!(buffer = (char*)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (ERROR);
	while (ft_gnlstrchr(curr->str, '\n') == 0)
	{
		if ((bytes = read(fd, buffer, BUFFER_SIZE)) == ERROR)
		{
			free(buffer);
			return (ERROR);
		}
		buffer[bytes] = 0;
		str_to_free = curr->str;
		if (!(curr->str = ft_gnlstrjoin(curr->str, buffer)))
			return (ERROR);
		free(str_to_free);
		if (bytes < BUFFER_SIZE)
			break ;
	}
	free(buffer);
	return (1);
}

int				ft_gnlcreate_line(char **line, t_listgnl *curr)
{
	int					i;
	char				*buffer;
	int					ret_val;

	i = 0;
	while (curr->str[i] && curr->str[i] != '\n')
		i++;
	ret_val = (curr->str[i] == '\n') ? READ_LINE : END_FILE;
	if (!(*line = (char*)malloc(sizeof(char) * (i + 1))))
		return (ERROR);
	buffer = curr->str;
	curr->str = (curr->str[i] == '\n') ? curr->str + i + 1 : curr->str + i;
	if (!(curr->str = ft_gnlstrdup(curr->str)))
		return (ERROR);
	(*line)[i] = 0;
	while (--i >= 0)
		(*line)[i] = buffer[i];
	free(buffer);
	return (ret_val);
}

void			ft_gnlfree_lst(int fd, t_listgnl **file_lst)
{
	t_listgnl			*curr;
	t_listgnl			*next;

	curr = *file_lst;
	if (!curr)
		return ;
	if (curr->fd == fd)
	{
		*file_lst = (*file_lst)->next;
		(curr->str) ? free(curr->str) : 0;
		free(curr);
		return ;
	}
	while (curr && curr->next)
	{
		next = curr->next->next;
		if (curr->next->fd == fd)
		{
			(curr->next->str) ? free(curr->next->str) : 0;
			free(curr->next);
			curr->next = next;
		}
		curr = curr->next;
	}
}

int				get_next_line(int fd, char **line)
{
	static t_listgnl	*file_lst = 0;
	t_listgnl			*curr;
	int					ret_val;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERROR);
	if (!(curr = ft_gnlfd_in_lst(fd, &file_lst)))
	{
		ft_gnlfree_lst(fd, &file_lst);
		return (ERROR);
	}
	if (ft_gnlread_line(fd, curr) == ERROR)
	{
		ft_gnlfree_lst(fd, &file_lst);
		return (ERROR);
	}
	ret_val = ft_gnlcreate_line(line, curr);
	if (ret_val == ERROR || ret_val == END_FILE)
		ft_gnlfree_lst(fd, &file_lst);
	return (ret_val);
}
