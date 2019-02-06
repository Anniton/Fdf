/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpieri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 09:53:17 by cpieri            #+#    #+#             */
/*   Updated: 2019/02/06 18:12:47 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	bresenham(t_vector_2d *p1, t_vector_2d *p2, t_struct *mlx)
{
	t_bres		e;

	e.ex = labs(p2->x - p1->x);
	e.ey = labs(p2->y - p1->y);
	e.err = (e.ex > e.ey ? e.ex : -e.ey) / 2;
	while (p1->x != p2->x || p1->y != p2->y)
	{
		if (p1->y >= 0 && p1->y <= WIN_H && p1->x >= 0 && p1->x <= WIN_W)
		{
			mlx->img_str[(p1->y * mlx->l / 4) + (p1->x)] = 0xFFFFFF;
			e.e = e.err;
			if (e.e > -e.ex)
			{
				(p1->x > p2->x) ? (p1->x--) : (p1->x++);
				e.err -= e.ey;
			}
			if (e.e < e.ey)
			{
				(p1->y > p2->y) ? (p1->y--) : (p1->y++);
				e.err += e.ex;
			}
		}
		else
			break ;
	}
}
