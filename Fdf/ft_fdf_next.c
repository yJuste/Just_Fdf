/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

// --------------------PROTOTYPE--------------------
void		ft_fdf(t_fdf *fdf, t_img *img);
void		ft_fdf_next(t_fdf *fdf, t_img *img);
void		ft_draw(t_fdf *fdf);
void		ft_isometric(int *x, int *y, int *z);
void		ft_draw_horizontal(t_fdf *fdf, t_map *map);
// -------------------------------------------------

void	ft_fdf(t_fdf *fdf, t_img *img)
{
	img->ptr = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size, &img->endian);
	ft_printf(1, "bpp: %d\nsize: %d\n", img->bpp, img->size);
	ft_fdf_next(fdf, img);
	mlx_put_image_to_window(fdf->mlx, fdf->win, img->ptr, 0, 0);
	// mlx_destroy_image(fdf->mlx, img->ptr);
}

void	ft_fdf_next(t_fdf *fdf, t_img *img)
{
	fdf->map->width = 4;
	fdf->map->height = 2;
	fdf->cam->zoom = 1;
	ft_draw(fdf);
}

void	ft_draw(t_fdf *fdf)
{
	ft_draw_horizontal(fdf, fdf->map);
	// ft_draw_vertical(fdf, fdf->map);
}

void	ft_isometric(int *x, int *y, int *z)
{
	int		tmp;

	tmp = *x;
	*x = (tmp - *y) * cos(0.523599);
	*y = (tmp + *y) * sin(0.523599) - *z;
}

void	ft_draw_horizontal(t_fdf *fdf, t_map *map)
{
	int		x;
	int		y;
	int		wid;
	int		hei;

	wid = WIDTH / map->width * fdf->cam->zoom;
	hei = HEIGHT / map->height * fdf->cam->zoom;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width - 1)
		{
			map->x0 = x * wid;
			map->y0 = y * hei;
			map->x1 = (x + 1) * wid;
			map->y1 = y * hei;
			ft_bresenham_line(fdf, map);
			ft_isometric(&map->x0, &map->y0, &map->z0);
			ft_isometric(&map->x1, &map->y1, &map->z1);
			x++;
		}
		y++;
	}
}
