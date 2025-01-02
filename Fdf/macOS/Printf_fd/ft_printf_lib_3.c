/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -----------------PROTOTYPE------------------
void	ft_itoa_stack(int src, char *dest);
void	ft_strdup_stack(char *src, char *dest);
void	ft_flags_init(t_flags *flags);
void	ft_dml_init(t_decimal *dml);
// --------------------------------------------

void	ft_itoa_stack(int src, char *dest)
{
	int	len;

	len = ft_intlen((long)src);
	dest[len] = '\0';
	if (src == -2147483648)
	{
		ft_strdup_stack("-2147483648", dest);
		return ;
	}
	if (src == 0)
	{
		dest[0] = '0';
		dest[1] = '\0';
		return ;
	}
	if (src < 0)
	{
		dest[0] = '-';
		src = -src;
	}
	while (src)
	{
		dest[--len] = src % 10 + '0';
		src /= 10;
	}
}

void	ft_strdup_stack(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	ft_flags_init(t_flags *flags)
{
	size_t		i;

	i = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->space = 0;
	flags->hashtag = 0;
	flags->plus = 0;
	flags->width = 0;
	flags->star_ds = 0;
	while (i < 20)
	{
		flags->s_width[i] = '\0';
		flags->s_precision[i] = '\0';
		i++;
	}
	return ;
}

void	ft_dml_init(t_decimal *dml)
{
	dml->len = 0;
	dml->width = 0;
	dml->spaces = 0;
	dml->precision = 0;
	dml->hex = 0;
	dml->neg = 0;
	dml->zero = 0;
	return ;
}
