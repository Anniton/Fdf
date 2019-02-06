/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:12:20 by aquan             #+#    #+#             */
/*   Updated: 2019/01/19 13:42:24 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
int		get_alt(t_struct *start, int y, int x)
{
	int alt;

	if (y >= start->nb_y || x >= start->nb_x)
		return (0);
	alt = start->final[y][x];
	return (alt);
}


void	segment_x(t_struct *start, int y, int x)
{
	t_coord_2	*i;
	t_coord_2	*f;
	int centre_x;
	int centre_y;

	i = malloc(sizeof(t_coord_2));
	f = malloc(sizeof(t_coord_2));
	centre_x = WIN_W / 2 - (start->nb_x * (WIDTH + STEP) / 2);
	centre_y = WIN_H / 2 - (start->nb_y * (HEIGHT + STEP) / 2);
	i->x = centre_x + x * (WIDTH + STEP) - y * (HEIGHT + STEP);
	i->y = centre_y + x * (WIDTH + STEP) / 2 + y * (HEIGHT + STEP)
		/ 2 - (get_alt(start, y, x) + STEP);
	f->x = centre_x + (x + 1) * (WIDTH + STEP) - y * (HEIGHT + STEP);
	f->y = centre_y + (x + 1) * (WIDTH + STEP) / 2 + y * (HEIGHT + STEP)
		/ 2 - (get_alt(start, y, x + 1) + STEP);
	ligne_1(start, i, f);

	printf("VALEUR DE ALT = %d\n", get_alt(start, y, x));
}

void	segment_y(t_struct *start, int y, int x)
{
	t_coord_2	*i;
	t_coord_2	*f;
	int centre_x;
	int centre_y;

	i = malloc(sizeof(t_coord_2));
	f = malloc(sizeof(t_coord_2));
	centre_x = WIN_W / 2 - (start->nb_x * (WIDTH + STEP) / 2);
	centre_y = WIN_H / 2 - (start->nb_y * (HEIGHT + STEP) / 2);
	i->x = centre_x + x * (WIDTH + STEP) - y * (HEIGHT + STEP);
	i->y = centre_y + x * (WIDTH + STEP) / 2 + y * (HEIGHT + STEP)
		/ 2 - (get_alt(start, y, x) + STEP);
	f->x = centre_x + x * (WIDTH + STEP) - (y + 1) * (HEIGHT + STEP);
	f->y = centre_y + x * (WIDTH + STEP) / 2 + (y + 1) * (HEIGHT + STEP)
		/ 2 - (get_alt(start, y + 1, x) + STEP);
	ligne_1(start, i, f);
}

int		couleur(t_struct *start, int x, int y)
{
	int px_color;
	px_color = 0;
	if (get_alt(start, y, x) == 0)
		px_color = 0x00FFFF;
	if (get_alt(start, y, x) > 0)
		px_color = 0xF3B72C;
	if (get_alt(start, y, x) < 0)
		px_color = 0x134BAC;
	return (px_color);
}


int		afficher(t_struct *start)
{
	int x;
	int y;
	y = 0;
	while (y < start->nb_y)
	{
		x = 0;
		while (x < start->nb_x)
		{
			if (x != start->nb_x - 1)
				segment_x(start, y, x);
			if (y != start->nb_y - 1)
				segment_y(start, y, x);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(start->mlx_ptr, start->win_ptr, start->img_ptr, 0, 0);
	//	mlx_hook(start->win_ptr, 17, (1L << 17), close_w, start);
	//	mlx_key_hook(start->win_ptr, key_event, start);
	//	mlx_loop(start->mlx_ptr);
	return (0);
}
