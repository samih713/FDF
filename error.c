/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:27:24 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/20 21:43:50 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// TODO access to check if file exists and accessable?


// ! access allowed?
// ! is exit allowed?
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
