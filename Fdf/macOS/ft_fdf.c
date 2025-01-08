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

// ------------------PROTOTYPE----------------------
int			ft_close_window(t_fdf *fdf);
void		ft_init(t_fdf **fdf);
void		ft_error(t_fdf *fdf, int error);
void		ft_free_fdf(t_fdf *fdf);
// -------------------------------------------------

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
		ft_fdf(fdf, fdf->img);
		mlx_hook(fdf->win, 2, 0, ft_key_hook, fdf);
		mlx_hook(fdf->win, 17, 0, ft_close_window, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		ft_error(fdf, ENOENT);
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

// Fonction d'erreur.
void	ft_error(t_fdf *fdf, int error)
{
	if (fdf)
		ft_free_fdf(fdf);
	if (fdf)
		free(fdf);
	ft_printf(2, "%s\n", strerror(error));
	exit(error);
}

// Libére toutes les variables dans fdf.
/* Ne pas ajouter cette ligne si mlx_destroy_display() n'existe pas.
 *	if (fdf->mlx)
 *		free(fdf->mlx);
 */
void	ft_free_fdf(t_fdf *fdf)
{
	if (fdf->map->map)
		ft_free_strs(fdf->map, (void **)fdf->map->map, 'i');
	if (fdf->map->colors)
		ft_free_strs(fdf->map, (void **)fdf->map->colors, 'i');
	if (fdf->menu->rotation)
		mlx_destroy_image(fdf->mlx, fdf->menu->rotation);
	if (fdf->menu->translation)
		mlx_destroy_image(fdf->mlx, fdf->menu->translation);
	if (fdf->menu->zoom)
		mlx_destroy_image(fdf->mlx, fdf->menu->zoom);
	if (fdf->menu->projection_height)
		mlx_destroy_image(fdf->mlx, fdf->menu->projection_height);
	if (fdf->img->ptr)
		mlx_destroy_image(fdf->mlx, fdf->img->ptr);
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	free(fdf->img);
	free(fdf->cam);
	free(fdf->map);
	free(fdf->menu);
	free(fdf->cohen);
}
