/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:49:07 by cmoulini          #+#    #+#             */
/*   Updated: 2018/11/30 18:52:13 by cmoulini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_listgnl	*check_fd(const int fd, t_listgnl **list)
{
	t_listgnl	*new;
	t_listgnl	*now;

	now = *list;
	while (now)
	{
		if (now->fd == fd)
			return (now);
		now = now->next;
	}
	if (!(new = (t_listgnl*)malloc(sizeof(t_listgnl))))
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	new->next = *list;
	*list = new;
	return (new);
}

static void			fill_line(t_listgnl *list, char **line)
{
	char	*tmp;
	char	*var;

	if ((var = ft_strchr(list->str, '\n')))
	{
		tmp = list->str;
		*line = ft_strsub(tmp, 0, var - tmp);
		list->str = ft_strdup(var + 1);
		free(tmp);
	}
	else
	{
		*line = ft_strdup(list->str);
		ft_strclr(list->str);
	}
}

static int			read_fd(const int fd, t_listgnl *list)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	ret = 1;
	if (list->str == NULL)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		list->str = ft_strdup(buf);
	}
	while (!ft_strchr(list->str, '\n') && ret >= 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		tmp = list->str;
		if (!(list->str = ft_strjoin(list->str, buf)))
			return (-1);
		free(tmp);
		if (ret == 0)
			return (0);
	}
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_listgnl	*list = NULL;
	t_listgnl			*tmp;
	int					ret;

	if (fd < 0 || line == NULL || read(fd, 0, 0))
		return (-1);
	if (!(tmp = check_fd(fd, &list)))
		return (-1);
	if ((ret = read_fd(fd, tmp)) < 0)
		return (-1);
	fill_line(tmp, line);
	if (ft_strlen(tmp->str) == 0 && ret == 0 && ft_strlen(*line) == 0)
		return (0);
	return (1);
}
