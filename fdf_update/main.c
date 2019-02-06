/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:16:41 by aquan             #+#    #+#             */
/*   Updated: 2019/01/15 12:28:25 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fdf.h"

int	main(int argc, char **argv)
{
	int fd;
	t_struct *start;

	(void)argc;
	fd = 0;
	start = malloc(sizeof(t_struct));
	fd = open(argv[1], O_RDONLY);
	start->final = (int **)malloc(sizeof(int*));
	ft_bzero(start->final, 1);
	if (check_sample_validity(fd, start))
	{
		print_int_tab(start->final, start);
		start->mlx_ptr = mlx_init();
		start->win_ptr = mlx_new_window(start->mlx_ptr, WIN_W, WIN_H, "petit carre");
		start->img_ptr = mlx_new_image(start->mlx_ptr, WIN_W, WIN_H);
		start->img_str = (int*)mlx_get_data_addr(start->img_ptr, &(start->bpp), &(start->l), &(start->e));
		mlx_hook(start->win_ptr, 17, (1L << 17), close_w, start);
		mlx_key_hook(start->win_ptr, key_event, start);
		afficher(start);
		mlx_put_image_to_window(start->mlx_ptr, start->win_ptr, start->img_ptr, 0, 0);
		mlx_loop(start->mlx_ptr);
		mlx_destroy_image(start->mlx_ptr, start->img_ptr);
	}
	else
		ft_putendl("Wrong format");
	close(fd);
	return(0);
}
