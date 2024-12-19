/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_FDF_H
# define FT_FDF_H

// Standard Libraries

# include <unistd.h>
# include <stdlib.h>

// My library

// minilibX
# include "minilibx/mlx.h"

# include "Get_Next_Line/get_next_line.h"
# include "Printf_fd/ft_printf.h"

// Macros

// Default Mac Air M2: 1470 x 956
// 	Large resolution: 1710 x 1112
# define HEIGHT 700
# define WIDTH 500

// Structure

typedef struct s_coord	t_coord;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	int			px_bit;
	int			ln_bit;
	int			endian;
	t_coord		*c;
}	t_fdf;

typedef struct s_coord
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}	t_coord;

//	---------- MY CODE ----------

// ft_fdf.c

// ft_fdf_next.c

// ft_bresenham.c

void		ft_bresenham_line(t_fdf *fdf);
void		ft_bresenham_line_next(t_fdf *fdf, int sx, int sy, int err);

// ft_lib.c

void		*ft_calloc(size_t count, size_t size);

// ft_split.c

char		**ft_split(const char *s, char c);
size_t		ft_count_words(const char *s, char c);
char		**ft_split_next(char **out, const char *s, char c);
char		**ft_split_error(char **out, size_t k);
char		*ft_strncpy(char *dest, const char *src, size_t n);

// get_next_line.c

char		*get_next_line(int fd);
int			ft_read_buffer(t_buf *buf, int fd);
char		*ft_strdup(const char *s1);

#endif
