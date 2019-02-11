/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 21:11:45 by aquan             #+#    #+#             */
/*   Updated: 2019/02/08 20:09:36 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		get_alt(t_struct *env, int y, int x)
{
	int alt;

	if (y >= env->nb_y || x >= env->nb_x)
		return (0);
	alt = env->final[y][x];
	return (alt);
}

static void		segment_x(t_struct *env, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int			centre_x;
	int			centre_y;

	centre_x = (env->win_w / 2 - (env->nb_x) * env->tool->step / 2)
	+ 100 + env->tool->left;
	centre_y = (env->win_h / 2 - (env->nb_y * env->tool->step) / 2)
	- 200 + env->tool->up;
	i.x = centre_x + x * (env->tool->step) - y * (env->tool->step);
	printf("VAL STEP IN SEG = %d\n", env->tool->step);
	i.y = centre_y + x * (env->tool->step) / 2 + y * (env->tool->step)
		/ 2 - (get_alt(env, y, x) + env->tool->step);
	f.x = centre_x + (x + 1) * (env->tool->step) - y * (env->tool->step);
	f.y = centre_y + (x + 1) * (env->tool->step) / 2 + y * (env->tool->step)
		/ 2 - (get_alt(env, y, x + 1) + env->tool->step);
	bresemham(env, &i, &f);
}

static void		segment_y(t_struct *env, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int			centre_x;
	int			centre_y;

	//	centre_x = (env->win_w / 2 - (env->nb_x * (WIDTH + env->tool->step) / 2)) + env->tool->left;
	//	centre_y = (env->win_h / 2 - (env->nb_y * (HEIGHT + env->tool->step) / 2)) + env->tool->up;
	centre_x = (env->win_w / 2 - (env->nb_x) * env->tool->step / 2)
	+ 100 + env->tool->left;
	centre_y = (env->win_h / 2 - (env->nb_y * env->tool->step) / 2)
	- 200 + env->tool->up;
	i.x = centre_x + x * (env->tool->step) - y * (env->tool->step);
	i.y = centre_y + x * (env->tool->step) / 2 + y * (env->tool->step)
		/ 2 - (get_alt(env, y, x) + env->tool->step);
	f.x = centre_x + x * (env->tool->step) - (y + 1) * (env->tool->step);
	f.y = centre_y + x * (env->tool->step) / 2 + (y + 1) * (env->tool->step)
		/ 2 - (get_alt(env, y + 1, x) + env->tool->step);
	bresemham(env, &i, &f);
}

int				isometry(t_struct *env)
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
				segment_x(env, y, x);
			if (y != env->nb_y - 1)
				segment_y(env, y, x);
			x++;
		}
		y++;
	}
	return (0);
}
