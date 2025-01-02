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

// -------------------------PROTOTYPE--------------------------
void		ft_translate(t_camera *cam, int *x, int *y);
void		ft_zoom(t_camera *cam, int *x, int *y, int *z);
void		ft_rotate_x(int *y, int *z, float angle);
void		ft_rotate_y(int *x, int *z, float angle);
void		ft_rotate_z(int *x, int *y, float angle);
// ------------------------------------------------------------

// Fonction pour translater.
void	ft_translate(t_camera *cam, int *x, int *y)
{
	*x += cam->offset_x;
	*y += cam->offset_y;
}

// Fonction pour zoomer.
void	ft_zoom(t_camera *cam, int *x, int *y, int *z)
{
	*x *= cam->zoom;
	*y *= cam->zoom;
	*z *= cam->zoom;
}

// Fonction pour rotater sur l'axe x.
void	ft_rotate_x(int *y, int *z, float angle)
{
	float		tmp_y;
	float		tmp_z;

	tmp_y = *y;
	tmp_z = *z;
	*y = tmp_y * cos(angle) - tmp_z * sin(angle);
	*z = tmp_y * sin(angle) + tmp_z * cos(angle);
}

// Fonction pour rotater sur l'axe y.
void	ft_rotate_y(int *x, int *z, float angle)
{
	float		tmp_x;
	float		tmp_z;

	tmp_x = *x;
	tmp_z = *z;
	*x = tmp_x * cos(angle) + tmp_z * sin(angle);
	*z = -tmp_x * sin(angle) + tmp_z * cos(angle);
}

// Fonction pour rotater sur l'axe z.
void	ft_rotate_z(int *x, int *y, float angle)
{
	float		tmp_x;
	float		tmp_y;

	tmp_x = *x;
	tmp_y = *y;
	*x = tmp_x * cos(angle) - tmp_y * sin(angle);
	*y = tmp_x * sin(angle) + tmp_y * cos(angle);
}
