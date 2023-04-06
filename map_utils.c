/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:29:25 by sabdelra          #+#    #+#             */
/*   Updated: 2023/04/06 06:41:41 by sabdelra         ###   ########.fr       */
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

void	apply_zoom(t_map *map, t_fdf *fdf)
{
	int		i;
	t_point	*p;

	p = malloc(sizeof(t_point) * map->size);
	mem_check(p);
	ft_memcpy(p, map->p, map->size * sizeof(t_point));
	i = 0;
	while (i < map->size)
	{
		p[i].p_3dv[x] *= fdf->vc.zoom;
		p[i].p_3dv[y] *= fdf->vc.zoom;
		i++;
	}
	project_iso(fdf, map, p, map->size);
	free(p);
	render_img(fdf, map);
}

void	move_projection(t_map *map, t_fdf *fdf)
{
	t_point	*p;

	p = malloc(sizeof(t_point) * map->size);
	ft_memcpy(p, map->p, map->size * sizeof(t_point));
	apply_move(fdf, p, map->size);
	apply_zoom(map, fdf);
	free(p);
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
