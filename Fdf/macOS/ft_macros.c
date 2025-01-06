/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_macros.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Gestion des touches du clavier.                                        */
/* ************************************************************************** */
#include "ft_fdf.h"

// -----------------------------PROTOTYPE-----------------------------
int			ft_key_hook(int keycode, t_fdf *fdf);
void		ft_key_zoom(int keycode, t_fdf *fdf);
void		ft_key_translate(int keycode, t_fdf *fdf);
void		ft_key_rotate(int keycode, t_fdf *fdf);
void		ft_key_projection_and_height(int keycode, t_fdf *fdf);
// -------------------------------------------------------------------

// Fonction principale qui appelle les différentes touches pressées.
int	ft_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == NUM_PAD_PLUS || keycode == MAIN_PAD_PLUS
		|| keycode == NUM_PAD_MINUS || keycode == MAIN_PAD_MINUS)
		ft_key_zoom(keycode, fdf);
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_UP || keycode == ARROW_DOWN)
		ft_key_translate(keycode, fdf);
	else if (keycode == NUM_PAD_1 || keycode == MAIN_PAD_1
		|| keycode == NUM_PAD_4 || keycode == MAIN_PAD_2
		|| keycode == NUM_PAD_2 || keycode == MAIN_PAD_3
		|| keycode == NUM_PAD_5 || keycode == MAIN_PAD_4
		|| keycode == NUM_PAD_3 || keycode == MAIN_PAD_5
		|| keycode == NUM_PAD_6 || keycode == MAIN_PAD_6)
		ft_key_rotate(keycode, fdf);
	else if (keycode == KEY_R || keycode == KEY_I
		|| keycode == MAIN_PAD_8 || keycode == NUM_PAD_8
		|| keycode == MAIN_PAD_9 || keycode == NUM_PAD_9)
		ft_key_projection_and_height(keycode, fdf);
	else if (keycode == MAIN_PAD_ESC)
		ft_close_window(fdf);
	return (0);
}

// Gére les touches de ZOOM.
void	ft_key_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == NUM_PAD_PLUS
		|| keycode == MAIN_PAD_PLUS)
		fdf->cam->zoom += 0.1;
	else if (keycode == NUM_PAD_MINUS
		|| keycode == MAIN_PAD_MINUS)
		fdf->cam->zoom -= 0.1;
	if (fdf->cam->zoom <= 0.1)
		fdf->cam->zoom = 0.1;
	if (fdf->cam->zoom >= 15)
		fdf->cam->zoom = 15;
	ft_draw(fdf);
}

// Gére les touches de TRANSLATION.
void	ft_key_translate(int keycode, t_fdf *fdf)
{
	if (keycode == ARROW_LEFT)
		fdf->cam->offset_x += 20;
	else if (keycode == ARROW_RIGHT)
		fdf->cam->offset_x -= 20;
	else if (keycode == ARROW_DOWN)
		fdf->cam->offset_y -= 20;
	else if (keycode == ARROW_UP)
		fdf->cam->offset_y += 20;
	ft_draw(fdf);
}

// Gére les touches de ROTATION.
void	ft_key_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == NUM_PAD_1 || keycode == MAIN_PAD_1)
		fdf->cam->alpha += 0.05;
	else if (keycode == NUM_PAD_4 || keycode == MAIN_PAD_2)
		fdf->cam->alpha -= 0.05;
	else if (keycode == NUM_PAD_2 || keycode == MAIN_PAD_3)
		fdf->cam->beta -= 0.05;
	else if (keycode == NUM_PAD_5 || keycode == MAIN_PAD_4)
		fdf->cam->beta += 0.05;
	else if (keycode == NUM_PAD_3 || keycode == MAIN_PAD_5)
		fdf->cam->gamma += 0.05;
	else if (keycode == NUM_PAD_6 || keycode == MAIN_PAD_6)
		fdf->cam->gamma -= 0.05;
	ft_draw(fdf);
}

// 1. Gére les touches de PROJECTION et de HEIGHT.
// 2. Gére la touche de RESET.
void	ft_key_projection_and_height(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_R)
	{
		ft_fdf_next(fdf);
		return ;
	}
	if (keycode == KEY_I)
	{
		if (fdf->cam->projection == 'i')
			fdf->cam->projection = 'o';
		else
			fdf->cam->projection = 'i';
	}
	else if (keycode == MAIN_PAD_8 || keycode == NUM_PAD_8)
		fdf->cam->height += 1;
	else if (keycode == MAIN_PAD_9 || keycode == NUM_PAD_9)
		fdf->cam->height -= 1;
	if (fdf->cam->height > 30)
		fdf->cam->height = 30;
	if (fdf->cam->height < -30)
		fdf->cam->height = -30;
	ft_draw(fdf);
}
