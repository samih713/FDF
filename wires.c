/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wires.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 05:10:01 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/15 16:55:28 by sabdelra         ###   ########.fr       */
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
	while (x < x1)
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

void bresenham(int x0, int x1, int y0, int y1, void *mlx_ptr, void *win_ptr, int color) {

  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
  int err = (dx>dy ? dx : -dy)/2, e2;

  for(;;){
    mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, color);
    if (x0==x1 && y0==y1) break;
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }
}
