/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -------------------------------PROTOTYPE------------------------------
void	ft_print_p(void *p, t_flags *flags, const char **format);
void	ft_p_to_hex(unsigned long int ptr, char *hexa);
int		ft_calculate_p(t_flags *flags, int *spaces, int len);
void	ft_parse_p(char *hexa, t_flags *flags, int spaces, int len);
void	ft_no_pointeur(t_flags *flags, const char **format, int *spaces);
// ----------------------------------------------------------------------

void	ft_print_p(void *p, t_flags *flags, const char **format)
{
	int		width;
	int		spaces;
	int		len;
	char	hexa[17];

	len = 0;
	if (!p)
		return (ft_no_pointeur(flags, format, &spaces));
	ft_p_to_hex((unsigned long int)p, hexa);
	len = ft_strlen(hexa) + 2;
	width = ft_calculate_p(flags, &spaces, len);
	ft_parse_p(hexa, flags, spaces, len);
	flags->count += width;
	(*format)++;
	return ;
}

void	ft_p_to_hex(unsigned long int ptr, char *hexa)
{
	int		i;
	int		j;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (ptr == 0)
		hexa[i++] = '0';
	else
	{
		while (ptr > 0)
		{
			hexa[i++] = base[ptr % 16];
			ptr /= 16;
		}
	}
	hexa[i] = '\0';
	j = 0;
	while (j < i / 2)
	{
		ft_swap_extra(&hexa[j], &hexa[i - j - 1]);
		j++;
	}
	return ;
}

int	ft_calculate_p(t_flags *flags, int *spaces, int len)
{
	int		width;

	width = ft_atoi(flags->s_width);
	if (width <= len)
		width = len;
	*spaces = width - len;
	return (width);
}

void	ft_parse_p(char *hexa, t_flags *flags, int spaces, int len)
{
	if (flags->minus)
	{
		write(flags->fd, "0x", 2);
		write(flags->fd, hexa, len - 2);
		while (spaces-- > 0)
			write(flags->fd, " ", 1);
	}
	else
	{
		if (flags->zero)
		{
			while (spaces-- > 0)
				write(flags->fd, "0", 1);
		}
		else
		{
			while (spaces-- > 0)
				write(flags->fd, " ", 1);
		}
		write(flags->fd, "0x", 2);
		write(flags->fd, hexa, len - 2);
	}
	return ;
}

void	ft_no_pointeur(t_flags *flags, const char **format, int *spaces)
{
	int		len;
	int		temp;

	len = 5;
	*spaces = ft_atoi(flags->s_width) - len;
	if (*spaces < 0)
		*spaces = 0;
	temp = *spaces;
	if (!flags->minus)
	{
		while (temp-- > 0)
			write(flags->fd, " ", 1);
	}
	if (!flags->precision)
		write(flags->fd, "(nil)", 5);
	if (flags->minus)
	{
		while (temp-- > 0)
			write(flags->fd, " ", 1);
	}
	flags->count += len + *spaces;
	(*format)++;
	return ;
}
