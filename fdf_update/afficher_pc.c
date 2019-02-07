/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher_pc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:10:52 by aquan             #+#    #+#             */
/*   Updated: 2019/02/07 16:28:29 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_alt_pc(t_struct *start, int y, int x)
{
	int alt;

	alt = (start->final[y][x] - 0.5 * cos(30) * y);
	return (alt);
}

void	segment_x_pc(t_struct *start, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int centre_x;
	int centre_y;

	//	centre_x = start->tool->left;
	//	centre_y = start->tool->up;
	centre_x = (start->win_w / 2 - (start->nb_x) * start->tool->step / 2) - 200 + start->tool->left;
	centre_y = (start->win_h / 2 - (start->nb_y * start->tool->step) / 2) - 200 + start->tool->up;

	i.x = centre_x + x * (start->tool->step) + (0.5 * cos(30) * y) * (start->tool->step);
	i.y = centre_y + y * 0.5 * (start->tool->step) - (get_alt_pc(start, y, x));
	f.x = centre_x + (x + 1) * (start->tool->step) +
		(0.5 * cos(30) * y) * (start->tool->step);
	f.y = centre_y + y * 0.5 * (start->tool->step) - (get_alt_pc(start, y, (x + 1)));
	ligne_1(start, &i, &f);
}

void	segment_y_pc(t_struct *start, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int centre_x;
	int centre_y;

	centre_x = (start->win_w / 2 - (start->nb_x) * start->tool->step / 2) - 200 + start->tool->left;
	centre_y = (start->win_h / 2 - (start->nb_y * start->tool->step) / 2) - 200 + start->tool->up;
	i.x = centre_x + x * (start->tool->step) + (0.5 * cos(30) * y) * (start->tool->step);
	i.y = centre_y + y * 0.5 * (start->tool->step) - (get_alt_pc(start, y, x));
	f.x = centre_x + x * (start->tool->step) +
		(0.5 * cos(30) * (y + 1)) * (start->tool->step);
	f.y = centre_y + (y + 1) * 0.5 * (start->tool->step) -
		(get_alt_pc(start, (y + 1), x));
	ligne_1(start, &i, &f);
}

int	afficher_pc(t_struct *start)
{
	int x;
	int y;
	y = 0;
	while (y < start->nb_y)
	{
		x = 0;
		while (x < start->nb_x)
		{
			if (x != start->nb_x - 1)
				segment_x_pc(start, y, x);
			if (y != start->nb_y - 1)
				segment_y_pc(start, y, x);
			x++;
		}
		y++;
	}
	return(0);
}
