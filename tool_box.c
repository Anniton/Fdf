/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 13:44:50 by aquan             #+#    #+#             */
/*   Updated: 2019/02/09 19:48:31 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_color(t_struct *env, int old_c, int new_c)
{
	int		x;
	int		y;

	y = 0;
	while (y < env->win_h)
	{
		x = 0;
		while (x < env->win_w)
		{
			if (env->img_str[x + y * (env->win_w)] == old_c)
				env->img_str[x + y * (env->win_w)] = new_c;
			x++;
		}
		y++;
	}
	return ;
}

void	pixel_put_img(int *img_str, int x, int y, t_struct *env)
{
	if (x > 0 && y > 0 && x < env->win_w && y < env->win_h)
		img_str[x + y * (env->win_w)] = env->px_color;
}

void	commands(t_struct *env)
{
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->win_w, 10, 0xFFFFFF, "Vue Iso :       1");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->win_w, 25, 0xFFFFFF, "Vue Cavaliere : 2");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->win_w, 40, 0xFFFFFF, "Zoom :          +");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->win_w, 55, 0xFFFFFF, "Dezoom :        -");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->win_w, 70, 0xFFFFFF, "left :         <-");
	mlx_string_put(env->mlx_ptr, env->win_ptr,
			env->win_w, 85, 0xFFFFFF, "right :        ->");
}


int		destroy_all(t_struct *env)
{
	int		i;

	i = 0;
	while (i < env->nb_y)
		free(env->final[i++]);
	free(env->final);
	free(env->tool);
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	free(env);
	return (0);
}
