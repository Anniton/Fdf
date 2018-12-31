/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:08:38 by cmoulini          #+#    #+#             */
/*   Updated: 2018/12/31 16:04:12 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "fdf.h"

int	main(int argc, char **argv)
{
	int fd;
	t_struct *start;

	(void)argc;
	fd = 0;
	start = malloc(sizeof(t_struct));
	if (samplevalidity(argv[1], start))
	{
		printf("VAL Y = %d\n", start->nb_y);
//		printf("VAL X =  %d\n", start->nb_x);
		fd = open(argv[1], O_RDONLY);
	//	print_int_tab(get_int_tab(fd, start), start);
	}
	close(fd);
	return(0);
}
