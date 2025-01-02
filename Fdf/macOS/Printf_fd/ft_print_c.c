/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -------------------------PROTOTYPE--------------------------
void	ft_print_c(int c, t_flags *flags, const char **format);
void	ft_parse_c(int c, t_flags *flags, int spaces);
// ------------------------------------------------------------

void	ft_print_c(int c, t_flags *flags, const char **format)
{
	int		width;
	int		spaces;

	width = ft_atoi(flags->s_width);
	if (width <= 1)
		width = 1;
	spaces = width - 1;
	ft_parse_c(c, flags, spaces);
	flags->count += width;
	(*format)++;
	return ;
}

void	ft_parse_c(int c, t_flags *flags, int spaces)
{
	if (flags->minus)
	{
		write(flags->fd, &c, 1);
		while (spaces-- > 0)
			write(flags->fd, " ", 1);
	}
	else
	{
		while (spaces-- > 0)
		{
			if (flags->zero)
				write(flags->fd, "0", 1);
			else
				write(flags->fd, " ", 1);
		}
		write(flags->fd, &c, 1);
	}
	return ;
}
