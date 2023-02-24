/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 05:36:58 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 05:28:25 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* just general testing make a better main for final version */

#include "fdf.h"
#include <stdio.h>

static void	init_mlx(t_fdf *fdf, char *map);

int main(int argc, char **argv)
{
	t_fdf	fdf;

	fdf.vc.zoom = 3;
	arg_check(argc);
	format_check(argv[1], ".fdf");
	fdf.map_path = (argv[1]);
	fdf.map = load_map(fdf.map_path);
	// * mlx initiation
	init_mlx(&fdf, argv[1]);
	// * draw map on image
	apply_zoom(fdf.map, &fdf);
	// render_img(&fdf, fdf.map);
	// *maybe centering is here 0, 0?
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.mlx_img, 0, 0);
	// * Hooks
	mlx_loop_hook(fdf.mlx_ptr, &handle_no_event, &fdf);
	// mlx_key_hook(fdf.win_ptr, &handle_keypress, &fdf);
	mlx_hook(fdf.win_ptr, 17, 0L, &close_window, &fdf);
	mlx_hook(fdf.win_ptr, 3, 1L<<1, &handle_keyrelease, &fdf);
	mlx_hook(fdf.win_ptr, 2, 1L<<0, &handle_keypress, &fdf);
	mlx_loop(fdf.mlx_ptr);
	return (0);
}

static void	init_mlx(t_fdf *fdf, char *map)
{
	fdf->mlx_ptr = mlx_init();
	mem_check(fdf->mlx_ptr);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, map);
	mem_check(fdf->win_ptr);
	fdf->img.mlx_img = mlx_new_image(fdf->mlx_ptr,WIN_WIDTH ,WIN_HEIGHT);
	mem_check(fdf->img.mlx_img);
	fdf->img.addr = mlx_get_data_addr(fdf->img.mlx_img, &fdf->img.bpp, &fdf->img.line_len, &fdf->img.endian);
}
