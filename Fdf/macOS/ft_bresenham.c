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

// ----------------------------------PROTOTYPE---------------------------------
void		ft_bresenham_line(t_fdf *fdf, t_map *map);
void		ft_bresenham_line_next(t_fdf *fdf, t_map *map, int sx, int sy);
void		ft_pixel_put(t_img *img, int x, int y, int color);
int			ft_color(t_img *img);
// ----------------------------------------------------------------------------

// Algorithme de bresenham.
void	ft_bresenham_line(t_fdf *fdf, t_map *map)
{
	int		sx;
	int		sy;

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
		ft_pixel_put(fdf->img, map->x0, map->y0, map->color);
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

// Fonction d'ajout de pixel pour mlx_new_image.
void	ft_pixel_put(t_img *img, int x, int y, int color)
{
	char		*pixel;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	pixel = img->addr + (y * img->size + x * (img->bpp / 8));
	*(int *)pixel = color;
}

// Fonction pour trnasformer une couleure hexa en RGB ( hexa est mieux en fait).
int	ft_color(t_img *img)
{
	return ((img->red << 16) | (img->green << 8) | img->blue);
}
