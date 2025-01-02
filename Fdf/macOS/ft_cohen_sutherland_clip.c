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

// ---------------------------------PROTOTYPE---------------------------------
void		ft_cohen_sutherland_clip(t_map *map, t_cohen *cohen);
void		ft_cohen_sutherland_clip_next(t_map *map, t_cohen *cohen,
				int *code0, int *code1);
void		ft_cohen_sutherland_clip_next_next(t_map *map, t_cohen *cohen,
				int *code0, int *code1);
int			ft_compute_region_code(t_cohen *cohen, int x);
// ---------------------------------------------------------------------------

// Algorithme de Cohen SutherLand Clip qui coupe les lignes
//   qui depasse de la fenetre.
void	ft_cohen_sutherland_clip(t_map *map, t_cohen *cohen)
{
	int		code0;
	int		code1;

	code0 = ft_compute_region_code(cohen, map->x0);
	code1 = ft_compute_region_code(cohen, map->x1);
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
			ft_cohen_sutherland_clip_next(map, cohen, &code0, &code1);
	}
	return ;
}

void	ft_cohen_sutherland_clip_next(t_map *map, t_cohen *cohen,
		int *code0, int *code1)
{
	if (*code0 != 0)
		cohen->code_out = *code0;
	else
		cohen->code_out = *code1;
	if (cohen->code_out & LEFT)
	{
		cohen->x = cohen->xmin;
		cohen->y = map->y0 + (map->y1 - map->y0)
			* (cohen->xmin - map->x0) / (map->x1 - map->x0);
	}
	else if (cohen->code_out & RIGHT)
	{
		cohen->x = cohen->xmax;
		cohen->y = map->y0 + (map->y1 - map->y0)
			* (cohen->xmax - map->x0) / (map->x1 - map->x0);
	}
	ft_cohen_sutherland_clip_next_next(map, cohen, code0, code1);
}

void	ft_cohen_sutherland_clip_next_next(t_map *map, t_cohen *cohen,
		int *code0, int *code1)
{
	if (cohen->code_out == *code0)
	{
		map->x0 = cohen->x;
		map->y0 = cohen->y;
		*code0 = ft_compute_region_code(cohen, map->x0);
	}
	else
	{
		map->x1 = cohen->x;
		map->y1 = cohen->y;
		*code1 = ft_compute_region_code(cohen, map->x1);
	}
	return ;
}

// Fonction pour assigner les zones binaires.
int	ft_compute_region_code(t_cohen *cohen, int x)
{
	int		code;

	code = 0;
	if (x < cohen->xmin)
		code |= LEFT;
	else if (x > cohen->xmax)
		code |= RIGHT;
	return (code);
}
