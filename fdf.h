/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:08:28 by cmoulini          #+#    #+#             */
/*   Updated: 2018/12/31 15:31:08 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <math.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define color 0xFF1493
# define SIZE 2048

typedef struct	s_struct
{
	int	nb_x;
	int nb_y;
}				t_struct;

int		**get_int_tab(int fd, t_struct *start);
void	print_int_tab(int **tab, t_struct *start);
int		ft_count_x(char *s, int *i);
int		ft_count_y(int fd);
int		samplevalidity(char *argv, t_struct *start);
int		ft_checkline(char *s);

#endif
