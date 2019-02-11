/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 12:28:21 by aquan             #+#    #+#             */
/*   Updated: 2019/02/11 14:46:00 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_x(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '-')
		{
			if (i != 0)
				if (!(ft_isspace(s[i - 1])))
					return (0);
			if (ft_isdigit(s[i + 1]))
				i++;
			else
				return (0);
		}
		if (!(ft_isdigit(s[i])) && !(ft_isspace(s[i])))
			return (0);
		i++;
	}
	return (1);
}

int		ft_arrlen(char **arr)
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

void		ft_arrcpy(int **src, int **dst, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	if (src == NULL)
		return ;
	while (i < height)
	{
		if (!(dst[i] = (int*)malloc(sizeof(int) * (width))))
			return ;
		j = 0;
		while (j < width)
		{
			dst[i][j] = src[i][j];
			printf("height = %d width = %d src = %d i = %d j = %d\n", height, width ,src[i][j], i, j);
			j++;
		}
		free(src[i]);
		i++;
	}
	free(src);
}
