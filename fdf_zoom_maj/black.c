/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:44:50 by aquan             #+#    #+#             */
/*   Updated: 2019/02/06 17:54:32 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
void	pixel_put_img(int *img_ptr, int x, int y, int px_color)
{
	img_ptr[x + y * (WIN_W - 75)] = px_color; 
}

void	info_put(t_struct *start)
{
	mlx_string_put(start->mlx_ptr, start->win_ptr, 10, 10, 0xFFFFFF, "Vue Iso : 1");
	mlx_string_put(start->mlx_ptr, start->win_ptr, 10, 25, 0xFFFFFF, "Vue Cavaliere : 2");
	mlx_string_put(start->mlx_ptr, start->win_ptr, 10, 40, 0xFFFFFF, "Zoom : +");
	mlx_string_put(start->mlx_ptr, start->win_ptr, 10, 55, 0xFFFFFF, "Dezoom : -");
}
/*
static int rgb(int r, int g, int b)
{
	return (255 * 255 *(r) + 256 * (g) + (b));
}
*/ /*
int	pixel_color(t_struct *start, int y, int x)
{
	int px_color;
//	alt = start->final[x][y];
//	printf("VAL X =  %d\n", x);
//	printf("VAL Y =  %d\n", y);
	if (get_alt(start, y, x) == 0)
		px_color = 0x000000;
	if (get_alt(start, y, x) > 0)
		px_color = 0x452648;
	if (get_alt(start, y, x) < 0)
		px_color = 0xAA4578;
	return (px_color);
}*/
