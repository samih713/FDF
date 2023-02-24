/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 20:16:22 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 16:12:11 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "fdf.h"

void	img_pix_put(t_img *img, int x, int y, int color);
void	bresenham(t_img *img, t_point *p0, t_point *p1);
void	render_img(t_fdf *fdf, t_map *map);

#endif
