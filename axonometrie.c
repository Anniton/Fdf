/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   axonometrie.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 13:49:32 by aquan             #+#    #+#             */
/*   Updated: 2019/01/09 12:12:47 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_z_pc(t_struct *start, int *y, int x)
{
	int z;
	z = (start->final[*y][x]) - 0.5*cos(45) * (*y);
	return (z);
}

void segment_pc_x(t_struct *start, int y, int x)
{
	t_coord_2	*i;
	t_coord_2	*f;

	i = malloc(sizeof(t_coord_2));
	f = malloc(sizeof(t_coord_2));
	i->x = 490 + y * (WIDTH + 12) + (0.5*cos(45) * x) * (HEIGHT + 12);
	i->y = 490 + x * 0.5 * (WIDTH + 12) - get_z_pc(start, &y, x);
	f->x = 490 + y * (WIDTH + 12) + (0.5*cos(45) * x + 1) * (HEIGHT + 12);
	f->y = 490 + (x + 1) * 0.5 * (WIDTH + 12) -  get_z_pc(start, &y, x + 1);
	ligne(start, i, f);
}

void segment_pc_y(t_struct *start, int y, int x)
{
	t_coord_2	*i;
	t_coord_2	*f;

	i = malloc(sizeof(t_coord_2));
	f = malloc(sizeof(t_coord_2));
	i->x = 490 + y * (WIDTH + 12) + (0.5*cos(45) * x) * (HEIGHT + 12);
	i->y = 490 + x * 0.5 * (WIDTH + 12) -  get_z_pc(start, &y, x);
	f->x = 490 + (y + 1) * (WIDTH + 12) + (0.5*cos(45) * x) * (HEIGHT + 12);
	f->y = 490 + x * 0.5 * (WIDTH + 12) -  get_z_pc(start, &y, x);
	ligne(start, i, f);
}


void	afficher_pc(t_struct *start)
{
	int x;
	int y;

	start->mlx_ptr = mlx_init();
	start->win_ptr = mlx_new_window(start->mlx_ptr, 1000, 1000, "petit carre");
	y = 0;
	while (y < start->nb_y)
	{
		x = 0;
		while(x < start->nb_x)
		{
			if (x != start->nb_x - 1)
				segment_pc_x(start, y, x);
			if (y != start->nb_y - 1)
				segment_pc_y(start, y, x);
			x++;
		}
		y++;
	}
	mlx_hook(start->win_ptr, 17,(1L << 17), close_w, start);
	mlx_key_hook(start->win_ptr, key_event, start);
	mlx_key_hook(start->win_ptr, key_event, start);
	mlx_loop(start->mlx_ptr);
}
