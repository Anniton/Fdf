/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:16:09 by aquan             #+#    #+#             */
/*   Updated: 2019/02/08 15:24:49 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ligne_2(t_struct *env, t_coord_2 *i, t_coord_2 *f)
{
	int m;
	int cumul;
	int x;
	int y;

	x = i->x;
	y = i->y;
	cumul = abs(f->y - i->y) / 2;
	m = 1;
	while (m <= abs(f->y - i->y))
	{
		if (f->y - i->y != 0)
			y += (i->y < f->y) ? 1 : -1;
		cumul += abs(f->x - i->x);
		if (cumul >= abs(f->y - i->y))
		{
			cumul -= abs(f->y - i->y);
			x += (i->x < f->x) ? 1 : -1;
		}
		if (x > 0 && y > 0 && x < env->win_w && y < env->win_h)
			pixel_put_img(env->img_str, x, y, env);
		m++;
	}
}

static void		ligne_3(t_struct *env, t_coord_2 *i, t_coord_2 *f)
{
	int m;
	int cumul;
	int x;
	int y;

	x = i->x;
	y = i->y;
	cumul = abs(f->x - i->x) / 2;
	m = 1;
	while (m <= abs(f->x - i->x))
	{
		x += (i->x < f->x) ? 1 : -1;
		cumul += abs(f->y - i->y);
		if (cumul >= abs(f->y - i->y))
		{
			cumul -= abs(f->x - i->x);
			if (f->y - i->y != 0)
				y += (i->y < f->y) ? 1 : -1;
		}
		if (x > 0 && y > 0 && x < env->win_w && y < env->win_h)
			pixel_put_img(env->img_str, x, y, env);
		m++;
	}
}

void			bresemham(t_struct *env, t_coord_2 *i, t_coord_2 *f)
{
	int x;
	int y;

	x = i->x;
	y = i->y;
	if (x > 0 && y > 0 && x < env->win_w && y < env->win_w)
		pixel_put_img(env->img_str, x, y, env);
	if (abs(f->x - i->x) > abs(f->y - i->y))
		ligne_3(env, i, f);
	else
		ligne_2(env, i, f);
}
