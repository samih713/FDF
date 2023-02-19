/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 05:12:02 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/19 21:36:02 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 3d vector to 2d transformations */

#include "fdf.h"

// TODO change offset implementation to more dynamic
/* Isometric transformation */
void	project_iso(t_map *map, m_point *points, int size)
{
	int i;

	i = 0;
	map->os_u = 0;
	while(i < size)
	{
		points[i].p_2dv[u] = (points[i].p_3dv[x] - points[i].p_3dv[y]) * cos(0.523599);
		points[i].p_2dv[v] = -points[i].p_3dv[z] + (points[i].p_3dv[x] + points[i].p_3dv[y]) * cos(0.523599);

		if (map->os_u > points[i].p_2dv[u])
			map->os_u = points[i].p_2dv[u];
		i++;
	}
	if (map->os_u < 0)
		map->os_u *= -1;
}
