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
void		ft_isometric(int *x, int *y, int *z);
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
void	ft_isometric(int *x, int *y, int *z)
{
	int		tmp;

	tmp = *x;
	*x = (tmp - *y) * cos(0.523599);
	*y = (tmp + *y) * sin(0.523599) - *z;
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
	map->wid *= fdf->cam->zoom;
	map->hei *= fdf->cam->zoom;
}
