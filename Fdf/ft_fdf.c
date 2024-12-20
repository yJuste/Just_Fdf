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
void		ft_fdf(t_fdf *fdf, t_img *img);
void		ft_init(t_fdf **fdf, t_img **img);
void		ft_draw_map(t_fdf *fdf, t_img *img);
int			close_window(t_fdf *fdf);
// --------------------------------------------------------

int	main(void)
{
	t_fdf		*fdf;
	t_img		*img;

	ft_init(&fdf, &img);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "Fdf by Juste");
	ft_fdf(fdf, img);
	mlx_loop(fdf->mlx);
	return (0);
}

void	ft_fdf(t_fdf *fdf, t_img *img)
{
	img->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->size, &img->endian);
	ft_printf(1, "bpp: %d\nsize: %d\n", img->bpp, img->size);
	fdf->c->x0 = 400;
	fdf->c->y0 = 300;
	fdf->c->x1 = 200;
	fdf->c->y1 = 100;
	img->red = 255;
	ft_bresenham_line(fdf, img);
	img->red = 0; img->green = 255;
	ft_draw_map(fdf, img);
	mlx_put_image_to_window(fdf->mlx, fdf->win, img->img, 0, 0);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
}

void	ft_draw_map(t_fdf *fdf, t_img *img)
{
	int		x;
	int		y;

	x = 0;
 	while (x < WIDTH)
 	{
		y = 0;
		while (y < HEIGHT)
		{
			fdf->c->x0 = x - WIDTH / 2;
			fdf->c->y0 = y - HEIGHT / 2;
			fdf->c->x1 = x - WIDTH / 2 + 1;
			fdf->c->y1 = y - HEIGHT / 2;
			ft_bresenham_line(fdf, img);
			fdf->c->x0 = x - WIDTH / 2;
			fdf->c->y0 = y - HEIGHT / 2;
			fdf->c->x1 = x - WIDTH / 2;
			fdf->c->y1 = y - HEIGHT / 2 + 1;
			ft_bresenham_line(fdf, img);
			y++;
		}
		x++;
	}
}

void	ft_init(t_fdf **fdf, t_img **img)
{
	*fdf = ft_calloc(1, sizeof(t_fdf));
	(*fdf)->c = ft_calloc(1, sizeof(t_coord));
	*img = ft_calloc(1, sizeof(t_img));
}

int	close_window(t_fdf *fdf)
{
	ft_printf(1, "Fermeture propre du programme.\n");
	exit(0);

}
