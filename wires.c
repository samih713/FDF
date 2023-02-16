/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wires.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 05:10:01 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/16 16:08:10 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function to draw the lines */

#include "fdf.h"

/* void bresenham(int x0, int x1, int y0, int y1, void *mlx_ptr, void *win_ptr, int color)
{
	int dx;
	int dy;
	int p;
	int x;
	int y;

	x = x0;
	y = y0;
	dx = x1 - x0;
	dy = y1 - y0;

	p = 2 * (dy - dx); // error
	while (x <= x1)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		if (p >= 0)
		{
			if (y0 < y1)
				y++;
			else
				y--;
			p = p + (2 * dy) - (2 * dx);
		}
		else
			p = p + (2 * dy);
		x++;
	}
} */

void bresenham(int x0, int x1, int y0, int y1, void *mlx_ptr, void *win_ptr, int color)
{
	int x, y;
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
	p = 2 * (dy - dx);
	while (x <= x1) {
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
		if (p < 0) {
			if (ch == 1)
				y += sy;
			else
				x += sx;
			p += 2 * 2 * dy;
		}
		else {
			y += sy;
			x += sx;
			p += (2 * dy) - (2 * dx);
		}
	}
}
