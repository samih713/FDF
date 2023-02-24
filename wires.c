/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wires.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 05:10:01 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 04:43:33 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// * function to draw the lines

#include "fdf.h"

static int	find_color(int *c_point, t_point *p0, t_point *p1);
static int	load_color(int s, int e, float p);
static int	switch_points(t_point *p0, t_point *p1, int *delta, int *inc);

void	bresenham(t_img *img, t_point *p0, t_point *p1)
{
	int	cp[2];
	int	delta[2];
	int	inc[2];
	int	p;
	int	ch;

	cp[x] = p0->p_2dv[u];
	cp[y] = p0->p_2dv[v];
	ch = switch_points(p0, p1, delta, inc);
	p = (2 * delta[y]) - delta[x];
	while (cp[x] < p1->p_2dv[u])
	{
		if (p <= 0)
		{
			if (ch)
				cp[y] += inc[y];
			else
				cp[x] += inc[x];
			p += 2 * delta[y];
		}
		else
		{
			cp[y] += inc[y];
			cp[x] += inc[x];
			p += (2 * delta[y]) - (2 * delta[x]);
		}
		img_pix_put(img, cp[x], cp[y], find_color(cp, p0, p1));
	}
}

static int	switch_points(t_point *p0, t_point *p1, int *delta, int *inc)
{
	int temp;
	int ch;

	delta[x] = abs(p1->p_2dv[u] - p0->p_2dv[u]);
	delta[y] = abs(p1->p_2dv[v] - p0->p_2dv[v]);
	if (p1->p_2dv[u] < p0->p_2dv[u])
		inc[x] = -1;
	else
		inc[x] = 1;
	if (p1->p_2dv[v] < p0->p_2dv[v])
		inc[y] = -1;
	else
		inc[y] = 1;
	ch = 0;
	if (delta[y] > delta[x])
	{
		temp = delta[x];
		delta[x] = delta[y];
		delta[y] = temp;
		ch = 1;
	}
	return (ch);
}

// * finds color as a percentage of current point
static int	find_color(int *c_point, t_point *p0, t_point *p1)
{
	double	range;
	int		start_col;
	int		end_col;
	int		cur_col[3];
	float	p; //position of the point as a percentage

	if (p0->color == p1->color)
		return (p0->color);
	if (c_point[x] > p0->p_2dv[u])
	{
		range = p1->p_2dv[u] - p0->p_2dv[u];
		p = (float)(c_point[x] - p0->p_2dv[u]) / (float)range;
		start_col = p0->color;
		end_col = p1->color;
	}
	else
	{
		range = p0->p_2dv[u] - p1->p_2dv[u];
		p = (float)(c_point[x] - p1->p_2dv[u]) / (float)range;
		start_col = p1->color;
		end_col = p0->color;
	}
	cur_col[r] = load_color((start_col >> 16) & 0xFF, (end_col >> 16) & 0xFF, p);
	cur_col[g] = load_color((start_col >> 8) & 0xFF, (end_col >> 8) & 0xFF, p);
	cur_col[b] = load_color((start_col & 0xFF), (end_col & 0xFF), p);
	return ((cur_col[r] << 16) | (cur_col[g] << 8) | cur_col[b]);
}

static int	load_color(int s, int e, float p)
{
	return (((1 - p) * s) + (p * e));
}
