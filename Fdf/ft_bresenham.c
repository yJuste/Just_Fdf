/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bresenham.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

// ----------------------------PROTOTYPE----------------------------
void	ft_bresenham_line(t_fdf *fdf);
void	ft_bresenham_line_next(t_fdf *fdf, int sx, int sy, int err);
// -----------------------------------------------------------------

/*
void plotLine(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
   int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
   int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1; 
   int err = dx+dy, e2; // error value e_xy
 
   for(;;){  // loop
	mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, 0xfffb00);
      if (x0==x1 && y0==y1) break;
      e2 = 2*err;
      if (e2 >= dy) { err += dy; x0 += sx; } // e_xy+e_x > 0
      if (e2 <= dx) { err += dx; y0 += sy; } // e_xy+e_y < 0
   }
}
*/

void	ft_bresenham_line(t_fdf *fdf)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;

	dx = abs(fdf->c->x1 - fdf->c->x0);
	dy = -abs(fdf->c->y1 - fdf->c->y0);
	if (fdf->c->x0 < fdf->c->x1)
		sx = 1;
	else
		sx = -1;
	if (fdf->c->y0 < fdf->c->y1)
		sy = 1;
	else
		sy = -1;
	err = dx + dy;
	ft_bresenham_line_next(fdf, sx, sy, err);
}

void	ft_bresenham_line_next(t_fdf *fdf, int sx, int sy, int err)
{
	int		dx;
	int		dy;
	int		e2;

	dx = abs(fdf->c->x1 - fdf->c->x0);
	dy = -abs(fdf->c->y1 - fdf->c->y0);
	while (1)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, fdf->c->x0, fdf->c->y0, 0xfffb00);
		if (fdf->c->x0 == fdf->c->x1 && fdf->c->y0 == fdf->c->y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			fdf->c->x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			fdf->c->y0 += sy;
		}
	}
}
