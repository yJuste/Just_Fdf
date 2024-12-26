/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cohen_sutherland_clip.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

// -----------------------PROTOTYPE------------------------
void	ft_cohen_sutherland_clip(t_map *map);
int		ft_compute_region_code(int x, int y, int xmin, int xmax, int ymin, int ymax);
// --------------------------------------------------------

// Fonction pour assigner les zones binaires
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

// Algorithme de Cohen SutherLand Clip qui coupe les lignes qui depasse de la fenetre
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
