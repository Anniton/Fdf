/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   persp_cav.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 14:42:43 by aquan             #+#    #+#             */
/*   Updated: 2019/01/09 11:20:34 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_z_pc(t_struct *start, int *y, int x)
{
	int z;	
	z = (start->final[*y][x]) - 0.5*cos(45) * (*y);
	return (z);
}


void	position_pc(int map_x, int map_y, int z, int *screen_x, int *screen_y)
{
	*screen_x =  490 + map_y * (WIDTH + 12) + (0.5*cos(45)*map_x) * (HEIGHT + 12);
   	*screen_y = 490 + map_x * 0.5 * (WIDTH + 12) - (z);
//	*screen_x =  map_x + (1 / 2) * cos(45) * map_y;
//	*screen_y =  map_y * (1 / 2) * cos(45) * map_y + z;
}

void segment_pc(t_struct *start, int ymin, int xmin, int ymax, int xmax)
{
	int xi;
	int yi;
	int xf;
	int yf;
	int alt;

	(void)alt;
	position_pc(ymin, xmin, get_z_pc(start, &ymin, xmin), &xi, &yi);
	position_pc(ymax,xmax, get_z_pc(start, &ymax, xmax), &xf, &yf);
	ligne(start->mlx_ptr, start->win_ptr, xi, yi, xf, yf);
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
				segment_pc(start, y, x, y, x + 1);	
			if (y != start->nb_y - 1)	
				segment_pc(start, y, x, y + 1, x);
			x++;
		}
		y++;
	}
	mlx_hook(start->win_ptr, 17,(1L << 17), close_w, start);
	mlx_key_hook(start->win_ptr, key_event, start);
	mlx_loop(start->mlx_ptr);
}
