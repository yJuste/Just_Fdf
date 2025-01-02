/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -------------------------------PROTOTYPE---------------------------------
void	ft_print_ux(unsigned int u, t_flags *flags, const char **format);
void	ft_calculate_ux( unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_flags_hashtag_ux(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_print_and_null_ux(unsigned int u, t_flags *flags, t_decimal *dml);
// -------------------------------------------------------------------------

void	ft_print_ux(unsigned int u, t_flags *flags, const char **format)
{
	t_decimal	dml;

	ft_dml_init(&dml);
	if (**format == 'x')
		dml.hex = 1;
	else if (**format == 'X')
		dml.hex = 2;
	else
		dml.hex = 0;
	ft_calculate_ux((unsigned int)u, flags, &dml);
	ft_parse_ux((unsigned int)u, flags, &dml);
	(*format)++;
	return ;
}

void	ft_calculate_ux(unsigned int u, t_flags *flags, t_decimal *dml)
{
	if (dml->hex == 1 || dml->hex == 2)
		dml->len = ft_uintlen_hexa(u);
	else
		dml->len = ft_uintlen(u);
	dml->width = ft_atoi(flags->s_width);
	dml->precision = ft_atoi(flags->s_precision);
	if (dml->precision > dml->len)
		dml->precision -= dml->len;
	else
		dml->precision = 0;
	if (flags->star_ds == 1)
		dml->precision = 0;
	dml->spaces = dml->width - (dml->len + dml->precision);
	if (dml->spaces < 0)
		dml->spaces = 0;
	return ;
}

// ---------- Functions utils for print_ux_next ----------

void	ft_flags_hashtag_ux(unsigned int u, t_flags *flags, t_decimal *dml)
{
	if (flags->hashtag)
	{
		if (u != 0)
		{
			if (dml->hex == 1)
				write(flags->fd, "0x", 2);
			else if (dml->hex == 2)
				write(flags->fd, "0X", 2);
			flags->count += 2;
			if (flags->minus)
				dml->spaces -= 2;
		}
	}
	return ;
}

void	ft_print_and_null_ux(unsigned int u, t_flags *flags, t_decimal *dml)
{
	if (!u && flags->precision && !ft_atoi(flags->s_precision))
	{
		if (dml->width)
		{
			write(flags->fd, " ", 1);
			flags->count++;
		}
		flags->count--;
	}
	else
	{
		if (dml->hex == 1)
			ft_printf_putnbr_hexa(flags, u, 'x');
		else if (dml->hex == 2)
			ft_printf_putnbr_hexa(flags, u, 'X');
		else
			ft_printf_putnbr_uint(flags, u);
	}
	return ;
}
