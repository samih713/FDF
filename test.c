/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 05:36:58 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/21 04:37:50 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* just general testing make a better main for final version */

#include "fdf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_map	*map;
	t_fdf	fdf;

	arg_check(argc);
	format_check(argv[1], ".fdf");
	map = load_map(argv[1]);
	printf("os_v = %d\n", map->os_v);
	// * mlx initiation
	fdf.mlx_ptr = mlx_init();
	mem_check(fdf.mlx_ptr);
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, argv[1]);
	mem_check(fdf.win_ptr);
	fdf.img.mlx_img = mlx_new_image(fdf.mlx_ptr,WINDOW_WIDTH ,WINDOW_HEIGHT);
	mem_check(fdf.img.mlx_img);
	fdf.img.addr = mlx_get_data_addr(fdf.img.mlx_img, &fdf.img.bpp, &fdf.img.line_len, &fdf.img.endian);
	// ***********************
	render_img(&fdf, map);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.mlx_img, 0, 0);
	// ***********************
	while(1);
	mlx_destroy_image(fdf.mlx_ptr, &fdf.img);
	mlx_destroy_window(fdf.mlx_ptr, fdf.win_ptr);
	mlx_destroy_display(fdf.mlx_ptr);
	free(&fdf.img);
	free(fdf.win_ptr);
	free(fdf.mlx_ptr);
	free(map);
	return (0);
}

