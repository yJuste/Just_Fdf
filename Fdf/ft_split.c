/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Returns an arr of arr defined by a separator.                          */
/*   • Prototype:   CHAR ** ( char *, char * )                                */
/*        -> malloc, free, size_t                                             */
/* ************************************************************************** */
#include "ft_fdf.h"

// ----------------------------PROTOTYPE---------------------------
char		**ft_split(const char *s);
size_t		ft_count_words(const char *s);
char		**ft_split_next(char **out, const char *s);
char		**ft_split_error(char **out, size_t k);
char		*ft_strncpy(char *dest, const char *src, size_t n);
// ----------------------------------------------------------------

char	**ft_split(const char *s)
{
	size_t		wc;
	char		**out;

	if (!s)
		return (NULL);
	wc = ft_count_words(s);
	out = ft_calloc(wc + 1, sizeof(char *));
	if (!out)
		return (NULL);
	return (ft_split_next(out, s));
}

size_t	ft_count_words(const char *s)
{
	size_t		i;
	size_t		wc;

	i = 0;
	wc = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\n')
			i++;
		if (s[i])
			wc++;
		while (s[i] && (s[i] != ' ' && s[i] != '\n'))
			i++;
	}
	return (wc);
}

char	**ft_split_next(char **out, const char *s)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == ' ' || s[i] == '\n')
			i++;
		if (s[i])
			j = i;
		while (s[i] && (s[i] != ' ' && s[i] != '\n'))
			i++;
		if (i > j)
		{
			out[k] = ft_calloc(i - j + 1, sizeof(char));
			if (!out[k])
				return (ft_split_error(out, k));
			ft_strncpy(out[k++], s + j, i - j);
		}
	}
	out[k] = NULL;
	return (out);
}

char	**ft_split_error(char **out, size_t k)
{
	size_t		f;

	f = 0;
	while (f < k)
	{
		free(out[f]);
		f++;
	}
	free(out);
	return (NULL);
}

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
