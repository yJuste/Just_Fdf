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

// -----------------------PROTOTYPE------------------------
void		ft_menu(t_fdf *fdf);
void		ft_menu_next(t_fdf *fdf);
void		ft_background_menu(t_fdf *fdf);
void		ft_header(t_fdf *fdf);
// --------------------------------------------------------

// Function for printing the menu.
void	ft_menu(t_fdf *fdf)
{
	if (WIDTH > 300)
	{
		ft_header(fdf);
		ft_menu_next(fdf);
	}
	return ;
}

void	ft_menu_next(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 20, 160, COLOR_HEADER,
		"TRANSLATION:");
	mlx_string_put(fdf->mlx, fdf->win, 20, 180, COLOR_HEADER,
		"          ^ up");
	mlx_string_put(fdf->mlx, fdf->win, 20, 200, COLOR_HEADER,
		"<- left           -> right");
	mlx_string_put(fdf->mlx, fdf->win, 20, 220, COLOR_HEADER,
		"          v down");
	mlx_string_put(fdf->mlx, fdf->win, 20, 260, COLOR_HEADER,
		"ZOOM:");
	mlx_string_put(fdf->mlx, fdf->win, 20, 280, COLOR_HEADER,
		"+ zoom    - dezoom");
	return ;
}

// Function for printing the background
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

void	ft_header(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 20, 10, COLOR_HEADER, " ________      __    ___  ");
	mlx_string_put(fdf->mlx, fdf->win, 20, 30, COLOR_HEADER, "|_   __  |    |  ] .' ..] ");
	mlx_string_put(fdf->mlx, fdf->win, 20, 50, COLOR_HEADER, "  | |_ \\_|.--.| | _| |_   ");
	mlx_string_put(fdf->mlx, fdf->win, 20, 70, COLOR_HEADER, "  |  _| / /'`\\' |'-| |-'  ");
	mlx_string_put(fdf->mlx, fdf->win, 20, 90, COLOR_HEADER, " _| |_  | \\__/  |  | |    ");
	mlx_string_put(fdf->mlx, fdf->win, 20, 110, COLOR_HEADER, "|_____|  '.__.;__][___]   ");
	mlx_string_put(fdf->mlx, fdf->win, 20, 130, COLOR_HEADER, "                          ");
}
