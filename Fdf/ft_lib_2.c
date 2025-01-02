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
#include "ft_fdf.h"

// ---------------------------------PROTOTYPE--------------------------------
int			ft_atoi_base(const char *str, int str_base);
const char	*ft_atoi_base_next(const char *str, int str_base, int *sign);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
void		ft_free_strs(void **strs);
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

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

void	ft_free_strs(void **strs)
{
	size_t		i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
}
