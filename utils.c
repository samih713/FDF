/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:25:35 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/20 21:19:19 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  General utilities */
#include "fdf.h"

unsigned int	is_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

unsigned int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

// * only checks if last 4 letters are ".fdf"
unsigned int	format_check(char *map_path, char *format)
{
	size_t	length;

	length = ft_strlen(map_path);
	map_path += length - 4;
	while (*map_path == *format)
	{
		map_path++;
		format++;
		if (!*map_path)
			return (1);
	}
	write(2, "Invalid map format\n", 20);
	exit (EXIT_FAILURE);
}
