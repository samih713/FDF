/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:12:56 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/22 19:57:02 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	clamp(int x0, int y0, int x1, int y1);
static void	fill_color(m_point *point0, m_point *point1, int *color);

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
	int	p[6];
	int	color[4]; // 0 start point elevation, 1 start point color, 2 end point elevation, 3 end point color

	i = 0;
	while (i < map->size)
	{
		p[x] = map->os_u + map->p[i].p_2dv[u];
		p[y] = map->os_v + map->p[i].p_2dv[v];
		if (i < map->size - 1)
		{
			p[x_nxt] = map->os_u + map->p[i + 1].p_2dv[u];
			p[y_nxt] = map->os_v + map->p[i + 1].p_2dv[v];
			if (map->p[i].p_3dv[y] == map->p[i + 1].p_3dv[y] && clamp(p[x], p[y], p[x_nxt], p[y_nxt]))
			{
				fill_color(&map->p[i], &map->p[i + 1], color);
				bresenham(&fdf->img, p[x], p[x_nxt], p[y], p[y_nxt], map->p[i].color);
			}
		}
		if (map->p[i].p_3dv[y] >= 1)
		{
			p[x_abv] = map->os_u + map->p[i - map->dim[MWIDTH]].p_2dv[u];
			p[y_abv] = map->os_v + map->p[i - map->dim[MWIDTH]].p_2dv[v];
			if (clamp(p[x], p[y], p[x_abv], p[y_abv]))
			{
				fill_color(&map->p[i], &map->p[i - map->dim[MWIDTH]], color);
				bresenham(&fdf->img, p[x], p[x_abv], p[y], p[y_abv], map->p[i].color);
			}
		}
		i++;
	}
	free(map->p);
}

static void fill_color(m_point *point0, m_point *point1, int *color)
{
	color[height0] = point0->p_3dv[z];
	color[height1] = point1->p_3dv[z];
	color[color0] = point0->color;
	color[color1] = point1->color;
}

static int clamp(int x0, int y0, int x1, int y1)
{
	if (x0 > WINDOW_WIDTH || y0 > WINDOW_HEIGHT)
		return (0);
	else if (x0 < 0 || y0 < 0)
		return (0);
	else if (x1 > WINDOW_WIDTH || y1 > WINDOW_HEIGHT)
		return (0);
	else if (x1 < 0 || y1 < 0)
		return (0);
	return (1);
}
