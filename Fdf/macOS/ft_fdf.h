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
/*   • Affiche des cartes 2D en projection 3D.                                */
/*   • ./a.out [ file ]                                                       */
/*      -> file   [ .fdf ]                                                    */
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

// My libraries

// minilibX
# include "minilibx_macos/mlx.h"

# include "Get_Next_Line/get_next_line.h"
# include "Printf_fd/ft_printf.h"

// Macros des fct
# include "ft_macros.h"

// Structures

typedef struct s_fdf	t_fdf;
typedef struct s_img	t_img;
typedef struct s_camera	t_camera;
typedef struct s_map	t_map;
typedef struct s_menu	t_menu;
typedef struct s_cohen	t_cohen;

typedef struct s_fdf
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_camera	*cam;
	t_map		*map;
	t_menu		*menu;
	t_cohen		*cohen;
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
	int			color;
	int			**colors;
}	t_map;

// zoom_ix is for optimisation, without it, it lags more.
typedef struct s_camera
{
	int			offset_x;
	int			offset_y;
	int			height;
	int			zoom_ix;
	float		zoom;
	char		projection;
	float		alpha;
	float		beta;
	float		gamma;
}	t_camera;

typedef struct s_menu
{
	void		*rotation;
	void		*translation;
	void		*zoom;
	void		*projection_height;
}	t_menu;

typedef struct s_cohen
{
	int			xmin;
	int			xmax;
	int			ymin;
	int			ymax;
	int			code_out;
	int			x;
	int			y;
}	t_cohen;

//	---------- MY CODE ----------

// ft_fdf.c

int			ft_close_window(int keycode, t_fdf *fdf);
void		ft_init(t_fdf **fdf);
void		ft_error(t_fdf *fdf, int error);
void		ft_free_fdf(t_fdf *fdf);

// ft_fdf_next.c

int			ft_parse_map(t_fdf *fdf, t_map *map, char **argv);
int			ft_parse_map_next(t_map *map, int fd, char *line);
void		ft_parse_map_next_next(t_map *map, char **out, size_t j);
void		ft_clear_image(t_img *img);
void		ft_free_strs(void **strs);

// ft_fdf_2.c

void		ft_fdf(t_fdf *fdf, t_img *img);
void		ft_fdf_next(t_fdf *fdf);
void		ft_draw(t_fdf *fdf);
void		ft_draw_next(t_fdf *fdf, t_map *map);
void		ft_draw_lines(t_fdf *fdf, t_map *map, int dx, int dy);

// ft_cam_movements.c

void		ft_translate(t_camera *cam, int *x, int *y);
void		ft_zoom(t_camera *cam, int *x, int *y, int *z);
void		ft_rotate_x(int *y, int *z, float angle);
void		ft_rotate_y(int *x, int *z, float angle);
void		ft_rotate_z(int *x, int *y, float angle);

// ft_menu.c

void		ft_menu(t_fdf *fdf);
void		ft_menu_next(t_fdf *fdf);
void		ft_background_menu(t_fdf *fdf);
void		ft_default_dimensions(t_fdf *fdf);
void		ft_projection(t_map *map, char projection);

// ft_menu_next.c

void		ft_put_image_translation(t_fdf *fdf);
void		ft_put_image_rotation(t_fdf *fdf);
void		ft_put_image_zoom(t_fdf *fdf);
void		ft_put_image_projection_and_height(t_fdf *fdf);
void		ft_header(t_fdf *fdf);

// ft_macros.c

int			ft_key_hook(int keycode, t_fdf *fdf);
void		ft_key_zoom(int keycode, t_fdf *fdf);
void		ft_key_translate(int keycode, t_fdf *fdf);
void		ft_key_rotate(int keycode, t_fdf *fdf);
void		ft_key_projection_and_height(int keycode, t_fdf *fdf);

// ft_lib.c

void		*ft_calloc(size_t count, size_t size);
void		*ft_realloc(void *ptr, size_t size);
void		*ft_memcpy(void *dst, const void *src, size_t n);
size_t		ft_strslen(const char **s);
int			ft_is_separator(char c, const char *sep);

// ft_lib_2.c

int			ft_atoi_base(const char *str, int str_base);
const char	*ft_atoi_base_next(const char *str, int str_base, int *sign);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c, char flg);
int			ft_strcmp(const char *s1, const char *s2);

// ft_bresenham.c

void		ft_bresenham_line(t_fdf *fdf, t_map *map);
void		ft_bresenham_line_next(t_fdf *fdf, t_map *map, int sx, int sy);
void		ft_pixel_put(t_img *img, int x, int y, int color);
int			ft_color(t_img *img);

// ft_cohen_sutherland_clip.c

void		ft_cohen_sutherland_clip(t_map *map, t_cohen *cohen);
void		ft_cohen_sutherland_clip_next(t_map *map, t_cohen *cohen,
				int *code0, int *code1);
void		ft_cohen_sutherland_clip_next_next(t_map *map, t_cohen *cohen,
				int *code0, int *code1);
int			ft_compute_region_code(t_cohen *cohen, int x);

// ft_split.c

char		**ft_split(const char *s);
size_t		ft_count_words(const char *s);
char		**ft_split_next(char **out, const char *s);
char		**ft_split_error(char **out, size_t k);
char		*ft_strncpy(char *dest, const char *src, size_t n);

// get_next_line.c

char		*get_next_line(int fd);
int			ft_read_buffer(t_buf *buf, int fd);
char		*ft_strdup(const char *s1);

#endif
