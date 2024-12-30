/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam_movements_next.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

// ---------------------PROTOTYPE----------------------
void		ft_default_dimensions(t_fdf *fdf);
void		ft_projection(t_map *map, float angle);
// ----------------------------------------------------

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

// Rend la grille en une vue specifique.
void	ft_projection(t_map *map, float angle)
{
	map->x0 = (map->x0 - map->y0) * cos(angle);
	map->y0 = (map->x0 + map->y0) * sin(angle) - map->z0;
	map->x1 = (map->x1 - map->y1) * cos(angle);
	map->y1 = (map->x1 + map->y1) * sin(angle) - map->z1;
}
