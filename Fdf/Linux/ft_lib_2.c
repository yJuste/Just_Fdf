/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Second Lib.                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

// ---------------------------------PROTOTYPE--------------------------------
int			ft_atoi_base(const char *str, int str_base);
const char	*ft_atoi_base_next(const char *str, int str_base, int *sign);
char		*ft_strchr(const char *s, int c, char flg);
int			ft_is_separator(char c, const char *sep);
int			ft_tolower(int c);
// --------------------------------------------------------------------------

int	ft_atoi_base(const char *str, int str_base)
{
	int		c;
	int		digit;
	int		sign;
	int		res;

	res = 0;
	sign = 1;
	str = ft_atoi_base_next(str, str_base, &sign);
	if (!str)
		return (0);
	while (*str)
	{
		c = ft_tolower(*str);
		if (c >= '0' && c <= '9')
			digit = c - '0';
		else if (c >= 'a' && c <= 'f')
			digit = 10 + (c - 'a');
		else
			return (0);
		if (digit >= str_base)
			return (0);
		res = res * str_base + digit;
		str++;
	}
	return (sign * res);
}

const char	*ft_atoi_base_next(const char *str, int str_base, int *sign)
{
	*sign = 1;
	if (!str || str_base < 2 || str_base > 16)
		return (NULL);
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		*sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	if (str_base == 16 && *str == '0'
		&& (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str += 2;
	return (str);
}

char	*ft_strchr(const char *s, int c, char flg)
{
	size_t		i;

	i = 0;
	if (flg == 'c')
	{
		while (s[i])
		{
			if (s[i] == (char)c)
				return ((char *)(s + i));
			i++;
		}
		if (s[i] == (char)c)
			return ((char *)(s + i));
	}
	else
	{
		i = ft_strlen(s);
		while (s[i] != (char)c && i > 0)
			i--;
		if (s[i] == (char) c)
			return ((char *)s + i);
	}
	return (NULL);
}

int	ft_is_separator(char c, const char *sep)
{
	while (*sep)
	{
		if (c == *sep)
			return (1);
		sep++;
	}
	return (0);
}

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
