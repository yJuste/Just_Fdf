/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -------------------------------PROTOTYPE------------------------------
void	ft_flags(va_list *args, t_flags *flags, const char **format);
void	ft_flags_args(int arg, t_flags *flags, const char **format);
void	ft_flags_next(t_flags *flags, const char **format, int i, int k);
void	ft_flags_args_next(t_flags *flags, char *format, int i, int k);
void	ft_flags_next_2(t_flags *flags, const char **format, int i);
// ----------------------------------------------------------------------

void	ft_flags(va_list *args, t_flags *flags, const char **format)
{
	if (**format == '0' && !flags->zero)
		ft_flags_next_2(flags, format, 1);
	else if (**format == ' ')
		ft_flags_next_2(flags, format, 2);
	else if (**format == '+')
		ft_flags_next_2(flags, format, 3);
	else if (**format == '-')
		ft_flags_next_2(flags, format, 4);
	else if (**format == '#')
		ft_flags_next_2(flags, format, 5);
	else if (**format >= '0' && **format <= '9')
		ft_flags_next(flags, format, 6, 0);
	else if (**format == '.')
		ft_flags_next(flags, format, 7, 0);
	else if (**format == '*')
		ft_flags_args(va_arg(*args, int), flags, format);
	return ;
}

void	ft_flags_args(int arg, t_flags *flags, const char **format)
{
	int		flg;
	char	nbr[15];

	flg = 0;
	nbr[0] = '\0';
	if (arg < 0)
	{
		arg = -arg;
		flg = 1;
	}
	ft_itoa_stack(arg, nbr);
	if (flags->precision)
	{
		if (flg == 1)
			flags->star_ds = 1;
		ft_flags_args_next(flags, nbr, 7, 0);
	}
	else
	{
		if (flg == 1)
			flags->minus = 1;
		ft_flags_args_next(flags, nbr, 6, 0);
	}
	(*format)++;
	return ;
}

void	ft_flags_next(t_flags *flags, const char **format, int i, int k)
{
	if (i == 6)
	{
		flags->width = 1;
		while (**format >= '0' && **format <= '9')
		{
			flags->s_width[k++] = **format;
			(*format)++;
		}
		flags->s_width[k] = '\0';
		return ;
	}
	if (i == 7)
	{
		flags->precision = 1;
		(*format)++;
		while (**format >= '0' && **format <= '9')
		{
			flags->s_precision[k++] = **format;
			(*format)++;
		}
		flags->s_precision[k] = '\0';
		return ;
	}
	return ;
}

void	ft_flags_args_next(t_flags *flags, char *format, int i, int k)
{
	if (i == 6)
	{
		flags->width = 1;
		while (*format >= '0' && *format <= '9')
		{
			flags->s_width[k++] = *format;
			format++;
		}
		flags->s_width[k] = '\0';
		return ;
	}
	if (i == 7)
	{
		while (*format >= '0' && *format <= '9')
		{
			flags->s_precision[k++] = *format;
			format++;
		}
		flags->s_precision[k] = '\0';
		return ;
	}
	return ;
}

void	ft_flags_next_2(t_flags *flags, const char **format, int i)
{
	if (i == 1)
		flags->zero = 1;
	else if (i == 2)
		flags->space = 1;
	else if (i == 3)
		flags->plus = 1;
	else if (i == 4)
		flags->minus = 1;
	else if (i == 5)
		flags->hashtag = 1;
	(*format)++;
	return ;
}
