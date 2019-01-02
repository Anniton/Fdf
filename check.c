/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 14:50:21 by aquan             #+#    #+#             */
/*   Updated: 2019/01/02 11:17:02 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

int		ft_count_x(char *s, int *i)
{
	int n;

	n = 0;
	if (s[*i] == ' ' || s[*i] == '-')
		++(*i);
	while (s[*i + 1] && ft_isdigit(s[*i + 1]))
		++(*i);
	if (s[*i] == ',')
	{
		if (s[*i + 1] == '0' && s[*i + 2] == 'x')
		{
			*i += 3;
			while (s[*i + n] && ((s[*i + n] >= 'a' && s[*i + n] <= 'f') ||
						(s[*i + n] >= 'A' && s[*i + n] <= 'F') || ft_isdigit(s[*i + n])))
				++n;
		}
		else
			return (0);
		if (n > 8)
			return (0);
		*i += n;
	}
	return (1);
}
int		ft_countline(char *s)
{
	
	ft_strsplit(s, ' ');
	while (s[i] && s[i] != '\n')
	{
		
	}
}
int		ft_count_y(char *s, t_struct *start)
{
	int y_len;
	int j;
	int i;
	int a;

	i = 0;
	y_len = 0;
	j = 0;
	a = ft_checkfirstline(s, start);	
	while (s[i])
	{
		if (s[i] && s[i] == '\n' && ((ft_checkline(s + j) == start->firstline)))
		{
			j += (a + 1);
			++y_len;
		}
		else if (s[i] && s[i] =='\n' && (ft_checkline(s + j) != start->firstline))
		{	
			write(1, "wrong sample\n", 13);
			return (0);
		}
		++i;
	}
	return (y_len);
}

int		ft_checkfirstline(char *s, t_struct *start)
{
	int i;

	start->firstline = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (ft_isdigit(s[i]))
		{
			if (!(ft_count_x(s, &i)))
				return (0);
			++(start->firstline);
		}
		++i;
	}
	return (i);
}


int		ft_checkline(char *s)
{
	int i;
	int x_len;

	x_len = 0;
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		if (ft_isdigit(s[i]))
		{
			if (!(ft_count_x(s, &i)))
				return (0);
			++x_len;
		}
		++i;
	}
	return (x_len);
}

int		samplevalidity(char *argv, t_struct *start)
{
	int		fd;
	int		ret;
	char	buf[SIZE];

	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if ((ret = read(fd, buf, SIZE)) <= 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	start->nb_y = ft_count_y(buf, start);
	start->nb_x = ft_checkline(buf);
	close(fd);
	return (1);
}
