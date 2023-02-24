/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:29:25 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 06:31:45 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "string.h"

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
void	apply_zoom(t_map *map, t_fdf *fdf)
{
	int		i;
	t_point	*p;

	p = malloc(sizeof(t_point) * map->size);
	memcpy(p, map->p, map->size * sizeof(t_point));
	i = 0;
	printf("zoom is %d\n", fdf->vc.zoom);
	printf("point is %d\n", map->p[i + 9].p_3dv[x]);
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
