#include "fdf.h"

/* int main(void)
{
	void	*mlx_ptr; //initializes a struct t_varx some shit
	void	*win_ptr;
	int		color;

	color = encode_rgb(23, 66, 2);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "Hello World!");
	for (int i = 0; i < WINDOW_WIDTH; i++)
		mlx_pixel_put(mlx_ptr, win_ptr, i, 40, color);
	while(1);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
} */

int main(void)
{
	int fd = open("file.txt", O_RDONLY);
	for(int i = 0; i < 5; i++)
		printf("%s",get_next_line(fd));
}

