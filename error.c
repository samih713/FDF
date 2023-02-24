/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:27:24 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 04:10:17 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	mem_check(void *allocated_memory)
{
	if (!allocated_memory)
	{
		write(2, "Memory allocation failed\n", 26);
		exit(EXIT_FAILURE);
	}
}

void	arg_check(int argc)
{
	if (argc != 2)
	{
		write(2, "Invalid number of arguments, please specify map path\n", 54);
		exit(EXIT_FAILURE);
	}
}

void	open_check(int map_fd)
{
	if (map_fd < 0)
	{
		write(2, "Invalid path\n", 14);
		exit (EXIT_FAILURE);
	}
}

void	empty_check(int map_size, t_map *map)
{
	if (!map_size)
	{
		write(2, "Empty map\n", 11);
		free(map);
		exit (EXIT_FAILURE);
	}
}
