/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

// --------------------PROTOTYPE--------------------
void		ft_fdf(t_fdf *fdf, t_img *img);
void		ft_fdf_next(t_fdf *fdf, t_img *img);
void		ft_draw(t_fdf *fdf);
void		ft_draw_next(t_fdf *fdf, t_map *map);
void		ft_draw_lines(t_fdf *fdf, t_map *map, int dx, int dy);
// -------------------------------------------------

// Fonction principale
void	ft_fdf(t_fdf *fdf, t_img *img)
{
	img->ptr = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size, &img->endian);
	ft_fdf_next(fdf, img);
	// mlx_destroy_image(fdf->mlx, img->ptr);
}

void	ft_fdf_next(t_fdf *fdf, t_img *img)
{
	fdf->cam->zoom = 1;
	img->green = 0; img->blue = 0; img->red = 0;
	fdf->cam->zoom_ix = 2;
	if (WIDTH * HEIGHT >= 450000)
		fdf->cam->zoom_ix = 25;
	ft_draw(fdf);
	mlx_hook(fdf->win, 2, 0, ft_key_hook, fdf);
}

// Fonction pour dessiner la grille
void	ft_draw(t_fdf *fdf)
{
	ft_clear_image(fdf, fdf->img);
	ft_default_dimensions(fdf);
	ft_draw_lines(fdf, fdf->map, 1, 0);
	ft_draw_lines(fdf, fdf->map, 0, 1);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->ptr, 0, 0);
	ft_menu(fdf);
}
# include <stdio.h>

// Fonction pour appliquer certains rendus directement pendant le processus d'ajout de point
void	ft_draw_next(t_fdf *fdf, t_map *map)
{
	ft_zoom(fdf, map);
	// fdf->cam->angle = 0.523599;
	fdf->cam->angle = 0;
	ft_rotate_x(fdf->cam, &map->y0, &map->z0, fdf->cam->alpha);
	ft_rotate_x(fdf->cam, &map->y1, &map->z1, fdf->cam->alpha);
	ft_rotate_y(fdf->cam, &map->x0, &map->z0, fdf->cam->beta);
	ft_rotate_y(fdf->cam, &map->x1, &map->z1, fdf->cam->beta);
	ft_rotate_z(fdf->cam, &map->x0, &map->y0, fdf->cam->gamma);
	ft_rotate_z(fdf->cam, &map->x1, &map->y1, fdf->cam->gamma);
	printf("%f", fdf->cam->alpha);
	printf("%f", fdf->cam->beta);
	printf("%f", fdf->cam->gamma);
	printf("\n");
	ft_projection(map, fdf->cam->angle);
	/*
	if (map->z0 > 0)
		map->y0 -= map->z0;
	if (map->z1 > 0)
		map->y1 -= map->z1;
	*/
	ft_translate(fdf->cam, &map->x0, &map->y0);
	ft_translate(fdf->cam, &map->x1, &map->y1);
	ft_cohen_sutherland_clip(map);
}

// 1. Fonction pour desiner les lignes
// 2. La condition if avec zoom_ix est pour optimiser le code
void	ft_draw_lines(t_fdf *fdf, t_map *map, int dx, int dy)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height - (dy > 0))
	{
		x = 0;
		while (x < map->width - (dx > 0))
		{
			map->x0 = x * map->wid;
			map->y0 = y * map->hei;
			map->x1 = (x + dx) * map->wid;
			map->y1 = (y + dy) * map->hei;
			map->z0 = map->map[y][x] * 10;
			map->z1 = map->map[y + dy][x + dx] * 10;
			ft_draw_next(fdf, map);
			if (map->x0 >= 0 && map->y0 >=
				-(fdf->cam->zoom * fdf->cam->zoom_ix))
				ft_bresenham_line(fdf, map);
			x++;
		}
		y++;
	}
}
