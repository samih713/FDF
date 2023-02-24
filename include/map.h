/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:34:43 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 05:28:14 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

#include "fdf.h"

// Map functions & utils
t_map	*load_map(char *map_path);
void	get_color(int *color, char *line, int *j);
int		get_number(char *line, int *j);
// projection
void	project_iso(t_map *map, t_point *points, int size);
// * bonus?
void	apply_zoom(t_map *map, t_fdf *fdf);

#endif
