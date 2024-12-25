/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

// ----------------------------PROTOTYPE---------------------------
void	*ft_calloc(size_t count, size_t size);
void	ft_clear_image(t_img *img);
// ----------------------------------------------------------------

void	*ft_calloc(size_t count, size_t size)
{
	size_t		i;
	size_t		tot;
	void		*ptr;

	i = 0;
	tot = count * size;
	ptr = malloc(tot);
	if (!ptr)
		return (NULL);
	while (i < tot)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

// 1. Clear tous les pixels a 0 ( ou une couleur dans mon cas)
// 2. Non je ne destroy pas l'image, je travaille avec la meme.
void	ft_clear_image(t_img *img)
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
