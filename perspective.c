/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perspective.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:10:52 by aquan             #+#    #+#             */
/*   Updated: 2019/02/08 20:09:48 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_alt_pc(t_struct *env, int y, int x)
{
	int alt;

	alt = (env->final[y][x] - 0.5 * cos(30) * y);
	return (alt);
}

static void		segment_x_pc(t_struct *env, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int			centre_x;
	int			centre_y;

	//	centre_x = env->tool->left;
	//	centre_y = env->tool->up;
	centre_x = (env->win_w / 2 - (env->nb_x)
	* env->tool->step / 2) - 200 + env->tool->left;
	centre_y = (env->win_h / 2 - (env->nb_y * env->tool->step) / 2)
	- 200 + env->tool->up;
	i.x = centre_x + x * (env->tool->step)
	+ (0.5 * cos(30) * y) * (env->tool->step);
	i.y = centre_y + y * 0.5 * (env->tool->step) - (get_alt_pc(env, y, x));
	f.x = centre_x + (x + 1) * (env->tool->step) +
		(0.5 * cos(30) * y) * (env->tool->step);
	f.y = centre_y + y * 0.5 * (env->tool->step)
	- (get_alt_pc(env, y, (x + 1)));
	bresemham(env, &i, &f);
}

static void		segment_y_pc(t_struct *env, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int			centre_x;
	int			centre_y;

	centre_x = (env->win_w / 2 - (env->nb_x)
	* env->tool->step / 2) - 200 + env->tool->left;
	centre_y = (env->win_h / 2 - (env->nb_y * env->tool->step) / 2)
	- 200 + env->tool->up;
	i.x = centre_x + x * (env->tool->step)
	+ (0.5 * cos(30) * y) * (env->tool->step);
	i.y = centre_y + y * 0.5 * (env->tool->step) - (get_alt_pc(env, y, x));
	f.x = centre_x + x * (env->tool->step) +
		(0.5 * cos(30) * (y + 1)) * (env->tool->step);
	f.y = centre_y + (y + 1) * 0.5 * (env->tool->step) -
		(get_alt_pc(env, (y + 1), x));
	bresemham(env, &i, &f);
}

int				perspective(t_struct *env)
{
	int x;
	int y;

	y = 0;
	while (y < env->nb_y)
	{
		x = 0;
		while (x < env->nb_x)
		{
			if (x != env->nb_x - 1)
				segment_x_pc(env, y, x);
			if (y != env->nb_y - 1)
				segment_y_pc(env, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
