/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 13:31:47 by aquan             #+#    #+#             */
/*   Updated: 2018/12/29 15:12:19 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_hook(int button, int x, int y, t_param *e)
{
	static int i = 0;

	if (button == BUT_RIGHT)
	{
		if (i % 2 == 0)
		{
			e->x1 = x;
			e->y1 = y;
			ft_putnbr(button);
			ft_putchar(' ');
			ft_putnbr(e->y1);
			ft_putchar('\n');
			i++;
		}
		else 
		{
			e->x2 = x;
			e->y2 = y;
			ft_putnbr(e->x2);
			ft_putchar(' ');
			ft_putnbr(e->y2);
			ft_putchar('\n');
			ft_line(e->x1, e->y1, e->x2, e->y2, e->mlx, e->win);
			i--;
		}
	}
	return (0);
}


