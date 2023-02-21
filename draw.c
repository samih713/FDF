/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:12:56 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/21 04:17:53 by sabdelra         ###   ########.fr       */
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
	int	i;
	int	point[6];

	i = 0;
	while (i < map->size - 1)
	{
		point[x] = map->os_u + map->p[i].p_2dv[u];
		point[x_nxt] = map->os_u + map->p[i + 1].p_2dv[u];
		point[y] = map->os_v + map->p[i].p_2dv[v];
		point[y_nxt] = map->os_v + map->p[i + 1].p_2dv[v];
		if (map->p[i].p_3dv[y] == map->p[i + 1].p_3dv[y])
			bresenham(&fdf->img, point[x], point[x_nxt], point[y], point[y_nxt], RED_PIXEL);
		if (map->p[i].p_3dv[y] >= 1) {
			point[x_abv] = map->os_u + map->p[i - map->dim[MWIDTH]].p_2dv[u];
			point[y_abv] = map->os_v + map->p[i - map->dim[MWIDTH]].p_2dv[v];
			bresenham(&fdf->img, point[x], point[x_abv], point[y], point[y_abv], RED_PIXEL);
		}
		i++;
	}
	free(map->p);
}
