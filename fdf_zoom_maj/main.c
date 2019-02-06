/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:16:41 by aquan             #+#    #+#             */
/*   Updated: 2019/02/06 19:56:22 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		create_win_and_image(t_struct *env)
{
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, WIN_W, WIN_H, "fdf");
	env->img_ptr = mlx_new_image(env->mlx_ptr, WIN_W, WIN_H);
	env->img_str = (int*)mlx_get_data_addr(env->img_ptr, &(env->bpp), &(env->l), &(env->e));
	env->affichage = 1;
	return (SUCCESS);
}

t_struct*	init_env(t_struct *env)
{
	if (!(env = (t_struct*)malloc(sizeof(t_struct) * 1)))
		return (NULL);
	if (!(env->tool = (t_tool*)malloc(sizeof(t_tool) * 1)))
		return (NULL);
	create_win_and_image(env);
	env->tool->zoom = 32;
	return (env);	

}



int	main(int ac, char **av)
{
	int fd;
	t_struct *env;

	env = NULL;	
	if (ac < 2)
		return(FAILURE);
	fd = open(av[1], O_RDONLY);
	if (!(env = init_env(env)))
		return (FAILURE);
	check_sample_validity(fd, env);
	print_int_tab(env->final, env);
	printf("h = %i, w = %i\n", env->nb_y, env->nb_x);
	print(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	mlx_key_hook(env->win_ptr, event, env);
	mlx_loop(env->mlx_ptr);
	return(SUCCESS);
}
