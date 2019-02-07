/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:16:41 by aquan             #+#    #+#             */
/*   Updated: 2019/02/07 18:27:14 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		tile_size(t_struct *start)
{
	if (start->nb_x > start->nb_y)
	{
		start->tool->step = (start->win_w - 700) / (start->nb_x);
		printf("VAL STEP =  %d\n", start->tool->step); 
//		start->coef_y = start->win_w - 250 / start->nb_x;
	}
	else
	{
		start->tool->step = (start->win_h - 700) / (start->nb_y);
//		start->coef_y = start->win_w - 250 / start->nb_x;
	}
	if (start->tool->step <= 1)
	{
		start->tool->step = 1;
	}
	return (0);
}

int		size_window(t_struct *start)
{
	start->win_h = start->nb_x * 40;
	start->win_w = start->nb_y * 45;
	if (start->win_h > 1000)
		start->win_h = 1000;
	if (start->win_h < 800)
		start->win_h = 800;
	if (start->win_w > 1500)
		start->win_w = 1500;
	if (start->win_w < 800)
		start->win_w = 800;
	return (0);
}

int		create_win_and_image(t_struct *env)
{
	env->mlx_ptr = mlx_init();
	size_window(env);
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->win_w, env->win_h, "petit carre");
	env->img_ptr = mlx_new_image(env->mlx_ptr, env->win_w, env->win_h);
	env->img_str = (int*)mlx_get_data_addr(env->img_ptr, &(env->bpp), &(env->l), &(env->e));
	env->affichage = 1;
	return (0);
}

int		destroy_all(t_struct *env)
{
	free(env->final);
	free(env->tool);
	free(env);
	mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	mlx_clear_window(env->mlx_ptr, env->win_ptr);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	int fd;
	t_struct *env;	
	(void)argc;
	fd = 0;


	if (!(env = (t_struct*)malloc(sizeof(t_struct))))
		return (-1);
	if (!(env->tool = (t_tool*)malloc(sizeof(t_tool) * 1)))
		return (-1);
	env->tool->left = 200;
	env->tool->up = 200;
	fd = open(argv[1], O_RDONLY);
	if(!(env->final = (int**)malloc(sizeof(int*))))
		return (-1);
	ft_bzero(env->final, 1);
	if (check_sample_validity(fd, env))
	{
		print_int_tab(env->final, env);
		create_win_and_image(env);
		env->tool->step = env->nb_x - env->nb_y / 2;
		tile_size(env);
		afficher(env);
		info_put(env);
		mlx_hook(env->win_ptr, 17, (1L << 17), close_w, env);
//		mlx_key_hook(env->win_ptr, key_event, env);
		mlx_hook(env->win_ptr, 2, 0, key_event, env);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
		mlx_loop(env->mlx_ptr);
		destroy_all(env);
	}
	else
		ft_putendl("Wrong format");
	close(fd);
	return(0);
}
