/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 03:07:20 by sabdelra          #+#    #+#             */
/*   Updated: 2023/04/06 06:41:34 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	recreate_image(t_fdf *fdf, f function)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.mlx_img);
	fdf->img.mlx_img = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	fdf->img.addr = mlx_get_data_addr(fdf->img.mlx_img, &fdf->img.bpp,
			&fdf->img.line_len, &fdf->img.endian);
	mem_check(fdf->img.mlx_img);
	function(fdf->map, fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
		fdf->img.mlx_img, 0, 0);
}

int	zoom(int ks, t_fdf *fdf)
{
	if (ks == XK_Up && fdf->vc.zoom < MAX_ZOOM)
		fdf->vc.zoom += 1;
	else if (ks == XK_Down && fdf->vc.zoom > MIN_ZOOM)
		fdf->vc.zoom -= 1;
	return (0);
}

void	reset_rotation(t_fdf *fdf)
{
	fdf->vc.angle.a = 0;
	fdf->vc.angle.b = 0;
	fdf->vc.angle.g = 0;
	recreate_image(fdf, apply_zoom);
}

int	rotate(int ks, t_fdf *fdf)
{
	if (ks == XK_u)
		fdf->vc.angle.a += (5 * (M_PI / 180));
	if (ks == XK_j)
		fdf->vc.angle.a -= (5 * (M_PI / 180));
	if (ks == XK_k)
		fdf->vc.angle.b += (5 * (M_PI / 180));
	if (ks == XK_h)
		fdf->vc.angle.b -= (5 * (M_PI / 180));
	return (0);
}

int	move(int ks, t_fdf *fdf)
{
	if (ks == XK_w && fdf->vc.y_offset < WIN_HEIGHT)
		fdf->vc.y_offset += 10;
	else if (ks == XK_s && fdf->vc.y_offset > (-1 * (WIN_HEIGHT)))
		fdf->vc.y_offset -= 10;
	else if (ks == XK_a && fdf->vc.x_offset < WIN_WIDTH)
		fdf->vc.x_offset += 10;
	else if (ks == XK_d && fdf->vc.x_offset > (-1 * WIN_WIDTH))
		fdf->vc.x_offset -= 10;
	return (0);
}
