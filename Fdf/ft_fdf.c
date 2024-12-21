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

// -----------------------PROTOTYPE------------------------
void		ft_error(t_fdf *fdf, char *error, int e);
void		ft_init(t_fdf **fdf);
// --------------------------------------------------------

int	main(int argc, char **argv)
{
	t_fdf		*fdf;

	fdf = NULL;
	if (argc == 1)
	{
		ft_init(&fdf);
		fdf->mlx = mlx_init();
		fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Fdf by Juste");
		ft_fdf(fdf, fdf->img);
		// mlx_hook(fdf->win, 17, 0, close_window, fdf);
		// mlx_key_hook(fdf->win, ft_zoom, fdf);
		mlx_loop(fdf->mlx);
	}
	else
		ft_error(fdf, strerror(ENOEXEC), 1);
	return (0);
}

void	ft_init(t_fdf **fdf)
{
	*fdf = ft_calloc(1, sizeof(t_fdf));
	(*fdf)->img = ft_calloc(1, sizeof(t_img));
	(*fdf)->map = ft_calloc(1, sizeof(t_map));
	(*fdf)->cam = ft_calloc(1, sizeof(t_camera));
}

void	ft_error(t_fdf *fdf, char *error, int e)
{
	if (fdf)
		free(fdf);
	ft_printf(2, "%s\n", error);
	exit(e);
}
