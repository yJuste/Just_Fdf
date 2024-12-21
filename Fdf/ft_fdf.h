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

// strerror, errno
# include <string.h>
# include <errno.h>

# include <math.h>

// My library

// minilibX
# include "minilibx/mlx.h"

# include "Get_Next_Line/get_next_line.h"
# include "Printf_fd/ft_printf.h"

// Macros

// Default Mac Air M2: 1470 x 956
// 	Large resolution: 1710 x 1112
# define WIDTH 900
# define HEIGHT 500

// Structure

typedef struct s_img	t_img;
typedef struct s_camera	t_camera;
typedef struct s_map	t_map;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_img			*img;
	t_camera		*cam;
	t_map			*map;
}	t_fdf;

typedef struct s_img
{
	void		*ptr;
	char		*addr;
	int			bpp;
	int			size;
	int			endian;
	int			red;
	int			green;
	int			blue;
}	t_img;

typedef struct s_map
{
	int			width;
	int			height;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			z0;
	int			z1;
}	t_map;

typedef struct s_camera
{
	float		zoom;
}	t_camera;

//	---------- MY CODE ----------

// ft_fdf.c

void		ft_fdf(t_fdf *fdf, t_img *img);
void		ft_fdf_next(t_fdf *fdf, t_img *img);

// ft_fdf_next.c

void		ft_fdf(t_fdf *fdf, t_img *img);
void		ft_fdf_next(t_fdf *fdf, t_img *img);
void		ft_draw(t_fdf *fdf);
void		ft_isometric(int *x, int *y, int *z);
void		ft_draw_horizontal(t_fdf *fdf, t_map *map);

// ft_bresenham.c

int		ft_color(t_img *img);
void	ft_pixel_put(t_img *img, int x, int y, int color);
void	ft_bresenham_line(t_fdf *fdf, t_map *map);
void	ft_bresenham_line_next(t_fdf *fdf, t_map *map, int sx, int sy);

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
