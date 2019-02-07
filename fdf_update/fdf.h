/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:14:33 by aquan             #+#    #+#             */
/*   Updated: 2019/02/07 17:43:24 by aquan            ###   ########.fr       */
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

# define color 0xFFFFFF
# define SIZE 2048
# define RGB


typedef struct s_tool
{
	int step;
	int left;
	int up;
	int coef_x;
}			t_tool;

typedef struct	s_struct
{
	int		nb_x;
	int 	nb_y;
	int 	win_h;
	int		win_w;
	int 	firstline;
	int 	**final;
	void	*mlx_ptr;
	void	*win_ptr;
	void 	*img_ptr;
	int 	*img_str;
	int		affichage;
	int		l;
	int 	bpp;
	int 	e;
	t_tool	*tool;
}				t_struct;

typedef struct s_coord_2
{
	int x;
	int y;
}				t_coord_2;


int		**get_int_tab(int fd, t_struct *start);
void	print_int_tab(int **tab, t_struct *start);
int		ft_check_x(char *s);
int		ft_count_y(char *s, t_struct *start);
int		ft_checkline(char *s);
int		ft_checkfirstline(char *s, t_struct *start);
int		check_sample_validity(int fd, t_struct *start);
int		afficher(t_struct *start);
int		afficher_pc(t_struct *start);
void	ligne_1(t_struct *start, t_coord_2 *i, t_coord_2 *f);
void	ligne_2(t_struct *start, t_coord_2 *i, t_coord_2 *f);
void	ligne_3(t_struct *start, t_coord_2 *i, t_coord_2 *f);
int 	close_w(void *param);
void	move_left(int key, t_struct *param);
int 	key_event(int key, t_struct *param);
int		put_berk(t_struct *param);
void	pixel_put_img(int *img_ptr, int x, int y, int px_color, t_struct *start);
int     pixel_color(t_struct *start, int y, int x);
int 	get_alt(t_struct *start, int y, int x);
void	info_put(t_struct *start);
#endif
