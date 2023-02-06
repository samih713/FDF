/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 03:10:06 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/06 04:57:04 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
#define MAP_H

typedef struct s_point {
	int	p_v3d[3];
	int p_v2d[2];
	// int	color;
}	t_point;

typedef struct s_map {
	int	dim[2]; // WIDTH HEIGHT
	t_point	**point;
} t_map;

t_map	*parse_points(int mfd);


#endif
