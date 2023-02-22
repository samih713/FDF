/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 04:25:35 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/22 04:52:47 by sabdelra         ###   ########.fr       */
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
// check for prefix ",0x"
unsigned int	is_hex(char c)
{
	char	*hex_u;
	char	*hex_l;

	hex_l = "fedcba";
	hex_u = "FEDCBA";
	if (c == ',' || c == 'x')
		return (1);
	while(*hex_u)
	{
		if (c == *hex_u)
			return (1);
		hex_u++;
	}
	while(*hex_l)
	{
		if (c == *hex_l)
			return (1);
		hex_l++;
	}
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
