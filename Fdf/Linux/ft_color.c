/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Ajoute les presets de couleur.                                         */
/* ************************************************************************** */
#include "ft_fdf.h"

// -----------------------------------PROTOTYPE--------------------------------
int			ft_scale(int n, int new_min, int new_max, int old_max);
int			ft_gradient(int iteration, int max);
int			ft_gradientbw(int iteration, int max);
// ----------------------------------------------------------------------------

// Scale des nombres.
int	ft_scale(int n, int new_min, int new_max, int old_max)
{
	if (old_max == 0 && new_min == 0)
		return (new_min);
	return ((new_max - new_min) * (n - 0) / (old_max - 0) + new_min);
}

// Applique un gradient de couleur.
int	ft_gradient(int iteration, int max)
{
	int		red;
	int		green;
	int		blue;

	if (iteration < max / 3)
	{
		red = 255;
		green = ft_scale(iteration, 0, 255, max / 3);
		blue = 0;
	}
	else if (iteration < 2 * max / 3)
	{
		red = ft_scale(iteration - max / 3, 255, 0, max / 3);
		green = 125;
		blue = ft_scale(iteration - max / 3, 0, 255, max / 3);
	}
	else
	{
		red = 0;
		green = ft_scale(iteration - 2 * max / 3, 255, 0, max / 3);
		blue = 255;
	}
	return (red << 16 | green << 8 | blue);
}

// Applique un gradient de couleur entre le noir et le blanc.
int	ft_gradientbw(int iteration, int max)
{
	int		intensity;

	intensity = ft_scale(iteration, 255, 0, max);
	return (intensity << 16 | intensity << 8 | intensity);
}
