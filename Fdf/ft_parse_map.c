/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:                                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created:   by Just'                               #+#    #+#             */
/*   Updated:   by Just'                              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_fdf.h"

// -----------------------PROTOTYPE------------------------
void	ft_parse_map(t_fdf *fdf, char **argv);
void	ft_print_array(int **array, int rows, int cols);
// --------------------------------------------------------

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

// Test your arrays.
void	ft_print_array(int **array, int rows, int cols)
{
	int		i;
	int		j;

	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			ft_printf(1, "%d ", array[i][j]);
			j++;
		}
		ft_printf(1, "\n");
		i++;
	}
}

void	ft_parse_map(t_fdf *fdf, char **argv)
{
	size_t		i;
	int		j;
	int		fd;
	char		*line;
	char		**out;

	j = 0;
	out = NULL;
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		out = ft_split(line);
		j++;
		fdf->map->map = ft_realloc(fdf->map->map, sizeof(int *) * j);
		fdf->map->width = ft_strslen((const char **)out);
		fdf->map->map[j - 1] = ft_calloc(fdf->map->width, sizeof(int));
		i = 0;
		while (out[i])
		{
			fdf->map->map[j - 1][i] = ft_atoi(out[i]);
			i++;
		}
		ft_free_strs((void **)out);
		free(line);
		line = get_next_line(fd);
	}
	fdf->map->height = j;
	ft_printf(1, "w: %d, h: %d\n", fdf->map->width, fdf->map->height);
	if (fdf->map->map)
		ft_print_array(fdf->map->map, fdf->map->height, fdf->map->width);
	// ft_free_strs((void **)fdf->map->map);
	return ;
}
