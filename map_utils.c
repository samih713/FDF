/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 01:29:25 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 03:37:17 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
void	apply_zoom(t_map *map, int zoom)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		map->p[i].p_3dv[x] *= zoom;
		map->p[i].p_3dv[y] *= zoom;
		i++;
	}
}
