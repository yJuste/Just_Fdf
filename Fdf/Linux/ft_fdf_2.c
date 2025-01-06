/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Affiche les lignes et applique les rendus.                             */
/* ************************************************************************** */
#include "ft_fdf.h"

// -----------------------------PROTOTYPE-----------------------------
void		ft_fdf(t_fdf *fdf, t_img *img);
void		ft_fdf_next(t_fdf *fdf);
void		ft_draw(t_fdf *fdf);
void		ft_draw_next(t_fdf *fdf, t_map *map);
void		ft_draw_lines(t_fdf *fdf, t_map *map, int dx, int dy);
// -------------------------------------------------------------------

// Fonction principale de fdf.
void	ft_fdf(t_fdf *fdf, t_img *img)
{
	img->ptr = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr,
			&img->bpp, &img->size, &img->endian);
	ft_fdf_next(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, ft_key_hook, fdf);
}

void	ft_fdf_next(t_fdf *fdf)
{
	if (WIDTH * HEIGHT >= 450000)
		fdf->cam->zoom_ix = 300;
	fdf->cam->offset_x = WIDTH / 3;
	fdf->cam->offset_y = HEIGHT / 3;
	fdf->cam->height = 3;
	fdf->cam->zoom_ix = 200;
	fdf->cam->zoom = 1;
	fdf->cam->projection = 'i';
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
	fdf->cohen->xmin = 0;
	fdf->cohen->xmax = WIDTH - 1;
	fdf->cohen->ymin = 0;
	fdf->cohen->ymax = HEIGHT - 1;
	ft_translate(fdf->cam, &fdf->map->x0, &fdf->map->y0);
	ft_translate(fdf->cam, &fdf->map->x1, &fdf->map->y1);
	ft_draw(fdf);
}

// Fonction pour dessiner la grille.
/*
 * note: j'enleve ft_menu car l'optimisation des PC de 42 est assez
 * mauvaise.
 * l.1-2;
 *	if (WIDTH > MIN_MENU)
 *		ft_background_menu(fdf);
 * l.5-6:
 * 	ft_menu(fdf);
 */
void	ft_draw(t_fdf *fdf)
{
	ft_clear_image(fdf, fdf->img);
	ft_default_dimensions(fdf);
	ft_draw_lines(fdf, fdf->map, 1, 0);
	ft_draw_lines(fdf, fdf->map, 0, 1);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->ptr, 0, 0);
}

// Fonction pour appliquer certains rendus directement
//   pendant le processus d'ajout de point.
void	ft_draw_next(t_fdf *fdf, t_map *map)
{
	ft_zoom(fdf->cam, &map->x0, &map->y0, &map->z0);
	ft_zoom(fdf->cam, &map->x1, &map->y1, &map->z1);
	ft_rotate_x(&map->y0, &map->z0, fdf->cam->alpha);
	ft_rotate_x(&map->y1, &map->z1, fdf->cam->alpha);
	ft_rotate_y(&map->x0, &map->z0, fdf->cam->beta);
	ft_rotate_y(&map->x1, &map->z1, fdf->cam->beta);
	ft_rotate_z(&map->x0, &map->y0, fdf->cam->gamma);
	ft_rotate_z(&map->x1, &map->y1, fdf->cam->gamma);
	ft_projection(map, fdf->cam->projection);
	ft_translate(fdf->cam, &map->x0, &map->y0);
	ft_translate(fdf->cam, &map->x1, &map->y1);
	ft_cohen_sutherland_clip(map, fdf->cohen);
}

// 1. Fonction pour desiner les lignes.
// 2. La condition if avec zoom_ix est pour optimiser le code.
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
			map->z0 = map->map[y][x] * fdf->cam->height;
			map->z1 = map->map[y + dy][x + dx] * fdf->cam->height;
			map->color = map->colors[y][x];
			ft_draw_next(fdf, map);
			if (map->x0 >= 0 && map->y0
				>= -(fdf->cam->zoom * fdf->cam->zoom_ix))
				ft_bresenham_line(fdf, map);
			x++;
		}
		y++;
	}
}
