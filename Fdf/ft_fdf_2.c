/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

// ----------------------PROTOTYPE---------------------
void		ft_clear_image(t_fdf *fdf, t_img *img);
// ----------------------------------------------------

// 1. Clear tous les pixels a 0 ( ou une couleur dans mon cas).
// 2. Non je ne destroy pas l'image, je travaille avec la meme.
void	ft_clear_image(t_fdf *fdf, t_img *img)
{
	int		i;
	int		tot;
	int		color;
	int		*buffer;

	buffer = (int *)img->addr;
	color = BCKGRND_COLOR;
	tot = WIDTH * HEIGHT;
	i = -1;
	while (++i < tot)
		buffer[i] = color;
}
