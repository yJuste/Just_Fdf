/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// ----------------------------------PROTOTYPE----------------------------------
int		ft_printf(int fd, const char *format, ...);
void	ft_printf_arguments(va_list *args, t_flags *flags, const char **format);
void	ft_printf_recall(va_list *args, t_flags *flags, const char **format);
void	ft_print_and_count(t_flags *flags, const char **format);
// -----------------------------------------------------------------------------

int	ft_printf(int fd, const char *format, ...)
{
	t_flags		flags;
	va_list		args;

	flags.count = 0;
	flags.fd = fd;
	va_start(args, format);
	while (*format)
	{
		ft_flags_init(&flags);
		if (*format == '%')
		{
			format++;
			ft_printf_recall(&args, &flags, &format);
			ft_printf_arguments(&args, &flags, &format);
		}
		else
			ft_print_and_count(&flags, &format);
	}
	va_end(args);
	return (flags.count);
}

void	ft_printf_arguments(va_list *args, t_flags *flags, const char **format)
{
	if (**format == '%')
		ft_print_percent(flags, format);
	else if (**format == 'c')
		ft_print_c(va_arg(*args, int), flags, format);
	else if (**format == 's')
		ft_print_s(va_arg(*args, char *), flags, format);
	else if (**format == 'p')
		ft_print_p(va_arg(*args, void *), flags, format);
	else if (**format == 'd' || **format == 'i')
		ft_print_di(va_arg(*args, int), flags, format);
	else if (**format == 'u' || **format == 'x' || **format == 'X')
		ft_print_ux(va_arg(*args, unsigned int), flags, format);
	return ;
}

void	ft_printf_recall(va_list *args, t_flags *flags, const char **format)
{
	int		i;

	i = 0;
	while (i < 10)
	{
		ft_flags(args, flags, format);
		i++;
	}
	return ;
}

void	ft_print_and_count(t_flags *flags, const char **format)
{
	write(flags->fd, *format, 1);
	flags->count++;
	(*format)++;
	return ;
}
