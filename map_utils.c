/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:29:25 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 21:33:54 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "string.h"

static void	apply_move(t_fdf *fdf, t_point *p, int size);

void	get_color(int *color, char *line, int *j)
{
	int		i;
	char	*hex_u;
	char	*hex_l;

	*color = 0;
	hex_u = "0123456789ABCDEF";
	hex_l = "0123456789abcdef";
	*j += 3;
	while (line[*j + 1] && line[*j] != ' ')
	{
		i = 0;
		while (hex_u[i] != line[*j] && hex_l[i] != line[*j])
			i++;
		*color *= 10;
		*color += i;
		(*j)++;
	}
}

int	get_number(char *line, int *j)
{
	int	z;
	int	sign;

	z = 0;
	sign = 1;
	if ((*j) >= 1 && line[(*j) - 1] == '-')
		sign = -1;
	while (is_number(line[*j]))
	{
		z *= 10;
		z += line[*j] - '0';
		(*j)++;
	}
	return (sign * z);
}

// * Bonus
// * passing map by value to avoid modifying actual value
// ! replace memcpy
void	apply_zoom(t_map *map, t_fdf *fdf)
{
	int		i;
	t_point	*p;

	p = malloc(sizeof(t_point) * map->size);
	memcpy(p, map->p, map->size * sizeof(t_point));
	i = 0;
	while (i < map->size)
	{
		p[i].p_3dv[x] *= fdf->vc.zoom;
		p[i].p_3dv[y] *= fdf->vc.zoom;
		i++;
	}
	project_iso(map, p, map->size);
	free(p);
	render_img(fdf, map);
}

// ! replace memcpy
void	move_projection(t_map *map, t_fdf *fdf)
{
	// int i;
	t_point *p;

	p = malloc(sizeof(t_point) * map->size);
	memcpy(p, map->p, map->size * sizeof(t_point));
	// i = 0;
	apply_move(fdf, p, map->size);
	apply_zoom(map, fdf);
	/* while (i < map->size)
	{
		if (i < map->size - 1)
		{
			if (map->p[i].p_3dv[y] == map->p[i + 1].p_3dv[y]
				&& clamp(&p[i], &p[i + 1]))
				bresenham(&fdf->img, &p[i], &p[i + 1]);
		}
		if (map->p[i].p_3dv[y] >= 1)
		{
			if (clamp(&p[i], &p[i - map->dim[MWIDTH]]))
				bresenham(&fdf->img, &p[i], &p[i - map->dim[MWIDTH]]);
		}
		i++;
	} */
	free(p);
}

// TODO move clamp to bresenham to avoid weird edges
int	clamp(t_point *p0, t_point *p1)
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

static void	apply_move(t_fdf *fdf, t_point *p, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		p[i].p_2dv[u] += fdf->vc.x_offset;
		p[i].p_2dv[v] += fdf->vc.y_offset;
		i++;
	}
}
