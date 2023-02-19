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
#include "get_next_line.h"
#include "map.h"
#include "draw.h"


// TODO fix enums (unify they are all over the place)
// TODO adjustable window size
// TODO error handling

// macros
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define SCALE 15 // change implementation

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xFFFFFF


//helpers functions
int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue); // still needs to be added
int	is_number(char c);

#endif
