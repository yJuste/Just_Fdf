/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// --------------------------------PROTOTYPE---------------------------------
int		ft_atoi(char *str);
void	ft_printf_putnbr(t_flags *flags, long nbr);
void	ft_printf_putnbr_uint(t_flags *flags, unsigned int nbr);
void	ft_printf_putnbr_hexa(t_flags *flags, unsigned int nbr, char format);
void	ft_swap_extra(char *a, char *b);
// --------------------------------------------------------------------------

int	ft_atoi(char *str)
{
	int		sign;
	int		res;

	sign = 1;
	res = 0;
	while (*str == ' ' && (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}

void	ft_printf_putnbr(t_flags *flags, long nbr)
{
	char		c;

	if (nbr < 0)
	{
		write(flags->fd, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_printf_putnbr(flags, nbr / 10);
		ft_printf_putnbr(flags, nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(flags->fd, &c, 1);
	}
}

void	ft_printf_putnbr_uint(t_flags *flags, unsigned int nbr)
{
	char		c;

	if (nbr >= 10)
	{
		ft_printf_putnbr_uint(flags, nbr / 10);
		ft_printf_putnbr_uint(flags, nbr % 10);
	}
	else
	{
		c = nbr + '0';
		write(flags->fd, &c, 1);
	}
}

void	ft_printf_putnbr_hexa(t_flags *flags, unsigned int nbr, char format)
{
	const char		*digits;

	if (format == 'x')
		digits = "0123456789abcdef";
	else if (format == 'X')
		digits = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_printf_putnbr_hexa(flags, nbr / 16, format);
		ft_printf_putnbr_hexa(flags, nbr % 16, format);
	}
	else
		write(flags->fd, &digits[nbr], 1);
}

void	ft_swap_extra(char *a, char *b)
{
	char		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
