/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

// -----------------------------------PROTOTYPE--------------------------------
void	ft_print_s(char *s, t_flags *flags, const char **format);
int		ft_calculate_s(char *s, t_flags *flags, int *spaces, int *len);
void	ft_parse_s(char *s, t_flags *flags, int spaces, int len);
// ----------------------------------------------------------------------------

void	ft_print_s(char *s, t_flags *flags, const char **format)
{
	int		width;
	int		spaces;
	int		len;

	if (!s)
		s = "(null)";
	width = ft_calculate_s(s, flags, &spaces, &len);
	ft_parse_s(s, flags, spaces, len);
	flags->count += width;
	(*format)++;
	return ;
}

int	ft_calculate_s(char *s, t_flags *flags, int *spaces, int *len)
{
	int		width;

	if (flags->precision)
		*len = ft_min(ft_strlen(s), ft_atoi(flags->s_precision));
	else
		*len = ft_strlen(s);
	if (flags->star_ds == 1)
		*len = ft_strlen(s);
	width = ft_atoi(flags->s_width);
	if (width <= *len)
		width = *len;
	*spaces = width - *len;
	return (width);
}

void	ft_parse_s(char *s, t_flags *flags, int spaces, int len)
{
	if (flags->minus)
	{
		write(flags->fd, s, len);
		while (spaces-- > 0)
			write(flags->fd, " ", 1);
	}
	else
	{
		while (spaces-- > 0)
			write(flags->fd, " ", 1);
		write(flags->fd, s, len);
	}
	return ;
}
