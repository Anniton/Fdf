/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:08:38 by cmoulini          #+#    #+#             */
/*   Updated: 2018/12/30 15:08:40 by cmoulini         ###   ########.fr       */
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
	if (samplevalidity(argv[1], start))
	{
		fd = open(argv[1], O_RDONLY);
		print_int_tab(get_int_tab(fd, start), start);
	}
	close(fd);
	return(0);
}