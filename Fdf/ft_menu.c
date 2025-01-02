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
#include "ft_fdf.h"

// -----------------PROTOTYPE------------------
void		ft_menu(t_fdf *fdf);
void		ft_menu_next(t_fdf *fdf);
void		ft_background_menu(t_fdf *fdf);
void		ft_header(t_fdf *fdf);
// --------------------------------------------

// Function for printing the menu.
void	ft_menu(t_fdf *fdf)
{
	if (WIDTH > 300)
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
