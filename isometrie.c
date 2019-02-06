/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometrie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 13:24:33 by aquan             #+#    #+#             */
/*   Updated: 2019/01/09 12:33:37 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_alt(t_struct *start, int y, int x)
{
	int alt;

	alt = start->final[y][x];
	return (alt);
}

void	segment_x(t_struct *start, int y, int x)
{
	t_coord_2	*i;
	t_coord_2	*f;

	i = malloc(sizeof(t_coord_2));
	f = malloc(sizeof(t_coord_2));
	i->x = 500 + x * (WIDTH + STEP) - y * (HEIGHT + STEP);
	i->y = 500 + x * (WIDTH + STEP) / 2 + y * (HEIGHT + STEP)
		/ 2 - (get_alt(start, y, x) + STEP);
	f->x = 500 + (x + 1) * (WIDTH + STEP) - y * (HEIGHT + STEP);
	f->y = 500 + (x + 1) * (WIDTH + STEP) / 2 + y * (HEIGHT + STEP)
		/ 2 - (get_alt(start, y, x + 1) + STEP);
	ligne(start, i, f);
}

void	segment_y(t_struct *start, int y, int x)
{
	t_coord_2	*i;
	t_coord_2	*f;

	i = malloc(sizeof(t_coord_2));
	f = malloc(sizeof(t_coord_2));
	i->x = 500 + x * (WIDTH + STEP) - y * (HEIGHT + STEP);
	i->y = 500 + x * (WIDTH + STEP) / 2 + y * (HEIGHT + STEP)
		/ 2 - (get_alt(start, y, x) + STEP);
	f->x = 500 + x * (WIDTH + STEP) - (y + 1) * (HEIGHT + STEP);
	f->y = 500 + x * (WIDTH + STEP) / 2 + (y + 1) * (HEIGHT + STEP)
		/ 2 - (get_alt(start, y + 1, x) + STEP);
	ligne(start, i, f);
}

void	afficher(t_struct *start)
{
	int x;
	int y;

	start->mlx_ptr = mlx_init();
	start->win_ptr = mlx_new_window(start->mlx_ptr, 1000, 1000, "petit carre");
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
	mlx_hook(start->win_ptr, 17, (1L << 17), close_w, start);
	mlx_key_hook(start->win_ptr, key_event, start);
	mlx_key_hook(start->win_ptr, key_iso_press, start);
	mlx_expose_hook(start->win_ptr, key_iso_press, start);
	mlx_loop(start->mlx_ptr);
}
