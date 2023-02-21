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

// * Priority
// TODO handle hex input (height,0xcolor or 0xcolor)
// TODO segfault when scale is too large or map is too large
// TODO events (checkout github page how to handle keypresses ...)
// TODO parallel projection
// TODO program name should be fdf
// TODO Testing (brainstorm)
// TODO error handling
// * extra
// TODO add menu with controls
// TODO window title based on map
// TODO window size based on drawing? or scale?
// TODO adjustable window size
// * before submission
// TODO file clean-up
// TODO norminette
// TODO Makefile
// *events
// TODO escape and basic controls from subject
// TODO zoom in out
// TODO move map (u,d,l,r)
// macros
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define SCALE 5 // change implementation

// ! wtf is this for?
# define MLX_ERROR 1

// ! testing
# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xFFFFFF


// * Utilities
unsigned int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue); // still needs to be added
unsigned int	is_number(char c);
unsigned int	format_check(char *map_path, char *format);

// *ERORR handling
void	mem_check(void *allocated_memory);
void	arg_check(int argc);
void	open_check(int map_fd);
void	empty_check(int map_size, t_map *map);

#endif
