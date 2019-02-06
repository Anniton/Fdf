/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   afficher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:12:20 by aquan             #+#    #+#             */
/*   Updated: 2019/02/06 16:28:09 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		get_alt(t_struct *start, int y, int x)
{
	int alt;

	if (y >= start->nb_y || x >= start->nb_x)
		return (0);
	alt = start->final[y][x];
	return (alt);
}

/*void	segment_x(t_struct *start, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int centre_x;
	int centre_y;

	centre_x = start->tool->left;
	centre_y = start->tool->up;
	i.x = centre_x + x * (WIDTH + start->tool->step) - y * (HEIGHT + start->tool->step);
	i.y = centre_y + x * (WIDTH + start->tool->step) / 2 + y * (HEIGHT + start->tool->step)
		/ 2 - (get_alt(start, y, x) + start->tool->step);
	f.x = centre_x + (x + 1) * (WIDTH + start->tool->step) - y * (HEIGHT + start->tool->step);
	f.y = centre_y + (x + 1) * (WIDTH + start->tool->step) / 2 + y * (HEIGHT + start->tool->step)
		/ 2 - (get_alt(start, y, x + 1) + start->tool->step);
	ligne_1(start, &i, &f);
}

void	segment_y(t_struct *start, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int centre_x;
	int centre_y;

	centre_x = start->tool->left;
	centre_y = start->tool->up;
	i.x = centre_x + x * (WIDTH + start->tool->step) - y * (HEIGHT + start->tool->step);
	i.y = centre_y + x * (WIDTH + start->tool->step) / 2 + y * (HEIGHT + start->tool->step)
		/ 2 - (get_alt(start, y, x) + start->tool->step);
	f.x = centre_x + x * (WIDTH + start->tool->step) - (y + 1) * (HEIGHT + start->tool->step);
	f.y = centre_y + x * (WIDTH + start->tool->step) / 2 + (y + 1) * (HEIGHT + start->tool->step)
		/ 2 - (get_alt(start, y + 1, x) + start->tool->step);
	ligne_1(start, &i, &f);
}*/

void	segment_x(t_struct *start, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int centre_x;
	int centre_y;

	centre_x = start->tool->left;
	centre_y = start->tool->up;
	i.x = centre_x + x - y * start->tool->step;
	i.y = centre_y + x / 2 + y * start->tool->step / 2 - (get_alt(start, y, x) + start->tool->step);
	f.x = centre_x + (x + 1) - y * start->tool->step;
	f.y = centre_y + (x + 1) / 2 + y * start->tool->step / 2 - (get_alt(start, y, x + 1) + start->tool->step);
	ligne_1(start, &i, &f);
}

void	segment_y(t_struct *start, int y, int x)
{
	t_coord_2	i;
	t_coord_2	f;
	int centre_x;
	int centre_y;

	centre_x = start->tool->left;
	centre_y = start->tool->up;
	i.x = centre_x + x - y * start->tool->step;
	i.y = centre_y + x / 2 + y * start->tool->step / 2 - (get_alt(start, y, x) + start->tool->step);
	f.x = centre_x + x - (y + 1) * start->tool->step;
	f.y = centre_y + x / 2 + (y + 1) * start->tool->step / 2 - (get_alt(start, y + 1, x) + start->tool->step);
	ligne_1(start, &i, &f);
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
	//	mlx_put_image_to_window(start->mlx_ptr, start->win_ptr, start->img_ptr, 0, 0);
	//		//	mlx_hook(start->win_ptr, 17, (1L << 17), close_w, start);
	//			//	mlx_key_hook(start->win_ptr, key_event, start);
	//				//	mlx_loop(start->mlx_ptr);
	return (0);
}
