/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:12:56 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 00:00:43 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	clamp(t_point *p0, t_point *p1);

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
		if (img->endian != 0) {
			pixel[c] = (color >> i) & 0xFF;
			c++;
		}
		else {
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
	// TODO ready for movement I guess
	while (i < map->size)
	{
		map->p[i].p_2dv[u] += map->os_u;
		map->p[i].p_2dv[v] += map->os_v;
		i++;
	}
	i = 0;
	while (i < map->size)
	{
		if (i < map->size - 1)
		{
			if (map->p[i].p_3dv[y] == map->p[i + 1].p_3dv[y] && clamp(&map->p[i], &map->p[i + 1]))
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

static int	clamp(t_point *p0, t_point *p1)
{

	if (p0->p_2dv[u] > WIN_WIDTH - 1 || p0->p_2dv[v] > WIN_HEIGHT - 1)
		return (0);
	else if (p0->p_2dv[u] < 0 || p0->p_2dv[v] < 0)
		return (0);
	else if (p1->p_2dv[u] > WIN_WIDTH - 1 || p1->p_2dv[v] > WIN_HEIGHT - 1)
		return (0);
	else if (p1->p_2dv[u] < 0 || p1->p_2dv[v] < 0)
		return (0);
	return (1);
}
