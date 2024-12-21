/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_tmp.c                                       :+:      :+:    :+:   */
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
void		ft_draw_grid(t_fdf *fdf, t_img *img);
void	ft_draw_grid_and_connect(t_fdf *fdf, t_img *img);
void	ft_draw_vertical(t_fdf *fdf, t_img *img);
void	ft_draw_horizontal(t_fdf *fdf, t_img *img);
int	ft_zoom(int key, t_fdf *fdf);
int			close_window(t_fdf *fdf);
// --------------------------------------------------------


# define NUM_PAD_PLUS		69
# define MAIN_PAD_PLUS		24
# define MOUSE_SCROLL_UP	4

# define MOUSE_SCROLL_DOWN	5
# define NUM_PAD_MINUS		78
# define MAIN_PAD_MINUS		27

int	ft_zoom(int key, t_fdf *fdf)
{
	if (key == NUM_PAD_PLUS ||
		key == MAIN_PAD_PLUS ||
		key == MOUSE_SCROLL_UP)
		fdf->cam->zoom += 0.1;
	else if (key == NUM_PAD_MINUS ||
		key == MAIN_PAD_MINUS ||
		key == MOUSE_SCROLL_DOWN)
		fdf->cam->zoom -= 0.1;
	ft_draw_vertical(fdf, img);
	ft_draw_horizontal(fdf, img);
	return (0);
}

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
	img->red = 0; img->green = 255;
	fdf->m->width = 4;
	fdf->m->height = 2;
	img->c->zoom = 0.1;
	ft_draw_vertical(fdf, img);
	ft_draw_horizontal(fdf, img);
	mlx_put_image_to_window(fdf->mlx, fdf->win, img->img, 0, 0);
	mlx_destroy_image(fdf->mlx, img->img);
	mlx_hook(fdf->win, 17, 0, close_window, fdf);
	mlx_key_hook(fdf->win, ft_zoom, fdf);
}

void	ft_isometric(int *x, int *y, int *z)
{
	int		tmp;

	tmp = *x;
	*x = (tmp - *y) * cos(0.523599);
	*y = (tmp + *y) * sin(0.523599) - *z;
}

void	ft_draw_horizontal(t_fdf *fdf, t_img *img)
{
	int		x;
	int		y;
	int		cell_width;
	int		cell_height;

	cell_width = WIDTH / fdf->m->width * fdf->cam->zoom;
	cell_height = HEIGHT / fdf->m->height * fdf->cam->zoom;
	y = 0;
	while (y < fdf->m->height)
	{
		x = 0;
		while (x < fdf->m->width - 1)
		{
			fdf->c->x0 = x * cell_width;
			fdf->c->y0 = y * cell_height;
			fdf->c->x1 = (x + 1) * cell_width;
			fdf->c->y1 = y * cell_height;
			ft_isometric(&fdf->c->x0, &fdf->c->y0, &fdf->c->z0);
			ft_isometric(&fdf->c->x1, &fdf->c->y1, &fdf->c->z1);
			ft_bresenham_line(fdf, img);
			x++;
		}
		y++;
	}
}

void	ft_draw_vertical(t_fdf *fdf, t_img *img)
{
	int		x;
	int		y;
	int		cell_width;
	int		cell_height;

	cell_width = WIDTH / fdf->m->width * fdf->cam->zoom;
	cell_height = HEIGHT / fdf->m->height * fdf->cam->zoom;
	y = 0;
	while (y < fdf->m->height - 1)
	{
		x = 0;
		while (x < fdf->m->width)
		{
			fdf->c->x0 = x * cell_width;
			fdf->c->y0 = y * cell_height;
			fdf->c->x1 = x * cell_width;
			fdf->c->y1 = (y + 1) * cell_height;
			ft_isometric(&fdf->c->x0, &fdf->c->y0, &fdf->c->z0);
			ft_isometric(&fdf->c->x1, &fdf->c->y1, &fdf->c->z1);
			ft_bresenham_line(fdf, img);
			x++;
		}
		y++;
	}
}

void	ft_init(t_fdf **fdf, t_img **img)
{
	*fdf = ft_calloc(1, sizeof(t_fdf));
	(*fdf)->c = ft_calloc(1, sizeof(t_coord));
	(*fdf)->m = ft_calloc(1, sizeof(t_map));
	*img = ft_calloc(1, sizeof(t_img));
	(*fdf)->cam = ft_calloc(1, sizeof(t_camera));
}

int	close_window(t_fdf *fdf)
{
	ft_printf(1, "Fermeture propre du programme.\n");
	exit(0);

}
