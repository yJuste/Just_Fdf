/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam_movements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

// -----------------------PROTOTYPE------------------------
void		ft_translate(t_camera *cam, int *x, int *y);
void		ft_zoom(t_fdf *fdf, t_map *map);
void		ft_rotate_x(t_camera *cam, int *y, int *z, float angle);
void		ft_rotate_y(t_camera *cam, int *x, int *z, float angle);
void		ft_rotate_z(t_camera *cam, int *x, int *y, float angle);
// --------------------------------------------------------


// Fonction pour translater.
void	ft_translate(t_camera *cam, int *x, int *y)
{
	*x += cam->offset_x;
	*y += cam->offset_y;
}

// Fonction pour zoomer.
void	ft_zoom(t_fdf *fdf, t_map *map)
{
	map->x0 *= fdf->cam->zoom;
	map->y0 *= fdf->cam->zoom;
	map->z0 *= fdf->cam->zoom;
	map->x1 *= fdf->cam->zoom;
	map->y1 *= fdf->cam->zoom;
	map->z1 *= fdf->cam->zoom;
}

void ft_rotate_x(t_camera *cam, int *y, int *z, float angle)
{
    float tmp_y = *y;
    float tmp_z = *z;

    *y = tmp_y * cos(angle) - tmp_z * sin(angle);
    *z = tmp_y * sin(angle) + tmp_z * cos(angle);
}

void ft_rotate_y(t_camera *cam, int *x, int *z, float angle)
{
    float tmp_x = *x;
    float tmp_z = *z;

    *x = tmp_x * cos(angle) + tmp_z * sin(angle);
    *z = -tmp_x * sin(angle) + tmp_z * cos(angle);
}

void ft_rotate_z(t_camera *cam, int *x, int *y, float angle)
{
    float tmp_x = *x;
    float tmp_y = *y;

    *x = tmp_x * cos(angle) - tmp_y * sin(angle);
    *y = tmp_x * sin(angle) + tmp_y * cos(angle);
}
