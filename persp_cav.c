/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:27:20 by aquan             #+#    #+#             */
/*   Updated: 2019/01/04 18:17:02 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_z_pc(t_struct *start, int y, int x)
{
	int z;	
	z = (start->final[y][x]) + (1 / 2) * sin(45) * y;
	return (z);
}


void	position_pc(int map_x, int map_y, int z, int *screen_x, int *screen_y)
{
	
	*screen_x =  map_x + (1 / 2) * cos(45) * map_y;
   	*screen_y =  map_y * (1 / 2) * z;
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
				ligne(start->mlx_ptr, start->win_ptr, y, x, y, x * get_z_pc(start, y, x));	
			if (y != start->nb_y - 1)	
				ligne(start->mlx_ptr, start->win_ptr, y, x, y * get_z_pc(start, y, x), x);
			x++;
		}
		y++;
	}
	mlx_hook(start->win_ptr, 17,(1L << 17), close_w, start);
	mlx_key_hook(start->win_ptr, key_event, start);
	mlx_loop(start->mlx_ptr);
}
