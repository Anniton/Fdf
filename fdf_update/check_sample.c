/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sample.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:13:20 by aquan             #+#    #+#             */
/*   Updated: 2019/02/07 18:29:47 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_x(char *s)
{
	int i;

	i = 0;
	while(s[i])
	{
		if (s[i] == '-')
		{
			if(i != 0)
				if (!(ft_isspace(s[i - 1])))
					return(0);
			if(ft_isdigit(s[i + 1]))
				i++;
			else 
				return (0);
		}
		if(!(ft_isdigit(s[i])) && !(ft_isspace(s[i])))
			return(0);
		i++;
	}
	return(1);
}

int	ft_arrlen(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

int		*ft_convert(char **tab)
{
	int	*tab_int;
	int	len;
	int	i;

	len = ft_arrlen(tab);
	if (!(tab_int = (int*)malloc(sizeof(*tab_int) * len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		tab_int[i] = ft_atoi(tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
	return (tab_int);
}

void	ft_arrcpy(int **src, int **dst, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		if (!(dst[i] = (int*)malloc(sizeof(int) * width)))
			return ;
		j = 0;
		while (j < width)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		free(src[i]);
		i++;
	}
	free(src);
}

int	check_sample_validity(int fd, t_struct *start)
{
	char	*line;
	char	**s_split;
	int		**tab;
	int		**tmp;
	int		len;
	int		len_of_a_line;

	len = 0;
	tab = NULL;
	start->firstline = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (tab)
			tmp = tab;
		if (!(tab = (int**)ft_memalloc(sizeof(int*) * (len + 1))))
			return (0);
		if (!(ft_check_x(line)))
			return(0);
		s_split = ft_strsplit(line, ' ');
		free(line);
		if (start->firstline == 0)
		{
			start->nb_x = ft_arrlen(s_split);
			start->firstline = 1;
		}
		len_of_a_line = ft_arrlen(s_split);
		if (len_of_a_line < start->nb_x)
			return (0);
		if (len > 0)
			ft_arrcpy(tmp, tab, len, len_of_a_line);
		tab[len] = ft_convert(s_split);
		len++;
	}
	start->nb_y = len;
	start->final = tab;
	return(1);
}
