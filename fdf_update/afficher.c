/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 21:11:45 by aquan             #+#    #+#             */
/*   Updated: 2019/02/07 15:20:49 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_alt(t_struct *start, int y, int x)
{
	int alt;

	if (y >= start->nb_y || x >= start->nb_x)
		return (0);
	alt = start->final[y][x];
	return (alt);
}

void	segment_x(t_struct *start, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int centre_x;
	int centre_y;

	centre_x = (start->win_w / 2 - (start->nb_x) * start->tool->step / 2) + start->tool->left;
	centre_y = (start->win_h / 2 - (start->nb_y * start->tool->step) / 2) - 200 + start->tool->up;
	
	i.x = centre_x + x * (start->tool->step) - y * (start->tool->step);
	printf("VAL STEP IN SEG = %d\n", start->tool->step);
	i.y = centre_y + x * (start->tool->step) / 2 + y * (start->tool->step)
		/ 2 - (get_alt(start, y, x) + start->tool->step);
	f.x = centre_x + (x + 1) * (start->tool->step) - y * (start->tool->step);
	f.y = centre_y + (x + 1) * (start->tool->step) / 2 + y * (start->tool->step)
		/ 2 - (get_alt(start, y, x + 1) + start->tool->step);
	ligne_1(start, &i, &f);
}

void	segment_y(t_struct *start, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int centre_x;
	int centre_y;

//	centre_x = (start->win_w / 2 - (start->nb_x * (WIDTH + start->tool->step) / 2)) + start->tool->left;
//	centre_y = (start->win_h / 2 - (start->nb_y * (HEIGHT + start->tool->step) / 2)) + start->tool->up;
	centre_x = (start->win_w / 2 - (start->nb_x) * start->tool->step / 2) + start->tool->left;
	centre_y = (start->win_h / 2 - (start->nb_y * start->tool->step) / 2) - 200 + start->tool->up;

	i.x = centre_x + x * (start->tool->step) - y * (start->tool->step);
	i.y = centre_y + x * (start->tool->step) / 2 + y * (start->tool->step)
		/ 2 - (get_alt(start, y, x) + start->tool->step);
	f.x = centre_x + x * (start->tool->step) - (y + 1) * (start->tool->step);
	f.y = centre_y + x * (start->tool->step) / 2 + (y + 1) * (start->tool->step)
		/ 2 - (get_alt(start, y + 1, x) + start->tool->step);
	ligne_1(start, &i, &f);
}
	int		afficher(t_struct *start)
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
					segment_x(start, y, x);
				if (y != start->nb_y - 1)
					segment_y(start, y, x);
				x++;
			}
			y++;
		}
		return (0);
	}
