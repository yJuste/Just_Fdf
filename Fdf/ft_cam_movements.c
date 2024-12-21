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
void		ft_isometric(int *x, int *y, int *z);
void		ft_translate(t_camera *cam, int *x, int *y);
void		ft_zoom(t_fdf *fdf, t_map *map);
// --------------------------------------------------------

void	ft_isometric(int *x, int *y, int *z)
{
	int		tmp;

	tmp = *x;
	*x = (tmp - *y) * cos(0.523599);
	*y = (tmp + *y) * sin(0.523599) - *z;
}

void	ft_translate(t_camera *cam, int *x, int *y)
{
	*x += cam->offset_x;
	*y += cam->offset_y;
}

void	ft_zoom(t_fdf *fdf, t_map *map)
{
	map->wid = WIDTH / map->width * fdf->cam->zoom;
	map->hei = HEIGHT / map->height * fdf->cam->zoom;
}
