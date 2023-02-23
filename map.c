/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/02/23 23:45:56 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO cleanup this files a mess
// TODO remove scale from load points
// ! optimize this function

static void	*size_of_map(char *map_path, t_map *map);
static void load_points(t_map *map, t_point *points, char *map_path); // just give it map du
static void get_color(int *color, char *line, int *j);
static int	get_number(char *line, int *j);
void apply_zoom(t_map *map, int zoom);

t_map	*load_map(char *map_path, t_view_controls *vc)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	mem_check(map);
	size_of_map(map_path, map);
	map->size = map->dim[MWIDTH] * map->dim[MHEIGHT];
	map->p = malloc(sizeof(t_point) * map->size);
	mem_check(map->p);
	load_points(map, map->p, map_path);
	apply_zoom(map, vc->zoom);
	project_iso(map, map->p, map->size);
	return map;
}

static void	*size_of_map(char *map_path, t_map *map)
{
	int		i;
	int		map_fd;
	char	*line;

	map_fd = open(map_path, O_RDONLY);
	open_check(map_fd);
	map->size = 0;
	map->dim[MHEIGHT] = 0;
	line = get_next_line(map_fd);
	while (line && *line)
	{
		i = 0;
		while (line[i])
		{
			if (is_number(line[i]))
			{
				map->size++;
				while (is_number(line[i]) || is_hex(line[i]))
					i++;
			}
			i++;
		}
		free(line);
		map->dim[MHEIGHT]++;
		line = get_next_line(map_fd);
	}
	empty_check(map->dim[MHEIGHT], map);
	map->dim[MWIDTH] = map->size / map->dim[MHEIGHT];
	free(line);
	close(map_fd);
	return (map->dim);
}

static void load_points(t_map *map, t_point *points, char *map_path)
{
	char *line;
	int j;
	int i;
	int row_number;
	int col_number;
	int map_fd;

	map_fd = open(map_path, O_RDONLY);
	line = get_next_line(map_fd);
	i = 0;
	row_number = 0;
	map->max_height = 0;
	while(line && *line)
	{
		j = 0;
		col_number = 0;
		while (line[j] && i < map->size)
		{
			points[i].p_3dv[z] = 0;
			if (is_number(line[j]))
			{
				points[i].p_3dv[y] = row_number;
				points[i].p_3dv[x] = col_number;
				col_number++;
				points[i].p_3dv[z] = get_number(line, &j);
				if (line[j] == ',')
				{
					j += 3;
					get_color(&points[i].color, line, &j); // skip ,0x
				}
				else
					points[i].color = WHITE_PIXEL;
				if (points[i].p_3dv[z] > map->max_height)
					map->max_height = points[i].p_3dv[z];
				i++;
			}
			j++;
		}
		free(line);
		line = get_next_line(map_fd);
		row_number++;
	}
	free(line);
	close(map_fd);
}

static int	get_number(char *line, int *j)
{
	int	z;
	int sign;

	z = 0;
	sign = 1;
	if ((*j) >= 1 && line[(*j) - 1] == '-')
		sign = -1;
	while (is_number(line[*j]))
	{
		z *= 10;
		z += line[*j] - '0';
		(*j)++;
	}
	return (sign * z);
}

static void get_color(int *color, char *line, int *j)
{
	int		i;
	char	*hex_u;
	char	*hex_l;

	*color = 0;
	hex_u = "0123456789ABCDEF";
	hex_l = "0123456789abcdef";
	while (line[*j + 1] && line[*j] != ' ')
	{
		i = 0;
		while (hex_u[i] != line[*j] && hex_l[i] != line[*j])
			i++;
		*color *= 10;
		*color += i;
		(*j)++;
	}
}

// * Apply zoom
void apply_zoom(t_map *map, int zoom)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->p[i].p_3dv[x] *= zoom;
		map->p[i].p_3dv[y] *= zoom;
		i++;
	}
}
