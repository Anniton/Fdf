/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aquan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:51:20 by aquan             #+#    #+#             */
/*   Updated: 2018/12/30 20:09:24 by aquan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include "../Libft/libft.h"
# include <unistd.h>
# include "mlx.h"
# include <math.h>

# define color 0xFF6347
# define KEY_ESC   53
# define BUT_LEFT 1
# define BUT_RIGHT 2
typedef struct		s_param
{
	void	*mlx;
	void	*win;
	int		x1;
	int 	y1;
	int 	x2;
	int		y2;
	int		pix_color;
}					t_param;

void	ft_line(int xi, int yi, int xf, int yf, void *mlx, void *win);
int		key_hook(int key, t_param *e);
int		red_cross(t_param *e);
int		mouse_hook(int button, int x, int y, t_param *e);
int		mouse_press(int button, int x, int y, t_param *e);
int		mouse_movement(int x, int y, t_param *e);
int		mouse_release(int button, int x, int y, t_param *e);
int		checkfile(char *buf);
int		samplevalidity(char *argv);
int		main();

#endif
