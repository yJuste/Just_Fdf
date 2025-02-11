/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Affiche le menu et les aides.                                 PART 1   */
/* ************************************************************************** */
#include "ft_fdf.h"

// -----------------------PROTOTYPE------------------------
void		ft_menu(t_fdf *fdf);
void		ft_menu_next(t_fdf *fdf);
void		ft_background_menu(t_fdf *fdf);
void		ft_default_dimensions(t_fdf *fdf);
void		ft_projection(t_map *map, char projection);
// --------------------------------------------------------

// Fonction pour afficher le menu.
void	ft_menu(t_fdf *fdf)
{
	if (WIDTH > MIN_MENU)
	{
		ft_header(fdf);
		ft_menu_next(fdf);
		ft_put_image_translation(fdf);
		ft_put_image_rotation(fdf);
		ft_put_image_zoom(fdf);
		ft_put_image_projection_and_height(fdf);
	}
}

void	ft_menu_next(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 25, 160, COLOR_HEADER,
		"------ translation ------");
	mlx_string_put(fdf->mlx, fdf->win, 25, 300, COLOR_HEADER,
		"-------- rotation -------");
	mlx_string_put(fdf->mlx, fdf->win, 25, 430, COLOR_HEADER,
		"---------- zoom ---------");
	mlx_string_put(fdf->mlx, fdf->win, 25, 510, COLOR_HEADER,
		"-- projection / height --");
	mlx_string_put(fdf->mlx, fdf->win, 25, 530, COLOR_HEADER,
		"        and RESET        ");
	mlx_string_put(fdf->mlx, fdf->win, 15, HEIGHT - 30, COLOR_HEADER,
		"by Juste              2024");
}

// Fonction pour afficher le background.
void	ft_background_menu(t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < 300)
		{
			ft_pixel_put(fdf->img, x, y, COLOR_MENU);
			x++;
		}
		y++;
	}
}

//	----------PROJECTION x DEFAULT_DIMENSIONS----------

// 1. On prend la plus petite échelle pour voir toute la grille en 1er.
// 2. Les cases de la grille sont carrés.
void	ft_default_dimensions(t_fdf *fdf)
{
	int		ref;
	int		max_dim;
	int		scale;

	if (fdf->map->width < 500 && fdf->map->height < 500)
	{
		if (WIDTH > HEIGHT)
			ref = HEIGHT;
		else
			ref = WIDTH;
	}
	else
	{
		if (fdf->map->width > fdf->map->height)
			ref = fdf->map->width;
		else
			ref = fdf->map->height;
	}
	if (fdf->map->width > fdf->map->height)
		max_dim = fdf->map->width;
	else
		max_dim = fdf->map->height;
	scale = ref / max_dim;
	fdf->map->wid = scale;
	fdf->map->hei = scale;
}

// 1. Rend la grille en vue une spécifique.
// 2. Projection 1 est la vue isométrique.
// 3. Projection 2 est la vue orthogonale.
void	ft_projection(t_map *map, char projection)
{
	if (projection == 'i')
	{
		map->x0 = (map->x0 - map->y0) * cos(0.523599);
		map->y0 = (map->x0 + map->y0) * sin(0.523599) - map->z0;
		map->x1 = (map->x1 - map->y1) * cos(0.523599);
		map->y1 = (map->x1 + map->y1) * sin(0.523599) - map->z1;
	}
}
