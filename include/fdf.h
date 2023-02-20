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

// TODO maps are not fixed width, maybe make mwidth an array?
// TODO segfault when scale is too large or map is too large
// TODO events
// TODO fix lines not reaching the end
// TODO error handling
// TODO zoom

// TODO change the isometeric angle
// TODO add menu with controls
// TODO window size based on drawing? or scale?
// TODO adjustable window size
// macros
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600
# define SCALE 10 // change implementation

// TODO use this if exit is not allowed
# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xFFFFFF


// * Utilities
unsigned int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue); // still needs to be added
unsigned int	is_number(char c);
unsigned int	format_check(char *map_path, char *format);

// *ERORR handling
void	mem_check(void *allocated_memory);
void	arg_check(int argc);

#endif
