/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:39:11 by aquan             #+#    #+#             */
/*   Updated: 2019/02/06 20:11:37 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
int		calc_iso(t_vector_2d *p1, int z)
{
	int		tmp_x;
	int		tmp_y;

	tmp_x = p1->x - p1->y;
	tmp_y = (p1->x + p1->y) / 2 - z;
	p1->x = tmp_x;
	p1->y = tmp_y;
	return (SUCCESS);
}

int		print(t_struct *env)
{
	int		i;
	int		j;
	t_vector_2d 	p1, p2;

	i = 0;
	while (i < env->nb_y)
	{
		j = 0;
		while (j < env->nb_x)
		{
			p1.y = i * env->tool->zoom;
			p1.x = j * env->tool->zoom;
			p2.y = i * env->tool->zoom;
			p2.x = j + 1 * env->tool->zoom;
			calc_iso(&p1, env->final[i][j]);
			if (j < env->nb_x)
				calc_iso(&p2, env->final[i][j+1]);
			bresenham(&p1, &p2, env);
			p1.y = i * env->tool->zoom;
			p1.x = j * env->tool->zoom;
			p2.y = i + 1 * env->tool->zoom;
			p2.x = j * env->tool->zoom;
			calc_iso(&p1, env->final[i][j]);
			if (i < env->nb_y)
				calc_iso(&p2, env->final[i+1][j]);
			bresenham(&p1, &p2, env);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

*/
void	segment_x(t_struct *start, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int centre_x;
	int centre_y;

	centre_x = start->tool->left;
	centre_y = start->tool->up;
	i.x = centre_x + x - y * start->tool->step;
	i.y = centre_y + x / 2 + y * start->tool->step / 2 - (get_alt(start, y, x) + start->tool->step);
	f.x = centre_x + (x + 1) - y * start->tool->step;
	f.y = centre_y + (x + 1) / 2 + y * start->tool->step / 2 - (get_alt(start, y, x + 1) + start->tool->step);
	ligne_1(start, &i, &f);
}

void	segment_y(t_struct *start, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int centre_x;
	int centre_y;

	centre_x = start->tool->left;
	centre_y = start->tool->up;
	i.x = centre_x + x - y * start->tool->step;
	i.y = centre_y + x / 2 + y * start->tool->step / 2 - (get_alt(start, y, x) + start->tool->step);
	f.x = centre_x + x - (y + 1) * start->tool->step;
	f.y = centre_y + x / 2 + (y + 1) * start->tool->step / 2 - (get_alt(start, y + 1, x) + start->tool->step);
	ligne_1(start, &i, &f);
}
