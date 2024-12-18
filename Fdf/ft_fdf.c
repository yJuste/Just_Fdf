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

// Default Mac Air M2: 1470 x 956
// 	Large resolution: 1710 x 1112
int	main(void)
{
	t_fdf		*fdf;

	fdf = malloc(sizeof(t_fdf));
	if (!fdf)
		return (1);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (1);
	fdf->win = mlx_new_window(fdf->mlx, 1470, 956, "Fdf by Juste");
	if (!fdf->win)
	{
		free(fdf->win);
		free(fdf->mlx);
		return (1);
	}
	free(fdf->win);
	free(fdf->mlx);
	free(fdf);
	return (0);
}
