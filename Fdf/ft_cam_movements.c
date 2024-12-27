/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

// -----------------------PROTOTYPE------------------------
void		ft_default_dimensions(t_fdf *fdf);
void		ft_projection(t_map *map, float *angle);
void		ft_translate(t_camera *cam, int *x, int *y);
void		ft_zoom(t_fdf *fdf, t_map *map);
// --------------------------------------------------------

// 1. On prend la plus petite echelle pour voir toute la grille en 1er.
// 2. Les cases de la grille sont carre.
void	ft_default_dimensions(t_fdf *fdf)
{
	int		ref;
	int		max_dim;
	int		scale;

	if (WIDTH > HEIGHT)
		ref = HEIGHT;
	else
		ref = WIDTH;
	if (fdf->map->width > fdf->map->height)
		max_dim = fdf->map->width;
	else
		max_dim = fdf->map->height;
	scale = ref / max_dim;
	fdf->map->wid = scale;
	fdf->map->hei = scale;
}

// Rend la grille en vue isometrique.
void	ft_projection(t_map *map, float *angle)
{
	/*
	int		tmp_x;
	int		tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = (tmp_x - tmp_y) * cos(0.523599);
	*y = (tmp_x + tmp_y) * sin(0.523599) - *z;
	*/
	map->x0 = (map->x0 - map->y0) * cos(*angle);
	map->y0 = (map->x0 + map->y0) * sin(*angle) - map->z0;
	map->x1 = (map->x1 - map->y1) * cos(*angle);
	map->y1 = (map->x1 + map->y1) * sin(*angle) - map->z1;
}

// Fonction pour translater.
void	ft_translate(t_camera *cam, int *x, int *y)
{
	*x += cam->offset_x;
	*y += cam->offset_y;
}

// Fonction pour zoomer.
void	ft_zoom(t_fdf *fdf, t_map *map)
{
	map->x0 *= fdf->cam->zoom;
	map->y0 *= fdf->cam->zoom;
	map->z0 *= fdf->cam->zoom;
	map->x1 *= fdf->cam->zoom;
	map->y1 *= fdf->cam->zoom;
	map->z1 *= fdf->cam->zoom;
	// map->wid *= fdf->cam->zoom;
	// map->hei *= fdf->cam->zoom;
}
