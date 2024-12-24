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

// --------------------------------PROTOTYPE-------------------------------
int		ft_color(t_img *img);
void	ft_pixel_put(t_img *img, int x, int y, int color);
void	ft_bresenham_line(t_fdf *fdf, t_map *map);
void	ft_bresenham_line_next(t_fdf *fdf, t_map *map, int sx, int sy);
// ------------------------------------------------------------------------

int	ft_color(t_img *img)
{
    return ((img->red << 16) | (img->green << 8) | img->blue);
}

void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char		*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = img->addr + (y * img->size + x * (img->bpp / 8));
	*(int *)pixel = color;
}

void	ft_bresenham_line(t_fdf *fdf, t_map *map)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;

	dx = abs(map->x1 - map->x0);
	dy = -abs(map->y1 - map->y0);
	if (map->x0 < map->x1)
		sx = 1;
	else
		sx = -1;
	if (map->y0 < map->y1)
		sy = 1;
	else
		sy = -1;
	ft_bresenham_line_next(fdf, map, sx, sy);
}

void	ft_bresenham_line_next(t_fdf *fdf, t_map *map, int sx, int sy)
{
	int		dx;
	int		dy;
	int		err;
	int		e2;

	dx = abs(map->x1 - map->x0);
	dy = -abs(map->y1 - map->y0);
	err = dx + dy;
	while (1)
	{
		ft_pixel_put(fdf->img, map->x0, map->y0, ft_color(fdf->img));
		if (map->x0 == map->x1 && map->y0 == map->y1)
			break ;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			map->x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			map->y0 += sy;
		}
	}
}

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
