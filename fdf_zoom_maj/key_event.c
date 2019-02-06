/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:15:42 by aquan             #+#    #+#             */
/*   Updated: 2019/02/06 19:18:32 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_plus(int key, t_struct *param)
{
	if (param->tool->step < 20 || param->tool->step > 1)
	{
		(param->tool->step) += (key == 69) ? 1 : -1;
		if (param->print == 1)
		{
			ft_bzero(param->img_str, sizeof(int) * WIN_H * WIN_W);
			print(param);
		}
		else
		{
			ft_bzero(param->img_str, sizeof(int) * WIN_H * WIN_W);
		//	print_pc(param);
		}
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0);
}
/*void	move_left(int key, t_struct *param)
{
	if (param->tool->left < WIN_W)
	{
		(param->tool->left) -= (key == 123) ? 10 : -10;
		ft_putnbr(param->tool->left);
		ft_putchar('\n');
		if (param->affichage == 1)
		{
			ft_bzero(param->img_str, sizeof(int) * WIN_H * WIN_W);
			print(param);
		}
		else
		{
			ft_bzero(param->img_str, sizeof(int) * WIN_H * WIN_W);
			print_pc(param);
		}
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0);
}

void	move_up(int key, t_struct *param)
{
	if (param->tool->up < WIN_H)
	{
		(param->tool->up) -= (key == 126) ? 20 : -20;	
		if (param->affichage == 1)
		{
			ft_bzero(param->img_str, sizeof(int) * WIN_H * WIN_W);
			print(param);
		}
		else
		{
			ft_bzero(param->img_str, sizeof(int) * WIN_H * WIN_W);
			print_pc(param);
		}
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0);
}
*/
int key_event(int key, t_struct *param)
{
	if (key == 53)
	{
		free(param);
		exit (EXIT_SUCCESS);
	}
	if (key == 83)
	{
		ft_bzero(param->img_str, sizeof(int) * WIN_H * WIN_W);
		param->affichage = 1;
		print(param);
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0);
	}
	if (key == 84)
	{
		ft_bzero(param->img_str, sizeof(int) * WIN_H * WIN_W);
		param->affichage = 2;
	//	print_pc(param);
		mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0);
	}
	if (key == 69 || key == 78)
		zoom_plus(key, param);
//	if (key == 123 || key == 124)
//		move_left(key, param);
//	if (key == 126 || key == 125)
//		move_up(key, param);
	return (0);
}

/*
   int		key_press(int keycode, t_struct *param)
   {
   mlx_hook(param->win_ptr, 2, (1L << 2), 
   }
   */
