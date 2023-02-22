/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wires.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 05:10:01 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/22 20:13:32 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function to draw the lines */

#include "fdf.h"
// TODO reduce function arguments and function size
// TODO color start end point maybe flipped maybe with ch variable
// TODO change this to accept point
void bresenham(t_img *img, int x0, int x1, int y0, int y1, int color)
{
	int x, y;
	// int c_color; // current color
	x = x0;
	y = y0;
	//
	int dx, dy;
	dx = abs(x1 - x0);
	dy = abs(y1 - y0);
	//
	int sx, sy;
	if (x1 < x0) sx = -1;
	else sx=1;
	if (y1 < y0) sy = -1;
	else sy=1;
	//
	int p, temp, ch;
	ch = 0;
	if (dy > dx) {
		temp = dx;
		dx = dy;
		dy = temp;
		ch = 1;
	}
	p = (2 * dy) - dx;
	while (x < x1) {
		if (p <= 0) {
			if (ch)
				y += sy;
			else
				x += sx;
			p += 2 * dy;
		}
		else {
			y += sy;
			x += sx;
			p += (2 * dy) - (2 * dx);
		}
		img_pix_put(img, x, y, color);
	}
}

// ! using the bigger delta
// find_color(color, delta)
// * finds color as a percentage of current point
/* static int	find_color(int *color, int *delta)
{
	int	percent;
	// find %
	if (abs(dx) > abs(dy))
	{

	}
	//
	int r, g, b;

} */
