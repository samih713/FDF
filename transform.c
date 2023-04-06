/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 05:12:02 by sabdelra          #+#    #+#             */
/*   Updated: 2023/04/06 06:33:21 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 3d vector to 2d transformations */

#include "fdf.h"
#include <stdlib.h>

static void	find_range(t_map *map, int *range, int index);
static void	matrix_rotate(t_point *p, t_angle a, int i);

void	project_iso(t_fdf *fdf, t_map *map, t_point *p, int size)
{
	int	i;
	int	range_u[3];
	int	range_v[3];

	i = 0;
	apply_rotation(p, fdf->vc.angle, map->size);
	while (i < size)
	{
		map->p[i].p_2dv[u] = (p[i].p_3dv[x] - p[i].p_3dv[y]) * cos(ISO_ANGLE);
		map->p[i].p_2dv[v] = -p[i].p_3dv[z] + (p[i].p_3dv[x]
				+ p[i].p_3dv[y]) * sin(ISO_ANGLE);
		i++;
	}
	find_range(map, range_u, u);
	find_range(map, range_v, v);
	map->os_u = (WIN_WIDTH / 2) - (range_u[MIN] + (range_u[RANGE] / 2));
	map->os_v = (WIN_HEIGHT / 2) - (range_v[MIN] + (range_v[RANGE] / 2));
}

void	apply_rotation(t_point *p, t_angle angle, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		matrix_rotate(p, angle, i);
		i++;
	}
}

// * range[range, MIN, MAX]
static void	find_range(t_map *map, int *range, int index)
{
	int	i;

	i = 0;
	range[MIN] = map->p[i].p_2dv[index];
	range[MAX] = map->p[i].p_2dv[index];
	while (i < map->size)
	{
		if (map->p[i].p_2dv[index] > range[MAX])
			range[MAX] = map->p[i].p_2dv[index];
		if (map->p[i].p_2dv[index] < range[MIN])
			range[MIN] = map->p[i].p_2dv[index];
		i++;
	}
	range[RANGE] = range[MAX] - range[MIN];
}

static void	matrix_rotate(t_point *p, t_angle a, int i)
{
	int	_x;
	int	_y;
	int	_z;

	_x = p[i].p_3dv[x];
	_y = p[i].p_3dv[y];
	_z = p[i].p_3dv[z];
	p[i].p_3dv[x] = (((cos(a.b) * cos(a.g))) * _x)
		+ (((sin(a.a)) * sin(a.b) * cos(a.g) - (cos(a.a) * sin(a.g))) * _y)
		+ (((cos(a.a) * sin(a.b) * cos(a.g)) + sin(a.a) * sin(a.g)) * _z);
	p[i].p_3dv[y] = (((cos(a.b) * sin(a.g))) * _x)
		+ (((sin(a.a)) * sin(a.b) * sin(a.g) + (cos(a.a) * cos(a.g))) * _y)
		+ (((cos(a.a) * sin(a.b) * sin(a.g)) - sin(a.a) * cos(a.g)) * _z);
	p[i].p_3dv[z] = (-sin(a.a) * _x) + (((sin(a.a) * cos(a.b))) * _y)
		+ ((cos(a.a) * cos(a.b)) * _z);
}
