/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -----------------------------PROTOTYPE----------------------------
void	ft_print_di(int d, t_flags *flags, const char **format);
void	ft_calculate_di(long d, t_flags *flags, t_decimal *dml);
void	ft_print_and_null_di(long d, t_flags *flags, t_decimal *dml);
void	ft_neg_space_plus_di(long *d, t_flags *flags, t_decimal *dml);
void	ft_special_case_di(long *d, t_flags *flags, t_decimal *dml);
// ------------------------------------------------------------------

void	ft_print_di(int d, t_flags *flags, const char **format)
{
	t_decimal	dml;

	ft_dml_init(&dml);
	ft_calculate_di((long)d, flags, &dml);
	ft_parse_di((long)d, flags, &dml);
	(*format)++;
	return ;
}

void	ft_calculate_di(long d, t_flags *flags, t_decimal *dml)
{
	dml->len = ft_intlen(d);
	if (d < 0)
		dml->len--;
	dml->width = ft_atoi(flags->s_width);
	if (flags->plus || flags->space)
		dml->width -= 1;
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

// ---------- Functions utils for print_di_next ----------

void	ft_print_and_null_di(long d, t_flags *flags, t_decimal *dml)
{
	if (!d && flags->precision && !ft_atoi(flags->s_precision))
	{
		if (dml->width > 0)
		{
			if (flags->zero && (flags->plus > 0 || flags->space > 0))
				write(flags->fd, "", 1);
			else if (!dml->zero)
			{
				write(flags->fd, " ", 1);
				flags->count++;
			}
		}
		flags->count--;
	}
	else
		ft_printf_putnbr(flags, (long)d);
	return ;
}

void	ft_neg_space_plus_di(long *d, t_flags *flags, t_decimal *dml)
{
	if (*d < 0)
	{
		*d = -*d;
		write(flags->fd, "-", 1);
		flags->count++;
		dml->spaces--;
		dml->neg = 1;
	}
	if (flags->space || flags->plus)
	{
		if (dml->neg == 0)
		{
			if (flags->plus)
				write(flags->fd, "+", 1);
			else
				write(flags->fd, " ", 1);
			flags->count++;
			dml->spaces--;
		}
	}
	return ;
}

void	ft_special_case_di(long *d, t_flags *flags, t_decimal *dml)
{
	if (flags->precision && ft_atoi(flags->s_precision) && *d < 0
		&& ft_atoi(flags->s_width) < ft_atoi(flags->s_precision))
		dml->spaces--;
	if (!ft_atoi(flags->s_precision))
	{
		if (flags->precision && *d < 0
			&& ft_atoi(flags->s_width) < ft_atoi(flags->s_precision))
			dml->spaces--;
	}
	if (*d < 0 && !flags->plus && !flags->space)
		dml->spaces--;
	if (flags->precision
		&& *d < 0
		&& ft_atoi(flags->s_width) > ft_atoi(flags->s_precision)
		&& (flags->plus || flags->space)
		&& !ft_atoi(flags->s_precision))
		dml->spaces--;
	return ;
}
