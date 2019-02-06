/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:08:38 by cmoulini          #+#    #+#             */
/*   Updated: 2019/01/11 15:17:31 by aquan            ###   ########.fr       */
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
	if (check_sample_validity_jg(fd, start))
	{
		// ft_putendl("OL");		
		print_int_tab(start->final, start);
		afficher(start);
		afficher_pc(start);
	}
	else
		ft_putendl("Wrong format");
	close(fd);
	return(0);
}
