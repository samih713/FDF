/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 03:38:15 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 05:10:52 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// ! optimize this function

enum e_counter
{
	i = 2,
	j
};

static void	set_point(t_point *p, int *c, char *line, int *max_height);
static void	*size_of_map(char *map_path, t_map *map);
static void	load_points(t_map *map, t_point *points, char *map_path);
static void	open_map(int *map_fd, char *map_path);

t_map	*load_map(char *map_path)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	mem_check(map);
	map->max_height = 0;
	map->size = 0;
	map->dim[MHEIGHT] = 0;
	size_of_map(map_path, map);
	empty_check(map->dim[MHEIGHT], map);
	map->dim[MWIDTH] = map->size / map->dim[MHEIGHT];
	map->p = malloc(sizeof(t_point) * map->size);
	mem_check(map->p);
	load_points(map, map->p, map_path);
	// apply_zoom(*map, vc->zoom);
	// project_iso(map, map->p, map->size);
	return (map);
}

static void	*size_of_map(char *map_path, t_map *map)
{
	int		i;
	int		map_fd;
	char	*line;

	open_map(&map_fd, map_path);
	line = get_next_line(map_fd);
	while (line && *line)
	{
		i = 0;
		while (line[i])
		{
			if (is_number(line[i]))
				map->size++;
			while (is_number(line[i]) || is_hex(line[i]))
				i++;
			i++;
		}
		free(line);
		map->dim[MHEIGHT]++;
		line = get_next_line(map_fd);
	}
	free(line);
	close(map_fd);
	return (map->dim);
}

static void	load_points(t_map *map, t_point *points, char *map_path)
{
	char	*line;
	int		c[4];
	int		map_fd;

	map_fd = open(map_path, O_RDONLY);
	line = get_next_line(map_fd);
	c[i] = 0;
	c[y] = 0;
	while (line && *line)
	{
		c[j] = 0;
		c[x] = 0;
		while (line[c[j]] && c[i] < map->size)
		{
			points[c[i]].p_3dv[z] = 0;
			if (is_number(line[c[j]]))
				set_point(points, c, line, &map->max_height);
			c[j]++;
		}
		free(line);
		line = get_next_line(map_fd);
		c[y]++;
	}
	free(line);
	close(map_fd);
}

static void	set_point(t_point *p, int *c, char *line, int *max_height)
{
	p[c[i]].p_3dv[y] = c[y];
	p[c[i]].p_3dv[x] = c[x];
	p[c[i]].color = WHITE_PIXEL;
	c[x]++;
	p[c[i]].p_3dv[z] = get_number(line, &c[j]);
	if (line[c[j]] == ',')
		get_color(&p[c[i]].color, line, &c[j]);
	if (p[c[i]].p_3dv[z] > *max_height)
		*max_height = p[c[i]].p_3dv[z];
	c[i]++;
}

static void	open_map(int *map_fd, char *map_path)
{
	*map_fd = open(map_path, O_RDONLY);
	open_check(*map_fd);
}
