/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:16:22 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/19 21:41:14 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
#define DRAW_H

#include "fdf.h"

enum POINTS
{
	x_nxt = 2,
	y_nxt,
	x_abv,
	y_abv
};
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_fdf
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	*img;
}	t_fdf;

void	img_pix_put(t_img *img, int x, int y, int color);
void	bresenham(t_img *img, int x0, int x1, int y0, int y1, int color);
void	render_img(t_fdf *fdf, t_map *map);

#endif
