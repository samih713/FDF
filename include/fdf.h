#ifndef FDF_H
# define FDF_H

// includes
#include <mlx.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <math.h>
#include <stdbool.h>
#include <X11/keysym.h>
#include "get_next_line.h"
#include "map.h"
#include "draw.h"
#include "events.h"

// macros
# define WIN_WIDTH 900
# define WIN_HEIGHT 720
# define MAX_ZOOM 20
# define MIN_ZOOM 1
// ! testing
# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xFFFFFF

// * Utilities
unsigned int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue); // still needs to be added
unsigned int	is_number(char c);
unsigned int	format_check(char *map_path, char *format);
unsigned int	is_hex(char c);

// *ERORR handling
void	mem_check(void *allocated_memory);
void	arg_check(int argc);
void	open_check(int map_fd);
void	empty_check(int map_size, t_map *map);

#endif

// * Priority
// TODO improve zoom
// TODO program name should be fdf
// TODO error handling
// TODO Testing (brainstorm)
// * extra
// doesnt have to be same dimensions as window maybe
// TODO parallel projection
// TODO add menu with controls
// TODO clamp the wiredrawing instead
// TODO window title based on map
// * before submission
// TODO file clean-up
// TODO norminette
// TODO Makefile
// *dump event ideas here
// TODO zoom for elevation (shift + zoom) controls
// TODO move map (u,d,l,r)
// * dump error testing ideas here
