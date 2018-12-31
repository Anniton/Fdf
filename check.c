/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:13:49 by aquan             #+#    #+#             */
/*   Updated: 2018/12/31 13:59:51 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define BUFF_SIZE 2048
#include <stdio.h>

int		ft_count_y(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			++count;
		++i;
	}
	return (count);
}

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
int		ft_checkline(char *s)
{
	int i;
	int count;
	int x_len;

	x_len = 0;
	i = 0;
	count = 0;
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

int		samplevalidity(char *argv)
{
	int		fd;
	int		ret;
	char	buf[BUFF_SIZE];
	int 	x;

	if ((fd = open(argv, O_RDONLY)) == -1)
	{
		write(1, "Error\n", 6);
		return (0);
	}	
	if ((ret = read(fd, buf, BUFF_SIZE)) <= 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	x = ft_checkline(buf);
	close(fd);
	return (x);
}
