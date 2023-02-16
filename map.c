/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by                   #+#    #+#             */
/*   Updated: 2023/02/15 15:30:04 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "map.h"
#include "get_next_line.h"

static int	size_of_map(char *map_path);
static void load_points(m_point *points, char *map_path);

t_map	*load_map(char *map_path)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (0); // change to mem error
	map->size = size_of_map(map_path);
	map->p = malloc(sizeof(m_point) * map->size);
	if(!map->p)
		return (0);
	load_points(map->p, map_path);
	project_iso(map, map->p, map->size);
	return map;
}

static int	size_of_map(char *map_path)
{
	int		size;
	int		i;
	int		map_fd;
	char	*line;

	map_fd = open(map_path, O_RDONLY);
	size = 0;
	line = get_next_line(map_fd);
	while (line && *line)
	{
		i = 0;
		while (line[i])
		{
			if (is_number(line[i]))
			{
				size++;
				while (is_number(line[i]))
					i++;
			}
			i++;
		}
		free(line);
		line = get_next_line(map_fd);
	}
	free(line);
	close(map_fd);
	return (size);
}

static void load_points(m_point *points, char *map_path)
{
	char *line;
	int i;
	int p_index;
	int row_number;
	int col_number;
	int map_fd;

	map_fd = open(map_path, O_RDONLY);
	line = get_next_line(map_fd);
	p_index = 0;
	row_number = 0;
	while(line && *line)
	{
		i = 0;
		col_number = 0;
		while (line [i])
		{
			points[p_index].p_3dv[z] = 0;
			if (is_number(line[i]))
			{
				points[p_index].p_3dv[y] = SCALE * row_number;
				points[p_index].p_3dv[x] = SCALE * col_number++;
				while (is_number(line[i]))
				{
					points[p_index].p_3dv[z] *= 10;
					points[p_index].p_3dv[z] += line[i] - '0';
					i++;
				}
				p_index++;
			}
			i++;
		}
		free(line);
		line = get_next_line(map_fd);
		row_number++;
	}
	free(line);
	close(map_fd);
}