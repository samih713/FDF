/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:12:56 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 20:35:32 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;
	int		c;

	i = img->bpp - 8;
	c = 0;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
		{
			pixel[c] = (color >> i) & 0xFF;
			c++;
		}
		else
		{
			pixel[c] = (color >> (img->bpp - 8 - i)) & 0xFF;
			c++;
		}
		i -= 8;
	}
}

void	render_img(t_fdf *fdf, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->p[i].p_2dv[u] += map->os_u + fdf->vc.x_offset;
		map->p[i].p_2dv[v] += map->os_v + fdf->vc.y_offset;
		i++;
	}
	i = 0;
	while (i < map->size)
	{
		if (i < map->size - 1)
		{
			if (map->p[i].p_3dv[y] == map->p[i + 1].p_3dv[y]
				&& clamp(&map->p[i], &map->p[i + 1]))
				bresenham(&fdf->img, &map->p[i], &map->p[i + 1]);
		}
		if (map->p[i].p_3dv[y] >= 1)
		{
			if (clamp(&map->p[i], &map->p[i - map->dim[MWIDTH]]))
				bresenham(&fdf->img, &map->p[i], &map->p[i - map->dim[MWIDTH]]);
		}
		i++;
	}
}
