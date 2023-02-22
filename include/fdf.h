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
#include "get_next_line.h"
#include "map.h"
#include "draw.h"

// macros
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define SCALE 3 // change implementation

// ! wtf is this for?
# define MLX_ERROR 1

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
// TODO handle hex input (height,0xcolor or 0xcolor)
// TODO segfault when scale is too large or map is too large
// TODO events (checkout github page how to handle keypresses ...)
// TODO parallel projection
// TODO zoom
// TODO program name should be fdf
// TODO error handling
// TODO Testing (brainstorm)
// * extra
// TODO add menu with controls
// TODO color gradient
// TODO window title based on map
// TODO window size based on drawing? or scale?
// TODO adjustable window size
// * before submission
// TODO remove encode rgb and other not used functions
// TODO file clean-up
// TODO norminette
// TODO Makefile
// *dump event ideas here
// TODO escape and basic controls from subject
// TODO zoom in out
// TODO move map (u,d,l,r)
// * dump error testing ideas here
// TODO uneven lines in map (row1 = 3 points, row2 = 6 points ...)
