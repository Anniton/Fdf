/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:44:50 by aquan             #+#    #+#             */
/*   Updated: 2019/01/18 18:32:39 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	pixel_put_img(int *img_ptr, int x, int y, int px_color)
{
	img_ptr[x + y * WIN_W] = px_color; 
}
/*
static int rgb(int r, int g, int b)
{
	return (256 * 256 *(r) + 256 * (g) + (b));
}

int		couleur(t_struct *start)
{
	int px_color;
	int x;
	int y;

		if (get_alt(start, y, x) == 0)
		px_color = 0x134BAC;
	if (get_alt(start, y, x) > 0)
		px_color = 0xF3B72C;
	if (get_alt(start, y, x) < 0)
		px_color = 0x134BAC;
	return (px_color);
}

*/
//return ((int)(rgb(127.5 * (cos(t) + 1), 127.5 * (sin(t) + 1),127.5 * (1 - cos(t)))));
	//return (0xff / (t + 1));

