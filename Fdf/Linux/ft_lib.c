/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated: 2025/01/04 01:55:04 by jlongin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • First Lib.                                                             */
/* ************************************************************************** */
#include "ft_fdf.h"

// ---------------------------PROTOTYPE---------------------------
void		*ft_calloc(size_t count, size_t size);
void		*ft_realloc(void *ptr, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strslen(const char **s);
int			ft_strcmp(const char *s1, const char *s2);
// ---------------------------------------------------------------

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

void	*ft_realloc(void *ptr, size_t size)
{
	void		*nptr;

	if (!ptr)
		return (ft_calloc(1, size));
	if (!size)
		return (free(ptr), NULL);
	nptr = ft_calloc(1, size);
	if (!nptr)
		return (NULL);
	ft_memcpy(nptr, ptr, size);
	free(ptr);
	return (nptr);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

size_t	ft_strslen(const char **s)
{
	size_t		i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
