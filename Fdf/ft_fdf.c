/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

int	close_window(t_fdf *fdf)
{
	ft_printf(1, "Fermeture propre du programme.\n");
	exit(0);
}

int	main(void)
{
	t_fdf		*fdf;

	fdf = malloc(sizeof(t_fdf));
	fdf->c = malloc(sizeof(t_coord));
	if (!fdf)
		return (1);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (1);
	fdf->win = mlx_new_window(fdf->mlx, HEIGHT, WIDTH, "Fdf by Juste");
	if (!fdf->win)
	{
		free(fdf->win);
		free(fdf->mlx);
		free(fdf);
		return (1);
	}
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	fdf->c->x0 = 500;
	fdf->c->y0 = 200;
	fdf->c->x1 = 300;
	fdf->c->y1 = 600;
	ft_bresenham_line(fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
