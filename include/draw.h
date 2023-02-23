/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:16:22 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 00:07:01 by sabdelra         ###   ########.fr       */
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
// * color gradient
enum COLOR {
	r,
	g,
	b
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
	t_img	img;
	t_map	*map;
	char	*map_path;
	t_view_controls vc;
}	t_fdf;

void	img_pix_put(t_img *img, int x, int y, int color);
void	bresenham(t_img *img, t_point *p0, t_point *p1);
void	render_img(t_fdf *fdf, t_map *map);

#endif
