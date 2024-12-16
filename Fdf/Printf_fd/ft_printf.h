/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Standard Libraries

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

// Structure

typedef struct s_flags
{
	int		width;
	int		space;
	int		plus;
	int		minus;
	int		hashtag;
	int		zero;
	int		precision;
	char	s_width[20];
	char	s_precision[20];
	int		count;
	int		star_ds;
	int		fd;
}	t_flags;

typedef struct s_decimal
{
	int		len;
	int		width;
	int		spaces;
	int		precision;
	int		hex;
	int		neg;
	int		zero;
}	t_decimal;

//	---------- MY CODE ----------

// ft_printf.c

int		ft_printf(int fd, const char *format, ...);
void	ft_printf_arguments(va_list *args, t_flags *flags, const char **format);
void	ft_printf_recall(va_list *args, t_flags *flags, const char **format);
void	ft_print_and_count(t_flags *flags, const char **format);

// ft_printf_2.c

void	ft_flags(va_list *args, t_flags *flags, const char **format);
void	ft_flags_args(int arg, t_flags *flags, const char **format);
void	ft_flags_next(t_flags *flags, const char **format, int i, int k);
void	ft_flags_args_next(t_flags *flags, char *format, int i, int k);
void	ft_flags_next_2(t_flags *flags, const char **format, int i);

// ft_print_percent.c

void	ft_print_percent(t_flags *flags, const char **format);
void	ft_parse_percent(t_flags *flags, int spaces);

// ft_print_c.c

void	ft_print_c(int c, t_flags *flags, const char **format);
void	ft_parse_c(int c, t_flags *flags, int spaces);

// ft_print_s.c

void	ft_print_s(char *s, t_flags *flags, const char **format);
int		ft_calculate_s(char *s, t_flags *flags, int *spaces, int *len);
void	ft_parse_s(char *s, t_flags *flags, int spaces, int len);

// ft_print_p.c

void	ft_print_p(void *p, t_flags *flags, const char **format);
void	ft_p_to_hex(unsigned long int ptr, char *hexa);
int		ft_calculate_p(t_flags *flags, int *spaces, int len);
void	ft_parse_p(char *hexa, t_flags *flags, int spaces, int len);
void	ft_no_pointeur(t_flags *flags, const char **format, int *spaces);

// ft_print_di.c

void	ft_print_di(int d, t_flags *flags, const char **format);
void	ft_calculate_di(long d, t_flags *flags, t_decimal *dml);
void	ft_print_and_null_di(long d, t_flags *flags, t_decimal *dml);
void	ft_neg_space_plus_di(long *d, t_flags *flags, t_decimal *dml);
void	ft_special_case_di(long *d, t_flags *flags, t_decimal *dml);

// ft_print_di_next.c

void	ft_parse_di(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_minus_di(long d, t_flags *flags, t_decimal *dml);
void	ft_parse_next_di(long d, t_flags *flags, t_decimal *dml);
void	ft_flags_next_zero_di(long *d, t_flags *flags, t_decimal *dml);
void	ft_parse_next_2_di(long *d, t_flags *flags, t_decimal *dml);

// ft_print_u.c

void	ft_print_ux(unsigned int u, t_flags *flags, const char **format);
void	ft_calculate_ux( unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_flags_hashtag_ux(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_print_and_null_ux(unsigned int u, t_flags *flags, t_decimal *dml);

// ft_print_u_next.c

void	ft_parse_ux(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_flags_minus_ux(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_parse_next_ux(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_flags_next_zero_ux(unsigned int u, t_flags *flags, t_decimal *dml);
void	ft_parse_next_2_ux(unsigned int u, t_flags *flags, t_decimal *dml);

// ft_printf_lib.c

int		ft_intlen(long n);
int		ft_uintlen(unsigned int n);
int		ft_uintlen_hexa(unsigned int n);
size_t	ft_strlen(const char *s);
int		ft_min(int a, int b);

// ft_printf_lib_2.c

int		ft_atoi(char *str);
void	ft_printf_putnbr(t_flags *flags, long nbr);
void	ft_printf_putnbr_uint(t_flags *flags, unsigned int nbr);
void	ft_printf_putnbr_hexa(t_flags *flags, unsigned int nbr, char format);
void	ft_swap_extra(char *a, char *b);

// ft_printf_lib_3.c

void	ft_itoa_stack(int src, char *dest);
void	ft_strdup_stack(char *src, char *dest);
void	ft_flags_init(t_flags *flags);
void	ft_dml_init(t_decimal *dml);

#endif
