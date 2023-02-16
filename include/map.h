/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:43 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/16 15:13:14 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include <stdbool.h>

// color

// Map
#define MAP_FILE "/home/eva001/42/FDF/maps/maps/test_maps/42.fdf"

typedef struct m_point
{
	int p_2dv[2];
	int p_3dv[3];
} m_point;

enum coordinates_3d
{
	x,
	y,
	z
};
enum coordinates_2d
{
	u,
	v
};

typedef struct t_map
{
	int size; // point count
	int os_u; // offset
	int max_u;
	bool color;
	m_point *p; // array of structs
} t_map;

// Map functions
t_map *load_map(char *map_path);
// projection
void project_iso(t_map *map, m_point *points, int size);
// bresenham
void bresenham(int x0, int x1, int y0, int y1, void *mlx_ptr, void *win_ptr, int color);

#endif
