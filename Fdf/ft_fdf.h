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

// open
# include <fcntl.h>

# include <math.h>

// My library

// minilibX
# include "minilibx/mlx.h"

# include "Get_Next_Line/get_next_line.h"
# include "Printf_fd/ft_printf.h"

// Macros des fct
# include "ft_macros.h"

// Structure

typedef struct s_img	t_img;
typedef struct s_camera	t_camera;
typedef struct s_map	t_map;
typedef struct s_menu	t_menu;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_img			*img;
	t_camera		*cam;
	t_map			*map;
	t_menu			*menu;
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
	int			wid;
	int			hei;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	int			z0;
	int			z1;
	int			**map;
}	t_map;

// zoom_ix is for optimisation, without it, it lags more.
typedef struct s_camera
{
	float		zoom;
	int		zoom_ix;
	int		offset_x;
	int		offset_y;
	float		angle;
	// float		altitude;
	// int		depth_factor;
}	t_camera;

typedef struct s_menu
{
	int		x;
	int		y;
}	t_menu;

//	---------- MY CODE ----------

// ft_fdf.c

void		ft_error(t_fdf *fdf, int error);
void		ft_init(t_fdf **fdf);

// ft_fdf_next.c

void		ft_fdf(t_fdf *fdf, t_img *img);
void		ft_fdf_next(t_fdf *fdf, t_img *img);
void		ft_draw(t_fdf *fdf);
void		ft_draw_horizontal(t_fdf *fdf, t_map *map);
void		ft_draw_vertical(t_fdf *fdf, t_map *map);

// ft_fdf_2.c

void		ft_clear_image(t_fdf *fdf, t_img *img);

// ft_parse_map.c

void		ft_parse_map(t_fdf *fdf, char **argv);

// ft_cam_movements.c

void		ft_default_dimensions(t_fdf *fdf);
void		ft_projection(t_map *map, float *angle);
void		ft_translate(t_camera *cam, int *x, int *y);
void		ft_zoom(t_fdf *fdf, t_map *map);

// ft_macros.c

int		ft_key_hook(int keycode, t_fdf *fdf);
int		ft_key_zoom(int keycode, t_fdf *fdf);
int		ft_key_translate(int keycode, t_fdf *fdf);

// ft_menu.c

void		ft_menu(t_fdf *fdf);
void		ft_menu_next(t_fdf *fdf);
void		ft_background_menu(t_fdf *fdf);
void		ft_header(t_fdf *fdf);

// ft_bresenham.c

int		ft_color(t_img *img);
void	ft_pixel_put(t_img *img, int x, int y, int color);
void	ft_bresenham_line(t_fdf *fdf, t_map *map);
void	ft_bresenham_line_next(t_fdf *fdf, t_map *map, int sx, int sy);

// ft_cohen_sutherland_clip.c

void		ft_cohen_sutherland_clip(t_map *map);
int			ft_compute_region_code(int x, int y, int xmin, int xmax, int ymin, int ymax);

// ft_lib.c

void	*ft_calloc(size_t count, size_t size);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strslen(const char **s);
int	ft_is_separator(char c, const char *sep);

// ft_split.c

char		**ft_split(const char *s);
size_t		ft_count_words(const char *s);
char		**ft_split_next(char **out, const char *s);
char		**ft_split_error(char **out, size_t k);
char		*ft_strncpy(char *dest, const char *src, size_t n);

char	**ft_split_sep(char *str, char *charseti);
char	*ft_strdup_sep_split(char *src, int start, int end);
int	ft_is_sep_split(char c, char *charset);

// get_next_line.c

char		*get_next_line(int fd);
int			ft_read_buffer(t_buf *buf, int fd);
char		*ft_strdup(const char *s1);

#endif
