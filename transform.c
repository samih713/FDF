/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 05:12:02 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/20 17:19:07 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 3d vector to 2d transformations */

#include "fdf.h"

// TODO move these somewhere else
enum RANGE
{
	RANGE,
	MIN,
	MAX
};
//

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
	// * proper centering is is (window center) - (data range center)
	map->os_u = (WINDOW_WIDTH / 2) - (range_u[MIN] + (range_u[RANGE] / 2));
	map->os_v = (WINDOW_HEIGHT / 2) - (range_v[MIN] + (range_v[RANGE] / 2));
}
// range/2


// * range[range, MIN, MAX]
static void find_range(t_map *map, int *range, int index)
{
	int	i;

	i = 0;
	range[MIN] = map->p[i].p_2dv[index];
	range[MAX] = map->p[i].p_2dv[index];
	while(i < map->size)
	{
		if (map->p[i].p_2dv[index] > range[MAX])
			range[MAX] = map->p[i].p_2dv[index];
		if (map->p[i].p_2dv[index] < range[MIN])
			range[MIN] = map->p[i].p_2dv[index];
		i++;
	}
	range[RANGE] = range[MAX] - range[MIN];
}
