/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:44:50 by aquan             #+#    #+#             */
/*   Updated: 2019/01/11 15:16:55 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put_img(void *img_ptr, int x, int y, int px_color)
{
	x = 0;
	y = 0;
	while (x < start->nb_x)
	{
		y = 0;
		while (y < start->nb_y)
		{
			//mlx_pixel_put(start->mlx_ptr, start->win_ptr, x, y, 0x00000);
			//pixel_put_img(start->img_ptr, x, y, 0x0000);
			start->imgstr[x + y * WIN_W] = 0xFF0000; 
			++y;
		}
		++x;
	}
	return (0);
}
