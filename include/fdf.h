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

// * macros
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MAX_ZOOM 20
# define MIN_ZOOM 1
// ! testing
# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xFFFFFF

// * Structs and enums
typedef struct s_point
{
	int p_2dv[2];
	int p_3dv[3];
	int color;
} t_point;
// * Map controls
typedef struct s_view_controls
{
	unsigned int zoom;
	unsigned int x_offset;
	unsigned int y_offset;
}	t_view_controls;
// * 3d point co-ordinates
enum coordinates_3d
{
	x,
	y,
	z
};
// * 2d point co-ordinates
enum coordinates_2d
{
	u,
	v
};
// * map dimensions
enum map_size {
	MWIDTH,
	MHEIGHT
};
// * determine offset when projecting
enum RANGE
{
	RANGE,
	MIN,
	MAX
};
// * map struct
typedef struct s_map
{
	int dim[2];
	int size; // point count
	int os_u; // offset
	int os_v; // offset
	int max_height; // TODO use for color
	t_point *p; // array of structs
} t_map;

enum POINTS
{
	x_nxt = 2,
	y_nxt,
	x_abv,
	y_abv
};
// * color gradient
enum COLOR {
	r,
	g,
	b
};
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
	t_map	*map;
	char	*map_path;
	t_view_controls vc;
}	t_fdf;

#include "get_next_line.h"
#include "map.h"
#include "draw.h"
#include "events.h"

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
