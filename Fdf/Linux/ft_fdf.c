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
/*   • Affiche des cartes 2D en projection 3D.                       PART 1   */
/*   • ./a.out [ file ]                                                       */
/*      -> file   [ .fdf ]                                                    */
/* ************************************************************************** */
#include "ft_fdf.h"

// ------------------PROTOTYPE------------------
int			ft_loop_hook(t_fdf *fdf);
int			ft_close_window(t_fdf *fdf);
void		ft_error(t_fdf *fdf, int error);
void		ft_init(t_fdf **fdf);
// ---------------------------------------------

int	main(int argc, char **argv)
{
	t_fdf		*fdf;

	fdf = NULL;
	if (argc == 2)
	{
		ft_init(&fdf);
		ft_parse_map(fdf, fdf->map, argv);
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Just'Fdf");
		fdf->img->ptr = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
		fdf->img->addr = mlx_get_data_addr(fdf->img->ptr, &fdf->img->bpp,
				&fdf->img->size, &fdf->img->endian);
		ft_fdf(fdf);
		mlx_hook(fdf->win, 2, 1L << 0, ft_key_hook, fdf);
		mlx_hook(fdf->win, 17, 1L << 17, ft_close_window, fdf);
		mlx_loop_hook(fdf->mlx, ft_loop_hook, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		ft_error(fdf, ENOENT);
	return (0);
}

// Applique les modifs de mlx_hook.
int	ft_loop_hook(t_fdf *fdf)
{
	ft_draw(fdf);
	return (0);
}

// Ferme la fenêtre.
int	ft_close_window(t_fdf *fdf)
{
	if (fdf)
		ft_free_fdf(fdf);
	if (fdf)
		free(fdf);
	ft_printf(1, "Window closed\n");
	exit(2);
	return (0);
}

// Fonction d'erreur.
void	ft_error(t_fdf *fdf, int error)
{
	if (fdf)
		ft_free_fdf(fdf);
	if (fdf)
		free(fdf);
	if (error == -1)
		ft_printf(2, "Format should be .fdf\n");
	else
		ft_printf(2, "%s\n", strerror(error));
	exit(error);
}

// 1. Alloue de la mémoire pour chaque structure.
// 2. Met toutes les variables à 0.
void	ft_init(t_fdf **fdf)
{
	*fdf = ft_calloc(1, sizeof(t_fdf));
	(*fdf)->img = ft_calloc(1, sizeof(t_img));
	(*fdf)->map = ft_calloc(1, sizeof(t_map));
	(*fdf)->cam = ft_calloc(1, sizeof(t_camera));
	(*fdf)->menu = ft_calloc(1, sizeof(t_menu));
	(*fdf)->cohen = ft_calloc(1, sizeof(t_cohen));
}
