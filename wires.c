/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wires.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 05:10:01 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/23 00:53:04 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* function to draw the lines */

#include "fdf.h"
// TODO reduce function arguments and function size
// TODO color start end point maybe flipped maybe with ch variable
// TODO change this to accept point
static int	find_color(int *c_point, m_point *p0, m_point *p1);
static int	load_color(int s, int e, float p);

void	bresenham(t_img *img, m_point *p0, m_point *p1)
{
	int cp[2];
	int d[2];
	int s[2];
	int cc;
	int p, temp, ch;

	cp[x] = p0->p_2dv[u];
	cp[y] = p0->p_2dv[v];
	d[x] = abs(p1->p_2dv[u] - p0->p_2dv[u]);
	d[y] = abs(p1->p_2dv[v] - p0->p_2dv[v]);
	if (p1->p_2dv[u] < p0->p_2dv[u])
		s[x] = -1;
	else
		s[x]=1;
	if (p1->p_2dv[v] < p0->p_2dv[v])
		s[y] = -1;
	else
		s[y]=1;
	ch = 0;
	if (d[y] > d[x])
	{
		temp = d[x];
		d[x] = d[y];
		d[y] = temp;
		ch = 1;
	}
	p = (2 * d[y]) - d[x];
	while (cp[x] < p1->p_2dv[u])
	{
		if (p <= 0)
		{
			if (ch)
				cp[y] += s[y];
			else
				cp[x] += s[x];
			p += 2 * d[y];
		}
		else
		{
			cp[y] += s[y];
			cp[x] += s[x];
			p += (2 * d[y]) - (2 * d[x]);
		}
		cc = find_color(cp, p0, p1);
		img_pix_put(img, cp[x], cp[y], cc);
	}
}

// ! using the bigger delta
// find_color(color, delta)
// * finds color as a percentage of current point
// TODO optimize by skipping if its the start point or end point
static int	find_color(int *c_point, m_point *p0, m_point *p1)
{
	double	range;
	int	sc;
	int	ec;
	int	cc[3];
	float	p; //position of the point as a percentage

	if (p0->color == p1->color)
		return(p0->color);
	if (c_point[x] > p0->p_2dv[u])
	{
		range = p1->p_2dv[u] - p0->p_2dv[u];
		p = (float)(c_point[x] - p0->p_2dv[u]) / (float)range;
		sc = p0->color;
		ec = p1->color;
	}
	else
	{
		range = p0->p_2dv[u] - p1->p_2dv[u];
		p = (float)(c_point[x] - p1->p_2dv[u]) / (float)range;
		sc = p1->color;
		ec = p0->color;
	}
	cc[red] = load_color((sc >> 16) & 0xFF, (ec >> 16) & 0xFF, p);
	cc[green] = load_color((sc >> 8) & 0xFF, (ec >> 8) & 0xFF, p);
	cc[blue] = load_color((sc & 0xFF), (ec & 0xFF), p);
	return((cc[red] << 16) | (cc[green] << 8) | cc[blue]);
}

static int	load_color(int s, int e, float p)
{
	return (((1 - p) * s) + (p * e));
}
