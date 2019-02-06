/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ligne.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:16:09 by aquan             #+#    #+#             */
/*   Updated: 2019/02/06 16:51:19 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ligne_2(t_struct *start, t_coord_2 *i, t_coord_2 *f)
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
		if (x > 0 && y > 0 && x < WIN_W && y < WIN_H)
			pixel_put_img(start->img_str, x, y, 0xFF0000);
		m++;
	}
}

void	ligne_3(t_struct *start, t_coord_2 *i, t_coord_2 *f)
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
		if (x > 0 && y > 0 && x < WIN_W && y < WIN_H)	
			pixel_put_img(start->img_str, x, y, 0xFF0000);
		m++;
	}
}

void	ligne_1(t_struct *start, t_coord_2 *i, t_coord_2 *f)
{
	int x;
	int y;

	x = i->x;
	y = i->y;
	if (x > 0 && y > 0 && x < WIN_W && y < WIN_W)	
		pixel_put_img(start->img_str, x, y, 0xFF0000);
	if (abs(f->x - i->x) > abs(f->y - i->y))
		ligne_3(start, i, f);
	else
		ligne_2(start, i, f);
}
