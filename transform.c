/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 05:12:02 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/20 02:49:12 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 3d vector to 2d transformations */

#include "fdf.h"

// TODO change offset implementation to more dynamic
static void find_range(t_map *map, int *range, int index);
/* Isometric transformation */
void	project_iso(t_map *map, m_point *p, int size)
{
	int	i;
	int	range_u[3];
	int	range_v[3];

	i = 0;
	while(i < size)
	{
		p[i].p_2dv[u] = (p[i].p_3dv[x] - p[i].p_3dv[y]) * cos(0.523599);
		p[i].p_2dv[v] = -p[i].p_3dv[z] + (p[i].p_3dv[x] + p[i].p_3dv[y]) * cos(0.523599);
		i++;
	}
	find_range(map, range_u, u);
	find_range(map, range_v, v);
	map->os_u = (WINDOW_WIDTH - range_u[0]) / 2;
	map->os_v = (WINDOW_HEIGHT - range_v[0]) / 2;
}

static void find_range(t_map *map, int *range, int index)
{
	int	i;
	int	min;
	int	max;

	i = 0;
	min = map->p[i].p_2dv[index];
	max = map->p[i].p_2dv[index];
	while(i < map->size)
	{
		if (map->p[i].p_2dv[index] > max)
			max = map->p[i].p_2dv[index];
		if (map->p[i].p_2dv[index] < min)
			min = map->p[i].p_2dv[index];
		i++;
	}
	range[1] = min;
	range[2] = max;
	range[0] = max - min;
}
