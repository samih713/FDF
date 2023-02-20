/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 05:36:58 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/20 17:27:39 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* just general testing make a better main for final version */

#include "fdf.h"
#include <stdio.h>

int main(void)
{
	t_map *map;
	t_fdf	fdf;
	int u0, u1, v0, v1, u_above, v_above;

	fdf.mlx_ptr = mlx_init();
	if (!fdf.mlx_ptr)
		return 0;
	fdf.win_ptr = mlx_new_window(fdf.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, MAP_FILE);
	fdf.img->mlx_img = mlx_new_image(fdf.mlx_ptr,WINDOW_WIDTH ,WINDOW_HEIGHT);
	map = load_map(MAP_FILE);
	fdf.img->addr = mlx_get_data_addr(fdf.img->mlx_img, &fdf.img->bpp, &fdf.img->line_len, &fdf.img->endian);
	render_img(&fdf, map);
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img->mlx_img, 0, 0);
	while(1);
	mlx_destroy_window(fdf.mlx_ptr, fdf.win_ptr);
	mlx_destroy_display(fdf.mlx_ptr);
	free(fdf.win_ptr);
	free(fdf.mlx_ptr);
	free(map->p);
	free(map);
}

