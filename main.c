/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:16:41 by aquan             #+#    #+#             */
/*   Updated: 2019/02/09 20:14:59 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		tile_size(t_struct *env)
{
	if (env->nb_x > env->nb_y)
		env->tool->step = (env->win_w - 500) / (env->nb_x);
	//		env->coef_y = env->win_w - 250 / env->nb_x;
	else
		env->tool->step = (env->win_h - 500) / (env->nb_y);
	//		env->coef_y = env->win_w - 250 / env->nb_x;
	if (env->tool->step <= 1)
		env->tool->step = 1;
	return (0);
}

int		size_window(t_struct *env)
{
	env->win_h = env->nb_x * 40;
	env->win_w = env->nb_y * 45;
	if (env->win_h > 1000)
		env->win_h = 1000;
	if (env->win_h < 800)
		env->win_h = 800;
	if (env->win_w > 1500)
		env->win_w = 1500;
	if (env->win_w < 800)
		env->win_w = 800;
	return (0);
}

int		create_win_and_image(t_struct *env)
{
	env->mlx_ptr = mlx_init();
	size_window(env);
	env->win_ptr = mlx_new_window(env->mlx_ptr,
		env->win_w + 180, env->win_h, "FDF");
	env->img_ptr = mlx_new_image(env->mlx_ptr, env->win_w, env->win_h);
	env->img_str = (int*)mlx_get_data_addr(env->img_ptr,
		&(env->bpp), &(env->l), &(env->e));
	env->affichage = 1;
	env->px_color = 0xffffff;
	commands(env);
	tile_size(env);
	isometry(env);
	return (0);
}

t_struct	*malloc_env(void)
{
	t_struct	*env;

	if (!(env = (t_struct*)malloc(sizeof(t_struct))))
		return (NULL);
	if (!(env->tool = (t_tool*)malloc(sizeof(t_tool) * 1)))
		return (NULL);
	env->tool->left = 200;
	env->tool->up = 200;
	return (env);
}

int		main(int argc, char **argv)
{
	int			fd;
	t_struct	*env;

	if (argc < 2)
		return (0);
	fd = 0;
	env = malloc_env();
	(fd = open(argv[1], O_RDONLY));
	printf("%d\n", fd); 
	if (fd < 0)
		return (-1);
	if (check_sample_validity(fd, env))
	{
		create_win_and_image(env);
		mlx_hook(env->win_ptr, 17, (1L << 17), cross_event, env);
		mlx_key_hook(env->win_ptr, esc_key, env);
		mlx_hook(env->win_ptr, 2, 0, key_event, env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
		mlx_loop(env->mlx_ptr);
		destroy_all(env);
	}
	else
		ft_putendl("Wrong format");
	close(fd);
	return (0);
}
