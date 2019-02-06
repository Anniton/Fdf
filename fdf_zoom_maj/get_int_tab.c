/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_int_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:15:02 by aquan             #+#    #+#             */
/*   Updated: 2019/02/06 15:37:04 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	**get_int_tab(int fd, t_struct *start)
{
	int 	**final;
	char	**tab;
	char	*line;
	int		x;
	int		y;

	y = 0;
	final = (int **)malloc(sizeof(int *) * start->nb_y);
	while (get_next_line(fd, &line) > 0)
	{
		x = 0;
		tab = ft_strsplit(line, ' ');
		final[y] = (int *)malloc(sizeof(int) * start->nb_x);
		while (tab[x])
		{
			final[y][x] = ft_atoi(&tab[x][0]);
			x++;
		}
		y++;
	}
	return (final);
}

void	print_int_tab(int **tab, t_struct *start)
{
	int x;
	int y;

	y = 0;
	while (y < start->nb_y)
	{
		x = 0;
		while(x < start->nb_x)
		{
			ft_putnbr(tab[y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
