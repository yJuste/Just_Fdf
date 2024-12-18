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

int close_window(t_fdf *fdf)
{
    	printf("Fermeture propre du programme.\n");
	exit(0);
}

void plotLine(t_fdf *fdf, int x0, int y0, int x1, int y1)
{
   int dx =  abs(x1-x0), sx = x0<x1 ? 1 : -1;
   int dy = -abs(y1-y0), sy = y0<y1 ? 1 : -1; 
   int err = dx+dy, e2; /* error value e_xy */
 
   for(;;){  /* loop */
	mlx_pixel_put(fdf->mlx, fdf->win, x0, y0, 0xfffb00);
      if (x0==x1 && y0==y1) break;
      e2 = 2*err;
      if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
      if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
   }
}

int	main(void)
{
	t_fdf		*fdf;

	fdf = malloc(sizeof(t_fdf));
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
	plotLine(fdf, 100, 200, 300, 400);
	mlx_loop(fdf->mlx);
	return (0);
}
