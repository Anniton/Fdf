/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 11:14:33 by aquan             #+#    #+#             */
/*   Updated: 2019/02/08 23:31:13 by aquan            ###   ########.fr       */
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


typedef struct s_check
{
	char	*line;
	char	**s_split;
	int		**tab;
	int		**tmp;
	int		len;
	int		len_of_a_line;
}				t_check;

typedef struct s_tool
{
	int step;
	int left;
	int up;
	int coef_x;
}			t_tool;

typedef struct	s_struct
{
	char	*line;
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
	int		px_color;
	t_tool	*tool;
}				t_struct;

typedef struct s_coord_2
{
	int x;
	int y;
}				t_coord_2;


int		ft_check_x(char *s);
int		ft_arrlen(char **arr);
int		*ft_convert(char **tab);
void	ft_arrcpy(int **src, int **dst, int height, int width);
int		**get_int_tab(int fd, t_struct *start);
int		check_sample_validity(int fd, t_struct *start);
int		isometry(t_struct *start);
int		perspective(t_struct *start);
int 	cross_event(t_struct *env);
int		esc_key(int key, t_struct *env);
int		destroy_all(t_struct *env);
int 	key_event(int key, t_struct *param);
void	pixel_put_img(int *img_str, int x, int y, t_struct *start);
void	bresemham(t_struct *start, t_coord_2 *i, t_coord_2 *f);
void	print_int_tab(int **tab, t_struct *start);
void	commands(t_struct *start);
void	check_color(t_struct *env, int old_c, int new_c);

#endif
