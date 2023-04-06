/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:58:06 by sabdelra          #+#    #+#             */
/*   Updated: 2023/04/06 06:42:15 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_mlx(t_fdf *fdf, char *map);
static void	init_fdf(t_fdf *fdf);

int	main(int argc, char **argv)
{
	t_fdf	fdf;

	arg_check(argc);
	init_fdf(&fdf);
	format_check(argv[1], ".fdf");
	fdf.map_path = (argv[1]);
	fdf.map = load_map(fdf.map_path);
	init_mlx(&fdf, argv[1]);
	apply_zoom(fdf.map, &fdf);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.mlx_img, 0, 0);
	mlx_loop_hook(fdf.mlx_ptr, &handle_no_event, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0L, &close_window, &fdf);
	mlx_hook(fdf.win_ptr, 3, 1L << 1, &handle_keyrelease, &fdf);
	mlx_hook(fdf.win_ptr, 2, 1L << 0, &handle_keypress, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}

static void	init_fdf(t_fdf *fdf)
{
	fdf->vc.zoom = 3;
	fdf->vc.x_offset = 0;
	fdf->vc.y_offset = 0;
	fdf->vc.angle.a = 0;
	fdf->vc.angle.b = 0;
	fdf->vc.angle.g = 0;
}

static void	init_mlx(t_fdf *fdf, char *map)
{
	fdf->mlx_ptr = mlx_init();
	mem_check(fdf->mlx_ptr);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, map);
	mem_check(fdf->win_ptr);
	fdf->img.mlx_img = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mem_check(fdf->img.mlx_img);
	fdf->img.addr = mlx_get_data_addr(fdf->img.mlx_img, &fdf->img.bpp,
			&fdf->img.line_len, &fdf->img.endian);
}
