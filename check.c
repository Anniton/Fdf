/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:13:49 by aquan             #+#    #+#             */
/*   Updated: 2018/12/30 15:02:27 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#define BUFF_SIZE 2048
#include <stdio.h>
/*
   int		check_map(char *argv)
   {
   int		oneline;
   int		x_len;
   int		fd;

   fd = open(argv, O_RDONLY);
   oneline = 1;
   while (get_next_line(fd, &line) == 1)
   {
   if (oneline == 1);
   checkline(line);
   else
   close(fd);
   free(line);		
   }
   return(1);
   }*/
int		checkline(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{	
		if ((ft_isdigit(s[i])))
		{
			if (((s[i - 1] == '-' || s[i - 1] == ' ' ) && ft_isdigit(s[i]) && ft_isdigit(s[i + 1])))
				++i;
			if (s[i] == ' ')
				++i;
		}
		printf("VAL I = %d\n", i);
		++i;
	}
	return (1);
}
/*		
		while (s[i] && ft_isdigit(s[i]))
		{
		if (s[i] == ',')
		{
		if (s[i] == '0')
		if (s[i + 1] == 'x' && ft_isdigit(s[i + 2])

		}
		}
		}
		i++;
		}
		if (buf[i] == '\0')
		return (1);
		return (0);
		}
		*/
int		samplevalidity(char *argv)
{
	int		fd;
	char	buf[BUFF_SIZE];

	if ((fd = open(argv, O_RDONLY)) == -1)
		return (0);
	read(fd, buf, BUFF_SIZE);
	checkline(buf);
	close(fd);
	return (0);
}



/*

   int		**check_line(char **str, int **tab)
   {
   int n;
   int m;
   int x;
   int y;

   tab = (int**)malloc(sizeof(**tab) * )
   n = 0;
   m = 0;
   y = 0;
   x = 0;
   str = ft_strsplit(line, ' ');
   while (ret)
   {
   tab[y][x++] = ft_atoi(str[n][m++]);
   }
   while (ret)
   {
   tab[y++] = ft_atoi(str[n++]);
   }
   free(str);
   return (tab);
   }

   int		reader(char *argv)
   {
   int fd;
   int ret;
   char **line;

   if ((fd = open(argv, O_RDONLY)) == -1)
   {
   write(1, "Error\n", 6);
   return (0);
   }
   ret = get_next_line(fd, &line);
   if (ret == -1 || ret == 0)
   {
   write(1, "Error\n", 6);
   return (0);
   }
   close(fd);
   return (1);
   }
   */
