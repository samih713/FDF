/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 02:59:28 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/06 05:01:48 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// move to utils
int	is_number(char c) {
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
// move to utils

// **************************** //
static	t_map *create_map(int count, t_point **point) {
	t_map *map;

	map = malloc(sizeof(t_map));
	map->point = malloc(sizeof(t_point *) * count);
	map->point = point;
	return (map);
}

t_map	*parse_points(int mfd) {
	int	norm[3];// [0:count, 1:i, 2:y]
	char *line;
	t_point **point;

	norm[2] = 0;
	norm[0] = 0;
	line = get_next_line(mfd);
	while (line) {
		norm[1] = 0;
		point[norm[0]] = malloc(sizeof(t_point));
		point[norm[0]]->p_v3d[0] = 0;
		while (line[norm[1]]) {
			if (is_number(line[norm[1]])) {
				point[norm[0]]->p_v3d[0]++;
				point[norm[0]]->p_v3d[1] = norm[2];
				point[norm[0]]->p_v3d[2] = 0;
				while (is_number(line[norm[1]])) {
					point[norm[0]]->p_v3d[2] += line[norm[1]] - '0';
					norm[1]++;
				}
				norm[0]++;
			}
			norm[1]++;
		}
		norm[2]++;
		line = get_next_line(mfd);
	}
	return (create_map(norm[1] + 1, point));
}

