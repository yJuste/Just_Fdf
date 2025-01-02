/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_di_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -----------------------------PROTOTYPE-----------------------------
void	ft_parse_di(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_minus_di(long d, t_flags *flags, t_decimal *dml);
void	ft_parse_next_di(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_next_zero_di(long *d, t_flags *flags, t_decimal *dml);
void	ft_parse_next_2_di(long *d, t_flags *flags, t_decimal *dml);
// -------------------------------------------------------------------

void	ft_parse_di(long d, t_flags *flags, t_decimal *dml)
{
	if (flags->minus)
		ft_flags_minus_di(d, flags, dml);
	else
		ft_parse_next_di(d, flags, dml);
	return ;
}

void	ft_flags_minus_di(long d, t_flags *flags, t_decimal *dml)
{
	ft_neg_space_plus_di(&d, flags, dml);
	while (dml->precision-- > 0)
	{
		write(flags->fd, "0", 1);
		flags->count++;
	}
	ft_print_and_null_di(d, flags, dml);
	flags->count += ft_intlen(d);
	if (flags->plus || flags->space)
		dml->spaces += 1;
	while (dml->spaces-- > 0)
	{
		write(flags->fd, " ", 1);
		flags->count++;
	}
	return ;
}

void	ft_parse_next_di(long d, t_flags *flags, t_decimal *dml)
{
	if (flags->zero)
		ft_flags_next_zero_di(&d, flags, dml);
	else
		ft_parse_next_2_di(&d, flags, dml);
	while (dml->precision-- > 0)
	{
		write(flags->fd, "0", 1);
		flags->count++;
	}
	ft_print_and_null_di(d, flags, dml);
	flags->count += ft_intlen(d);
	return ;
}

void	ft_flags_next_zero_di(long *d, t_flags *flags, t_decimal *dml)
{
	if (!flags->precision || flags->star_ds == 1)
		ft_neg_space_plus_di(d, flags, dml);
	ft_special_case_di(d, flags, dml);
	if (flags->plus == 1 || flags->space == 1)
	{
		if (!flags->precision)
			dml->spaces++;
		if (*d <= 0 && flags->precision && ft_atoi(flags->s_width) > 1
			&& !ft_atoi(flags->s_precision))
			dml->spaces++;
	}
	while (dml->spaces-- > 0)
	{
		if (flags->precision && !flags->star_ds)
			write(flags->fd, " ", 1);
		else
			write(flags->fd, "0", 1);
		flags->count++;
	}
	if (flags->precision && !flags->star_ds)
		ft_neg_space_plus_di(d, flags, dml);
	return ;
}

void	ft_parse_next_2_di(long *d, t_flags *flags, t_decimal *dml)
{
	if (*d < 0 && !flags->plus && !flags->space)
		dml->spaces--;
	while (dml->spaces-- > 0)
	{
		write(flags->fd, " ", 1);
		flags->count++;
	}
	if (*d == 0 && flags->width > 0)
	{
		if (flags->precision == 1 && ft_atoi(flags->s_precision) == 0)
		{
			if (ft_atoi(flags->s_width) != 1)
			{
				write(flags->fd, " ", 1);
				flags->count++;
				dml->zero = 1;
			}
		}
	}
	ft_neg_space_plus_di(d, flags, dml);
	return ;
}
