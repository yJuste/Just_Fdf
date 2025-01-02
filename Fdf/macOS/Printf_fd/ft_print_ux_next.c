/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ux_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// --------------------------------PROTOTYPE---------------------------------
void	ft_parse_ux(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_flags_minus_ux(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_parse_next_ux(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_flags_next_zero_ux(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_parse_next_2_ux(unsigned int u, t_flags *flags, t_decimal *dml);
// --------------------------------------------------------------------------

void	ft_parse_ux(unsigned int u, t_flags *flags, t_decimal *dml)
{
	if (flags->minus)
		ft_flags_minus_ux(u, flags, dml);
	else
		ft_parse_next_ux(u, flags, dml);
	return ;
}

void	ft_flags_minus_ux(unsigned int u, t_flags *flags, t_decimal *dml)
{
	if (flags->hashtag)
		ft_flags_hashtag_ux(u, flags, dml);
	while (dml->precision-- > 0)
	{
		write(flags->fd, "0", 1);
		flags->count++;
	}
	ft_print_and_null_ux(u, flags, dml);
	if (dml->hex == 1 || dml->hex == 2)
		flags->count += ft_uintlen_hexa(u);
	else
		flags->count += ft_uintlen(u);
	while (dml->spaces-- > 0)
	{
		write(flags->fd, " ", 1);
		flags->count++;
	}
	return ;
}

void	ft_parse_next_ux(unsigned int u, t_flags *flags, t_decimal *dml)
{
	if (flags->zero)
		ft_flags_next_zero_ux(u, flags, dml);
	else
		ft_parse_next_2_ux(u, flags, dml);
	while (dml->precision-- > 0)
	{
		write(flags->fd, "0", 1);
		flags->count++;
	}
	ft_print_and_null_ux(u, flags, dml);
	if (dml->hex == 1 || dml->hex == 2)
		flags->count += ft_uintlen_hexa(u);
	else
		flags->count += ft_uintlen(u);
	return ;
}

void	ft_flags_next_zero_ux(unsigned int u, t_flags *flags, t_decimal *dml)
{
	if (flags->hashtag && (dml->hex == 1 || dml->hex == 2) && u != 0)
		dml->spaces -= 2;
	if (!flags->precision)
		ft_flags_hashtag_ux(u, flags, dml);
	while (dml->spaces-- > 0)
	{
		if (flags->precision && !flags->star_ds)
			write(flags->fd, " ", 1);
		else
			write(flags->fd, "0", 1);
		flags->count++;
	}
	if (flags->precision)
		ft_flags_hashtag_ux(u, flags, dml);
	return ;
}

void	ft_parse_next_2_ux(unsigned int u, t_flags *flags, t_decimal *dml)
{
	if (flags->hashtag && (dml->hex == 1 || dml->hex == 2) && u != 0)
		dml->spaces -= 2;
	while (dml->spaces-- > 0)
	{
		write(flags->fd, " ", 1);
		flags->count++;
	}
	if (flags->hashtag && dml->hex == 0)
		flags->count -= 2;
	if (flags->hashtag)
		ft_flags_hashtag_ux(u, flags, dml);
	return ;
}
