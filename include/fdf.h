#ifndef FDF_H
# define FDF_H

// includes
#include <mlx.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

// macros
# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 800
# define SCALE 15 // change implementation

# define MLX_ERROR 1

# define RED_PIXEL 0xFF0000

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_fdf;


//helpers functions
int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue); // still needs to be added
int	is_number(char c);

#endif
