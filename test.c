/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 05:36:58 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/16 16:59:38 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* just general testing make a better main for final version */


#include "map.h"
#include "fdf.h"
#include <stdio.h>


int main(void)
{
	t_map *map;
	void	*mlx_ptr;
	void	*win_ptr;
	int white, red;
	int i;
	int a, b;
	int u0, u1, v0, v1, u_above, v_above;
	int color;

	white = encode_rgb(255, 255, 255);
	red = encode_rgb(255, 0, 0);
	color = red;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "o55k");
	i = 0;
	map = load_map(MAP_FILE);
	while (i < map->size)
	{
		a = map->os_u + map->p[i].p_2dv[u];
		b = map->os_u + map->p[i].p_2dv[v];
		mlx_pixel_put(mlx_ptr, win_ptr, a, b, color);
		i++;
	}
	i = 0;
	while (i <= (map->size - 1))
	{
		u0 = map->os_u + map->p[i].p_2dv[u];
		u1 = map->os_u + map->p[i + 1].p_2dv[u];
		v0 = map->os_u + map->p[i].p_2dv[v];
		v1 = map->os_u + map->p[i + 1].p_2dv[v];
		if (map->p[i].p_3dv[y] == map->p[i + 1].p_3dv[y])
			bresenham(u0, u1, v0, v1, mlx_ptr, win_ptr, color);
		if (i > 18) {
			u_above = map->os_u + map->p[i - 19].p_2dv[u]; //19 is hardcoding the next line???
			v_above = map->os_u + map->p[i - 19].p_2dv[v];
			bresenham(u0, u_above, v0, v_above, mlx_ptr, win_ptr, color);
		}
		i++;
	}
	printf("offset is: %d\n", map->os_u);
	while(1);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(win_ptr);
	free(mlx_ptr);
	free(map->p);
	free(map);
}

