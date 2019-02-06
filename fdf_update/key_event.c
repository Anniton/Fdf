/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:15:42 by aquan             #+#    #+#             */
/*   Updated: 2019/01/19 13:41:58 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
		afficher(param);	
	}
	if (key == 84)
	{
		ft_bzero(param->img_str, sizeof(int) * WIN_H * WIN_W);
		afficher_pc(param);
	}
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0);
	return (0);
}
/*
int		key_press(int keycode, t_struct *start)
{
	mlx_hook(start->win_ptr, 2, (1L << 2), 
}
*/
