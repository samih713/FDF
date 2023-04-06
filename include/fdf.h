/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:18:21 by sabdelra          #+#    #+#             */
/*   Updated: 2023/04/06 05:53:05 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
// * Includes
# include <mlx.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
// * Local Includes
# include "get_next_line.h"
# include "map.h"
# include "draw.h"
# include "events.h"
// * macros
# define WIN_WIDTH 1240
# define WIN_HEIGHT 1240
# define MAX_ZOOM 40
# define MIN_ZOOM 1
// * colors
# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xFFFFFF
//* isometric angle
#define ISO_ANGLE 0.523599

// * 3d point co-ordinates
enum e_coordinates_3d
{
	x,
	y,
	z
};
// * 2d point co-ordinates
enum e_coordinates_2d
{
	u,
	v
};
// * map dimensions
enum e_map_size {
	MWIDTH,
	MHEIGHT
};
// * determine offset when projecting
enum e_range
{
	RANGE,
	MIN,
	MAX
};

enum e_points
{
	x_nxt = 2,
	y_nxt,
	x_abv,
	y_abv
};

// * color gradient
enum e_color {
	r,
	g,
	b
};

// * Utilities
unsigned int	is_number(char c);
unsigned int	format_check(char *map_path, char *format);
unsigned int	is_hex(char c);
void	*ft_memcpy(void *dest, const void	*src, size_t n);

// * ERORR handling
void			mem_check(void *allocated_memory);
void			arg_check(int argc);
void			open_check(int map_fd);
void			empty_check(int map_size, t_map *map);

#endif

// * extra
// TODO zoom for elevation (shift + zoom) controls
// TODO parallel projection
// TODO window title based on map
// TODO add menu with controls

