/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:27:20 by aquan             #+#    #+#             */
/*   Updated: 2019/01/04 15:17:07 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_alt(t_struct *start, int y, int x)
{
	
	int alt = start->final[y][x];
	return (alt);
}

void	positionne(int map_x, int map_y, int alt, int *screen_x, int *screen_y)
{
	int centre_x;
	int centre_y;
	
	centre_x = 1000 / 2 - (19 - 1) * (WIDTH + STEP);
	centre_y = 1000 / 2 - (11 - 1) * (HEIGHT + STEP);
	*screen_x = centre_x + map_x * (WIDTH + STEP) + map_y * (HEIGHT + STEP);
   	*screen_y = centre_y + map_x * (WIDTH + STEP) / 2 - map_y * (HEIGHT + STEP) / 2 - alt * 2;

}

void segment(t_struct *start, int ymin, int xmin, int ymax, int xmax)
{
	int xi;
	int yi;
	int xf;
	int yf;	
	int alt;

	alt = 0;
	positionne(ymin, xmin, get_alt(start, ymin, xmin), &xi, &yi);
	positionne(ymax,xmax, get_alt(start, ymax, xmax), &xf, &yf);
	ligne(start->mlx_ptr, start->win_ptr, xi, yi, xf, yf);
}
void	afficher(t_struct *start)
{
	int x;
	int y;

	start->mlx_ptr = mlx_init();
	start->win_ptr = mlx_new_window(start->mlx_ptr, start->nb_y * start->nb_y * WIDTH, start->nb_y * start->nb_y * WIDTH, "petit carre");
	y = 0;
	while (y < start->nb_y)
	{
		x = 0;
		while(x < start->nb_x)
		{
			if (x != start->nb_x - 1)	
				segment(start, y, x, y, x + 1);	
			if (y != start->nb_y - 1)	
				segment(start, y, x, y + 1, x);
			x++;
		}
		y++;
	}
	mlx_hook(start->win_ptr, 17,(1L << 17), close_w, start);
	mlx_key_hook(start->win_ptr, key_event, start);
	mlx_loop(start->mlx_ptr);
}
