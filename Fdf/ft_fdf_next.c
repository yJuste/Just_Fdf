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
void		ft_draw_next(t_fdf *fdf, t_map *map);
void		ft_cohen_sutherland_clip(t_map *map);
void		ft_draw_horizontal(t_fdf *fdf, t_map *map);
void		ft_draw_vertical(t_fdf *fdf, t_map *map);
// -------------------------------------------------

void	ft_fdf(t_fdf *fdf, t_img *img)
{
	img->ptr = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp, &img->size, &img->endian);
	// ft_printf(1, "ptr: %p\nbpp: %d\nsize: %d\nendian : %d\n", fdf->img->ptr, fdf->img->bpp, fdf->img->size, fdf->img->endian);
	ft_fdf_next(fdf, img);
	// mlx_destroy_image(fdf->mlx, img->ptr);
}

void	ft_fdf_next(t_fdf *fdf, t_img *img)
{
	fdf->map->width = 100;
	fdf->map->height = 80;
	fdf->cam->zoom = 1;
	img->green = 255; img->blue = 255; img->red = 255;
	fdf->cam->zoom_ix = 2;
	if (WIDTH * HEIGHT >= 450000)
		fdf->cam->zoom_ix = 25;
	ft_draw(fdf);
	mlx_hook(fdf->win, 2, 0, ft_key_hook, fdf);
}

void	ft_draw(t_fdf *fdf)
{
	ft_clear_image(fdf->img);
	// mlx_clear_window(fdf->mlx, fdf->win);
	ft_default_dimensions(fdf);
	ft_zoom(fdf, fdf->map);
	ft_draw_horizontal(fdf, fdf->map);
	ft_draw_vertical(fdf, fdf->map);
	// int i = 0;
	// ft_printf(1, "pair %d = %p\n", i++, fdf->img->ptr);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->ptr, 0, 0);
	// ft_printf(1, "impair %d = %p\n", i++, fdf->img->ptr);
}

void	ft_draw_next(t_fdf *fdf, t_map *map)
{
	ft_isometric(&map->x0, &map->y0, &map->z0);
	ft_isometric(&map->x1, &map->y1, &map->z1);
	ft_translate(fdf->cam, &map->x0, &map->y0);
	ft_translate(fdf->cam, &map->x1, &map->y1);
	// ft_printf(1, "x0y0:%d;%d\nx1y1:%d;%d\n", map->x0, map->y0, map->x1, map->y1);
	ft_cohen_sutherland_clip(map);
}


int	ft_compute_region_code(int x, int y, int xmin, int xmax, int ymin, int ymax)
{
	int		code;

	code = 0;
	if (x < xmin)
		code |= LEFT;
	else if (x > xmax)
		code |= RIGHT;
	return (code);
}

void	ft_cohen_sutherland_clip(t_map *map)
{
	int		xmin = 0, xmax = WIDTH - 1;
	int		ymin = 0, ymax = HEIGHT - 1;
	int		code0 = ft_compute_region_code(map->x0, map->y0, xmin, xmax, ymin, ymax);
	int		code1 = ft_compute_region_code(map->x1, map->y1, xmin, xmax, ymin, ymax);

	while (1)
	{
		if ((code0 | code1) == 0)
			break ;
		else if (code0 & code1)
		{
			map->x0 = -1;
			map->x1 = -1;
			return ;
		}
		else
		{
			int		code_out;
			int		x, y;

			if (code0 != 0)
				code_out = code0;
			else
				code_out = code1;
			if (code_out & LEFT)
			{
				x = xmin;
				y = map->y0 + (map->y1 - map->y0) * (xmin - map->x0) / (map->x1 - map->x0);
			}
			else if (code_out & RIGHT)
			{
				x = xmax;
				y = map->y0 + (map->y1 - map->y0) * (xmax - map->x0) / (map->x1 - map->x0);
			}
			if (code_out == code0)
			{
				map->x0 = x;
				map->y0 = y;
				code0 = ft_compute_region_code(map->x0, map->y0, xmin, xmax, ymin, ymax);
			}
			else
			{
				map->x1 = x;
				map->y1 = y;
				code1 = ft_compute_region_code(map->x1, map->y1, xmin, xmax, ymin, ymax);
			}
		}
	}
}

void	ft_draw_horizontal(t_fdf *fdf, t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width - 1)
		{
			map->x0 = x * map->wid;
			map->y0 = y * map->hei;
			map->x1 = (x + 1) * map->wid;
			map->y1 = y * map->hei;
			ft_draw_next(fdf, map);
			if (map->x0 >= 0 && map->y0 >= -(fdf->cam->zoom * fdf->cam->zoom_ix))
				ft_bresenham_line(fdf, map);
			x++;
		}
		y++;
	}
}

void	ft_draw_vertical(t_fdf *fdf, t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height - 1)
	{
		x = 0;
		while (x < map->width)
		{
			map->x0 = x * map->wid;
			map->y0 = y * map->hei;
			map->x1 = x * map->wid;
			map->y1 = (y + 1) * map->hei;
			ft_draw_next(fdf, map);
			if (map->x0 >= 0 && map->y0 >= -(fdf->cam->zoom * fdf->cam->zoom_ix))
				ft_bresenham_line(fdf, map);
			x++;
		}
		y++;
	}
}
