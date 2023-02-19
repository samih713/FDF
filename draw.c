/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:12:56 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/19 20:51:28 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
    pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0) {
			*pixel = (color >> i) & 0xFF;
			pixel++;
		}
		else {
			*pixel = (color >> (img->bpp - 8 - i)) & 0xFF;
			pixel++;
		}
		i -= 8;
	}
}

void	render_img(t_fdf *fdf, t_map *map)
{
	int i;
	int a;
	int b;
	int u0, u1, v0, v1;
	int u_above, v_above;

	i = 0;
	while (i < map->size)
	{
		a = map->os_u + map->p[i].p_2dv[u];
		b = map->os_u + map->p[i].p_2dv[v];
		img_pix_put(fdf->img, a, b, RED_PIXEL);
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
			bresenham(fdf->img, u0, u1, v0, v1, RED_PIXEL);
		if (i > 18) {
			u_above = map->os_u + map->p[i - 19].p_2dv[u]; //19 is hardcoding the next line???
			v_above = map->os_u + map->p[i - 19].p_2dv[v];
			bresenham(fdf->img, u0, u_above, v0, v_above, RED_PIXEL);
		}
		i++;
	}
}
