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
#include "ft_fdf.h"

// -----------------------PROTOTYPE------------------------
int		ft_key_hook(int keycode, t_fdf *fdf);
int		ft_zoom(int keycode, t_fdf *fdf);
void	ft_translate(int keycode, t_fdf *fdf);
// --------------------------------------------------------

int	ft_key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == NUM_PAD_PLUS || keycode == MAIN_PAD_PLUS
		|| keycode == MOUSE_SCROLL_UP || keycode == NUM_PAD_MINUS
		|| keycode == MAIN_PAD_MINUS || keycode == MOUSE_SCROLL_DOWN)
		ft_zoom(keycode, fdf);
	else if (keycode == ARROW_LEFT || keycode == ARROW_RIGHT
		|| keycode == ARROW_UP || keycode == ARROW_DOWN)
		ft_translate(keycode, fdf);
	return (0);
}

int	ft_zoom(int keycode, t_fdf *fdf)
{
	if (keycode == NUM_PAD_PLUS ||
		keycode == MAIN_PAD_PLUS ||
		keycode == MOUSE_SCROLL_UP)
		fdf->cam->zoom += 0.1;
	else if (keycode == NUM_PAD_MINUS ||
		keycode == MAIN_PAD_MINUS ||
		keycode == MOUSE_SCROLL_DOWN)
		fdf->cam->zoom -= 0.1;
	if (fdf->cam->zoom <= 0.1)
		fdf->cam->zoom = 0.1;
	ft_draw(fdf);
	return (0);
}

void	ft_translate(int keycode, t_fdf *fdf)
{
	if (keycode == ARROW_LEFT) {
		fdf->cam->offset_x += 20;
	}
	else if (keycode == ARROW_RIGHT) {
		fdf->cam->offset_x -= 20;
	}
	else if (keycode == ARROW_DOWN) {
		fdf->cam->offset_y -= 20;
	}
	else if (keycode == ARROW_UP) {
		fdf->cam->offset_y += 20;
	}
	ft_draw(fdf);
}
