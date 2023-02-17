/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 05:36:58 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/17 17:30:55 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* just general testing make a better main for final version */


#include "map.h"
#include "fdf.h"
#include <stdio.h>

void	img_pix_put(t_img *img, int a, int b, int color) {
	char	*pixel;

	pixel = img->addr + (b * img->line_len + (a * (img->bpp / sizeof(int))));
	*(int *)pixel = color;
}

int main(void)
{
	t_map *map;
	t_fdf	fdf;
	void	*win_ptr;
	int white, red;
	int i;
	int a, b;
	int u0, u1, v0, v1, u_above, v_above;
	int color;

	white = encode_rgb(255, 255, 255);
	red = encode_rgb(255, 0, 0);
	color = red;
	fdf.mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(fdf.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "o55k");
	i = 0;
	map = load_map(MAP_FILE);
	fdf.img.mlx_img = mlx_new_image(fdf.mlx_ptr,WINDOW_WIDTH ,WINDOW_HEIGHT);
	fdf.img.addr = mlx_get_data_addr(fdf.img.mlx_img, &fdf.img.bpp, &fdf.img.line_len, &fdf.img.endian);
	while (i < map->size)
	{
		a = map->os_u + map->p[i].p_2dv[u];
		b = map->os_u + map->p[i].p_2dv[v];
		img_pix_put(fdf.img.mlx_img, a, b, color);
		i++;
	}
	i = 0;
	while (i < map->size)
	{
		u0 = map->os_u + map->p[i].p_2dv[u];
		u1 = map->os_u + map->p[i + 1].p_2dv[u];
		v0 = map->os_u + map->p[i].p_2dv[v];
		v1 = map->os_u + map->p[i + 1].p_2dv[v];
		if (map->p[i].p_3dv[y] == map->p[i + 1].p_3dv[y])
			bresenham(fdf.img, u0, u1, v0, v1, color);
		if (i > 18) {
			u_above = map->os_u + map->p[i - 19].p_2dv[u]; //19 is hardcoding the next line???
			v_above = map->os_u + map->p[i - 19].p_2dv[v];
			bresenham(fdf.img, u0, u_above, v0, v_above, color);
		}
		i++;
	}
	mlx_put_image_to_window(fdf.mlx_ptr, fdf.win_ptr, fdf.img.mlx_img, 0, 0);
	while(1);
	mlx_destroy_window(fdf.mlx_ptr, win_ptr);
	mlx_destroy_display(fdf.mlx_ptr);
	free(win_ptr);
	free(fdf.mlx_ptr);
	free(map->p);
	free(map);
}

