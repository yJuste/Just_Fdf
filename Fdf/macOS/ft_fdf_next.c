/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_next.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   • Analyse la map.                                               PART 2   */
/* ************************************************************************** */
#include "ft_fdf.h"

// --------------------------------PROTOTYPE------------------------------
int			ft_parse_map(t_fdf *fdf, t_map *map, char **argv);
int			ft_parse_map_next(t_map *map, int fd, char *line);
void		ft_parse_map_next_next(t_map *map, char **out, size_t j);
void		ft_clear_image(t_img *img);
void		ft_free_strs(void **strs);
// -----------------------------------------------------------------------

// analyse la map et met les nombres / les couleurs dans un tableau.
int	ft_parse_map(t_fdf *fdf, t_map *map, char **argv)
{
	int			fd;
	size_t		j;
	char		*line;
	char		*file;

	file = argv[1];
	file = ft_strchr(file, '.', 'r');
	if (!file)
		return (ft_error(fdf, ENOEXEC), exit(3), 0);
	if (ft_strcmp(file, ".fdf") != 0)
		return (ft_error(fdf, ENOEXEC), exit(4), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_error(fdf, EBADF), exit(5), 0);
	line = get_next_line(fd);
	j = ft_parse_map_next(map, fd, line);
	close(fd);
	map->height = j;
	return (0);
}

int	ft_parse_map_next(t_map *map, int fd, char *line)
{
	size_t		j;
	char		**out;

	j = 0;
	while (line)
	{
		out = ft_split(line);
		if (!out)
			break ;
		j++;
		map->map = ft_realloc(map->map, sizeof(int *) * j);
		map->colors = ft_realloc(map->colors, sizeof(int *) * j);
		map->width = ft_strslen((const char **)out);
		map->map[j - 1] = ft_calloc(map->width, sizeof(int));
		map->colors[j - 1] = ft_calloc(map->width, sizeof(int));
		ft_parse_map_next_next(map, out, j);
		ft_free_strs((void **)out);
		free(line);
		line = get_next_line(fd);
	}
	return (j);
}

void	ft_parse_map_next_next(t_map *map, char **out, size_t j)
{
	size_t		i;
	char		*strchr;

	i = 0;
	while (out[i])
	{
		strchr = ft_strchr(out[i], ',', 'c');
		if (strchr)
		{
			*strchr = '\0';
			map->map[j - 1][i] = ft_atoi(out[i]);
			map->colors[j - 1][i] = ft_atoi_base(strchr + 1, 16);
		}
		else
		{
			map->map[j - 1][i] = ft_atoi(out[i]);
			map->colors[j - 1][i] = COLOR;
		}
		i++;
	}
}

// 1. Clear tous les pixels à 0 ( ou une couleur dans mon cas).
// 2. Non je ne destroy pas l'image, je travaille avec la même.
void	ft_clear_image(t_img *img)
{
	int		i;
	int		tot;
	int		color;
	int		*buffer;

	buffer = (int *)img->addr;
	color = BCKGRND_COLOR;
	tot = WIDTH * HEIGHT;
	i = -1;
	while (++i < tot)
		buffer[i] = color;
}

void	ft_free_strs(void **strs)
{
	size_t		i;

	i = 0;
	if (!strs)
		return ;
	while (strs[i])
	{
		free(strs[i]);
		strs[i] = NULL;
		i++;
	}
	free(strs);
	strs = NULL;
}
