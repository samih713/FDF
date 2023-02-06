/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 02:32:19 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/06 04:57:40 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MAP_PATH "../maps/test_maps/42.fdf"

int main(void) {
	int mfd = open(MAP_PATH, O_RDONLY);
	if (mfd <= 0) {
		return (-1);
	}
	parse_points(mfd);

}
