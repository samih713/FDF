/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:43 by sabdelra          #+#    #+#             */
/*   Updated: 2023/04/06 06:41:56 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include "fdf.h"
// * Structs
typedef struct s_point
{
	int	p_2dv[2];
	int	p_3dv[3];
	int	color;
}	t_point;
// * angle
typedef struct s_angle
{
	double	a;
	double	b;
	double	g;
}	t_angle;
// * Map controls
typedef struct s_view_controls
{
	int	zoom;
	int	x_offset;
	int	y_offset;
	t_angle	angle;
}	t_vc;
// * Map
typedef struct s_map
{
	int		dim[2];
	int		size;
	int		os_u;
	int		os_v;
	int		max_height;
	t_point	*p;
}	t_map;
// * Image
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;
// * FDF king of structs
typedef struct s_fdf
{
	t_vc	vc;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	*map;
	char	*map_path;
}	t_fdf;
//* Map functions & utils
t_map	*load_map(char *map_path);
void	get_color(int *color, char *line, int *j);
int		get_number(char *line, int *j);
//* projection and rotation
void	project_iso(t_fdf *fdf, t_map *map, t_point *points, int size);
int		clamp(t_point *p0, t_point *p1);
void	apply_rotation(t_point *p, t_angle angle, int size);
// * bonus
void	apply_zoom(t_map *map, t_fdf *fdf);
void	move_projection(t_map *map, t_fdf *fdf);

#endif
