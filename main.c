/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:46:17 by aquan             #+#    #+#             */
/*   Updated: 2018/12/30 13:10:54 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
int main(int argc, char **argv)
{	
//	t_param *e;
	if (argc != 2)
		write(1, "error\n", 6);
	else
	{	
		samplevalidity(argv[1]);
	}
//	if(!(e = malloc(sizeof(t_param))))
//		return (0);
//	e->mlx = mlx_init();
//	e->win = mlx_new_window(e->mlx, 1000, 1000, "new_wd");
//	mlx_key_hook(e->win, key_hook, e);
//	mlx_mouse_hook(e->win, mouse_hook, e);
//	mlx_hook(e->win, 17, (1L<<17), red_cross, e);
	
//	mlx_hook(e->win, 6, (1L<<6), mouse_press, e);
//	mlx_hook(e->win, 4, (1L<<4), mouse_press, e);	
//	mlx_hook(e->win, 5, (1L<<5), mouse_release, e);	
//	mlx_loop(e->mlx);
	return (0);
}










// COEUR
//	ft_line(525, 475, 500, 500, mlx, win);
//	ft_line(550, 475, 525, 475, mlx, win);
//	ft_line(550, 475, 575, 500, mlx, win);
//	ft_line(575, 500, 575, 525, mlx, win);
//	ft_line(575, 525, 550, 550, mlx, win);
//	ft_line(550, 550, 525, 575, mlx, win);
//	ft_line(525, 575, 500, 600, mlx, win);
//	ft_line(500, 600, 475, 575, mlx, win);
//	ft_line(475, 575, 450, 550, mlx, win);
//	ft_line(450, 550, 425, 525, mlx, win);
//	ft_line(425, 525, 425, 500, mlx, win);
//	ft_line(425, 500, 450, 475, mlx, win);
//	ft_line(450, 475, 475, 475, mlx, win);
//	ft_line(475, 475, 500, 500, mlx, win);

