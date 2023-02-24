/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:18:21 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 16:35:54 by sabdelra         ###   ########.fr       */
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
# include <X11/keysym.h>
// * Local Includes
# include "get_next_line.h"
# include "map.h"
# include "draw.h"
# include "events.h"
// * macros
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MAX_ZOOM 20
# define MIN_ZOOM 1
// * colors
# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xFFFFFF

// * ENUMS for readability
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
// *ERORR handling
void			mem_check(void *allocated_memory);
void			arg_check(int argc);
void			open_check(int map_fd);
void			empty_check(int map_size, t_map *map);

#endif

// * Priority
// ! replace memcpy in apply_zoom
// TODO move clamp to bresenham to avoid weird edges
// TODO error handling
// TODO Testing (brainstorm)
// * extra
// TODO parallel projection
// TODO add menu with controls
// TODO window title based on map
// TODO program name should be fdf
// * before submission
// TODO file clean-up
// TODO norminette
// TODO Makefile
// *dump event ideas here
// TODO move map (u,d,l,r)
// TODO zoom for elevation (shift + zoom) controls
// * dump error testing ideas here
