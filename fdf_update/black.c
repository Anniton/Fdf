/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:44:50 by aquan             #+#    #+#             */
/*   Updated: 2019/02/06 22:08:57 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
void	pixel_put_img(int *img_ptr, int x, int y, int px_color)
{
	if (x > 0 && y > 0 && x < WIN_W && y < WIN_H)
		img_ptr[x + y * (WIN_W)] = px_color; 
}

void	info_put(t_struct *start)
{
	mlx_string_put(start->mlx_ptr, start->win_ptr, 10, 10, 0xFFFFFF, "Vue Iso : 1");
	mlx_string_put(start->mlx_ptr, start->win_ptr, 10, 25, 0xFFFFFF, "Vue Cavaliere : 2");
	mlx_string_put(start->mlx_ptr, start->win_ptr, 10, 40, 0xFFFFFF, "Zoom : +");
	mlx_string_put(start->mlx_ptr, start->win_ptr, 10, 55, 0xFFFFFF, "Dezoom : -");
}
int	pixel_color(t_struct *start, int y, int x)
{
	int px_color;
	if (get_alt(start, y, x) == 0)
		px_color = 0x000000;
	if (get_alt(start, y, x) > 0)
		px_color = 0x452648;
	if (get_alt(start, y, x) < 0)
		px_color = 0xAA4578;
	return (px_color);
}
