/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:15:42 by aquan             #+#    #+#             */
/*   Updated: 2019/02/08 23:41:01 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		zoom_plus(int key, t_struct *env)
{
	(env->tool->step) += (key == 69) ? 1 : -1;
	if (env->affichage == 1)
	{
		ft_bzero(env->img_str, sizeof(int) * env->win_h * env->win_w);
		isometry(env);
	}
	else
	{
		ft_bzero(env->img_str, sizeof(int) * env->win_h * env->win_w);
		perspective(env);
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

static void		move_left(int key, t_struct *env)
{
	(env->tool->left) -= (key == 123) ? 10 : -10;
	ft_putnbr(env->tool->left);
	ft_putchar('\n');
	if (env->affichage == 1)
	{
		ft_bzero(env->img_str, sizeof(int) * env->win_h * env->win_w);
		isometry(env);
	}
	else
	{
		ft_bzero(env->img_str, sizeof(int) * env->win_h * env->win_w);
		perspective(env);
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

static void		move_up(int key, t_struct *env)
{
	(env->tool->up) -= (key == 126) ? 40 : -40;
	if (env->affichage == 1)
	{
		ft_bzero(env->img_str, sizeof(int) * env->win_h * env->win_w);
		isometry(env);
	}
	else
	{
		ft_bzero(env->img_str, sizeof(int) * env->win_h * env->win_w);
		perspective(env);
	}
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

static int		change_color(int key, t_struct *env)
{
	int		old_color;

	old_color = env->px_color;
	if (key == 9)
		env->px_color = 0x452648;
	if (key == 15)
		env->px_color = 0xFF0000;
	if (key == 11)
		env->px_color = 0x00FFFF;
	if (key == 16)
		env->px_color = 0xF3B72C;
	check_color(env, old_color, env->px_color);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	return (env->px_color);
}
int				key_event(int key, t_struct *env)
{
	if (key == 83)
	{
		ft_bzero(env->img_str, sizeof(int) * env->win_h * env->win_w);
		env->affichage = 1;
		isometry(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	}
	if (key == 84)
	{
		ft_bzero(env->img_str, sizeof(int) * env->win_h * env->win_w);
		env->affichage = 2;
		perspective(env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	}
	if (key == 9 || key == 11 || key == 15 || key == 16)
		change_color(key, env);
	if (key == 69 || key == 78)
		zoom_plus(key, env);
	if (key == 123 || key == 124)
		move_left(key, env);
	if (key == 126 || key == 125)
		move_up(key, env);
	return (0);
}
