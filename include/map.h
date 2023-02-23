/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:43 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/23 03:08:51 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include "fdf.h"

// TODO change to s_point and t_point
typedef struct m_point
{
	int p_2dv[2];
	int p_3dv[3];
	int color;
} m_point;

// * 3d point co-ordinates
enum coordinates_3d
{
	x,
	y,
	z
};
// * 2d point co-ordinates
enum coordinates_2d
{
	u,
	v
};
// * map dimensions
enum map_size {
	MWIDTH,
	MHEIGHT
};
// * determine offset when projecting
enum RANGE
{
	RANGE,
	MIN,
	MAX
};
typedef struct s_map
{
	int dim[2];
	int size; // point count
	int os_u; // offset
	int os_v; // offset
	int max_height; // TODO use for color
	m_point *p; // array of structs
} t_map;

// Map functions
t_map	*load_map(char *map_path);
// projection
void	project_iso(t_map *map, m_point *points, int size);

#endif
