/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoulini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/30 15:08:28 by cmoulini          #+#    #+#             */
/*   Updated: 2019/01/04 15:07:59 by aquan            ###   ########.fr       */
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
# include <stdio.h>

# define color 0x9400D3
# define SIZE 2048
# define HEIGHT 10
# define WIDTH 10
# define STEP 5
typedef struct	s_struct
{
	void *mlx_ptr;
	void *win_ptr;	
	int	nb_x;
	int nb_y;
	int firstline;
	int **final;

}				t_struct;

int		**get_int_tab(int fd, t_struct *start);
void	print_int_tab(int **tab, t_struct *start);
int		ft_check_x(char *s);
int		ft_count_y(char *s, t_struct *start);
int		ft_checkline(char *s);
int		ft_checkfirstline(char *s, t_struct *start);
int		check_sample_validity_jg(int fd, t_struct *start);
void	afficher(t_struct *start);
void	ligne(void *mlx_ptr, void *win_ptr, int xi, int yi, int xf, int yf);
void	segment(t_struct *start, int imin, int jmin, int imax, int jmax);
void	positionne(int map_x, int map_y, int alt, int *screen_x, int *screen_y);
int		get_alt(t_struct *start, int x, int y);
int 	close_w(void *param);
int		key_event(int key, t_struct *param);

#endif
