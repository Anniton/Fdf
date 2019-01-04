/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 20:07:54 by cmoulini          #+#    #+#             */
/*   Updated: 2019/01/04 13:44:30 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int close_w(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

//int mouse_press(int button, int x, int y, t_struct *param)
//{
//	(void)x;
//	(void)y;	
//	if (button == 1)
//		mlx_hook(param->win_ptr, 6, (1L << 6), mouse_movement, param);
//	return (0);
//}

//int mouse_movement(int x, int y, t_struct *param)
//{
//	mlx_pixel_put(param->mlx_ptr, param->win_ptr, x, y, color);
//	return(0);
//}

//int		mouse_release(int button, int x, int y, t_struct *param)
//{
//	(void)y;
//	(void)x;
//	(void)button;
//	mlx_hook(param->win_ptr, 6, (1L<<6), NULL, param);
//	return (0);
//}
