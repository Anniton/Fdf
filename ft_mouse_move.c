/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 11:46:01 by aquan             #+#    #+#             */
/*   Updated: 2018/12/30 10:02:23 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		mouse_press(int	button, int x, int y, t_param *e)
{
	(void)x;
	(void)y;
	if (button == BUT_LEFT)
		e->pix_color = color;
	else if (button == BUT_RIGHT)
		e->pix_color = 0;
	mlx_hook(e->win, 6, (1L<<6), mouse_movement, e);
	return (0);
}


int		mouse_movement(int x, int y, t_param *e)
{
	int	i;
	int	j;

	i = -10;
	while (i < 10)
	{
		j = -10;
		while (j < 10)
		{
			//mlx_pixel_put(e->mlx, e->win, x + i, y + j, e->pix_color + (i + j) * 1000);
			mlx_pixel_put(e->mlx, e->win, x + i * 100, y + j * 100, e->pix_color + (i + j) * 1000000);
			j++;
		}
		i++;
	}
	return (0);
}

int		mouse_release(int button, int x, int y, t_param *e)
{
	(void)y;
	(void)x;
	(void)e;
	(void)button;
	mlx_hook(e->win, 6, (1L<<6), NULL, e);
	return (0);
}
