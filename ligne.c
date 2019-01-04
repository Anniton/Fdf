#include "fdf.h"

void	ligne(void *mlx_ptr, void *win_ptr, int xi, int yi, int xf, int yf)
{
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;

	x = xi;
	y = yi;
	dx = abs(xf - xi);
	dy = abs (yf - yi);
	xinc = (xi < xf) ? 1 : -1;
	yinc = (yi < yf) ? 1 : -1;
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
	if (dy == 0)
		yinc = 0;
	if (dx > dy)
	{
		cumul = dx / 2;
		i = 1;
		while (i <= dx)
		{
			x += xinc;
			cumul += dy;
			if (cumul >= dy)
			{
				cumul -= dx;
				y += yinc;
			}
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			i++;
		}
	}
	else
	{
		cumul = dy / 2;
		i = 1;
		while (i <= dy)
		{
			y += yinc;
			cumul += dx;
			if (cumul >= dy)
			{
				cumul -= dy;
				x += xinc;
			}
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
			i++;
		}
	}

}
