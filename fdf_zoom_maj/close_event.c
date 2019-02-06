/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 17:14:41 by aquan             #+#    #+#             */
/*   Updated: 2019/02/06 18:46:23 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		destroy_all(t_struct *env)
{
	free(env->final);
	//free(env->tool);
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	free(env);
	return (SUCCESS);
}

int		event(int key, t_struct *param)
{
	if (key == K_ESC)
	{	
		destroy_all(param);
		exit(SUCCESS);
	}
	return (SUCCESS);
}
