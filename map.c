/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/02/20 17:28:47 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "map.h"
#include "get_next_line.h"

// TODO cleanup this files a mess

static int	*size_of_map(char *map_path, t_map *map);
static void load_points(t_map *map, m_point *points, char *map_path); // just give it map du

t_map	*load_map(char *map_path)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0); // change to mem error
	map->dim = malloc(sizeof(int) * 2);
	map->dim = size_of_map(map_path, map);
	map->size = map->dim[MWIDTH] * map->dim[MHEIGHT];
	map->p = malloc(sizeof(m_point) * map->size);
	if(!map->p)
		return (0);
	load_points(map, map->p, map_path);
	project_iso(map, map->p, map->size);
	return map;
}

static int	*size_of_map(char *map_path, t_map *map)
{
	int		i;
	int		map_fd;
	char	*line;

	map_fd = open(map_path, O_RDONLY);
	map->dim[MWIDTH] = 0;
	map->dim[MHEIGHT] = 0;
	line = get_next_line(map_fd);
	while (line && *line)
	{
		i = 0;
		while (line[i])
		{
			if (is_number(line[i]))
			{
				map->dim[MWIDTH]++;
				while (is_number(line[i]))
					i++;
			}
			i++;
		}
		free(line);
		map->dim[MHEIGHT]++;
		line = get_next_line(map_fd);
	}
	map->dim[MWIDTH] /= map->dim[MHEIGHT]; //
	free(line);
	close(map_fd);
	return (map->dim);
}

static void load_points(t_map *map, m_point *points, char *map_path)
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
		while (line [j])
		{
			points[i].p_3dv[z] = 0;
			if (is_number(line[j]))
			{
				points[i].p_3dv[y] = SCALE * row_number;
				points[i].p_3dv[x] = SCALE * col_number++;
				while (is_number(line[j]))
				{
					points[i].p_3dv[z] *= 10;
					points[i].p_3dv[z] += line[j] - '0';
					j++;
				}
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
