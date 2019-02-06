#include "fdf.h"

void	ligne_2(t_struct *start, t_coord_2 *i, t_coord_2 *f)
{
	int m;
	int cumul;
	int x;
	int y;

	x = i->x;
	y = i->y;
	cumul = abs(f->y - i->y) / 2;
	m = 1;
	while (m <= abs(f->y - i->y))
	{
		y += (i->y < f->y) ? 1 : -1;
		cumul += abs(f->x - i->x);
		if (cumul >= abs(f->y - i->y))
		{
			cumul -= abs(f->y - i->y);
			x += (i->x < f->x) ? 1 : -1;
		}
		mlx_pixel_put(start->mlx_ptr, start->win_ptr, x, y, color);
		m++;
	}
}

void	ligne_3(t_struct *start, t_coord_2 *i, t_coord_2 *f)
{
	int m;
	int cumul;
	int x;
	int y;

	x = i->x;
	y = i->y;
	cumul = abs(f->x - i->x) / 2;
	m = 1;
	while (m <= abs(f->x - i->x))
	{
		x += (i->x < f->x) ? 1 : -1;
		cumul += abs(f->y - i->y);
		if (cumul >= abs(f->y - i->y))
		{
			cumul -= abs(f->x - i->x);
			y += (i->y < f->y) ? 1 : -1;
		}
		mlx_pixel_put(start->mlx_ptr, start->win_ptr, x, y, color);
		m++;
	}
}

void	ligne(t_struct *start, t_coord_2 *i, t_coord_2 *f)
{
	int x;
	int y;

	x = i->x;
	y = i->y;
	mlx_pixel_put(start->mlx_ptr, start->win_ptr, x, y, color);
	if (abs(f->x - i->x) > abs(f->y - i->y))
		ligne_3(start, i, f);
	else
		ligne_2(start, i, f);
}
