/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menu_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Affiche le menu et les aides.                                 PART 2   */
/* ************************************************************************** */
#include "ft_fdf.h"

// -------------------------PROTOTYPE--------------------------
void		ft_put_image_translation(t_fdf *fdf);
void		ft_put_image_rotation(t_fdf *fdf);
void		ft_put_image_zoom(t_fdf *fdf);
void		ft_put_image_projection_and_height(t_fdf *fdf);
void		ft_header(t_fdf *fdf);
// ------------------------------------------------------------

// Fonction pour afficher l'image de la rotation.
void	ft_put_image_rotation(t_fdf *fdf)
{
	int		width;
	int		height;

	width = 300;
	height = 200;
	fdf->menu->rotation = mlx_xpm_file_to_image(fdf->mlx,
			"Images/rotation.xpm", &width, &height);
	mlx_put_image_to_window(fdf->mlx, fdf->win,
		fdf->menu->rotation, 55, 180);
}

// Fonction pour afficher l'image de la translation.
void	ft_put_image_translation(t_fdf *fdf)
{
	int		width;
	int		height;

	width = 300;
	height = 200;
	fdf->menu->translation = mlx_xpm_file_to_image(fdf->mlx,
			"Images/translation.xpm", &width, &height);
	mlx_put_image_to_window(fdf->mlx, fdf->win,
		fdf->menu->translation, 55, 320);
}

// Fonction pour afficher l'image du zoom.
void	ft_put_image_zoom(t_fdf *fdf)
{
	int		width;
	int		height;

	width = 300;
	height = 200;
	fdf->menu->zoom = mlx_xpm_file_to_image(fdf->mlx,
			"Images/zoom.xpm", &width, &height);
	mlx_put_image_to_window(fdf->mlx, fdf->win,
		fdf->menu->zoom, 55, 420);
}

// Fonction pour afficher l'image de projection et de la hauteur.
void	ft_put_image_projection_and_height(t_fdf *fdf)
{
	int		width;
	int		height;

	width = 300;
	height = 200;
	fdf->menu->projection_height = mlx_xpm_file_to_image(fdf->mlx,
			"Images/projection_height.xpm", &width, &height);
	mlx_put_image_to_window(fdf->mlx, fdf->win,
		fdf->menu->projection_height, 55, 530);
}

//	----------HEADER FOR FDF----------

// Le header 42 en police Varsity.
void	ft_header(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 20, 10, COLOR_HEADER,
		" ________      __    ___  ");
	mlx_string_put(fdf->mlx, fdf->win, 20, 30, COLOR_HEADER,
		"|_   __  |    |  ] .' ..] ");
	mlx_string_put(fdf->mlx, fdf->win, 20, 50, COLOR_HEADER,
		"  | |_ \\_|.--.| | _| |_   ");
	mlx_string_put(fdf->mlx, fdf->win, 20, 70, COLOR_HEADER,
		"  |  _| / /'`\\' |'-| |-'  ");
	mlx_string_put(fdf->mlx, fdf->win, 20, 90, COLOR_HEADER,
		" _| |_  | \\__/  |  | |    ");
	mlx_string_put(fdf->mlx, fdf->win, 20, 110, COLOR_HEADER,
		"|_____|  '.__.;__][___]   ");
	mlx_string_put(fdf->mlx, fdf->win, 20, 130, COLOR_HEADER,
		"                          ");
}
