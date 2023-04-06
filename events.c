/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:56:03 by sabdelra          #+#    #+#             */
/*   Updated: 2023/04/06 06:42:50 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void)
{
	return (0);
}

int	handle_keypress(int ks, t_fdf *fdf)
{
	if (ks == XK_Escape)
		close_window(fdf);
	else if (ks == XK_u || ks == XK_h || ks == XK_j || ks == XK_k)
		rotate(ks, fdf);
	else if (ks == XK_Up || ks == XK_Down)
	{
		if (ks == XK_Up && fdf->vc.zoom == MAX_ZOOM)
			return (0);
		else if (ks == XK_Down && fdf->vc.zoom == MIN_ZOOM)
			return (0);
		zoom(ks, fdf);
	}
	else if (ks == XK_w || ks == XK_a || ks == XK_s || ks == XK_d)
		move(ks, fdf);
	else if (ks == XK_i)
		reset_rotation(fdf);
	return (EVENT_ERR);
}

int	handle_keyrelease(int ks, t_fdf *fdf)
{
	if (ks == XK_Up || ks == XK_Down)
	{
		recreate_image(fdf, apply_zoom);
		return (0);
	}
	else if (ks == XK_w || ks == XK_a || ks == XK_s || ks == XK_d)
	{
		recreate_image(fdf, move_projection);
		return (0);
	}
	else if (ks == XK_u || ks == XK_h || ks == XK_j || ks == XK_k)
	{
		recreate_image(fdf, apply_zoom);
		return (0);
	}
	return (EVENT_ERR);
}

int	close_window(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.mlx_img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	free(fdf->map->p);
	free(fdf->map);
	free(fdf->mlx_ptr);
	exit(EXIT_SUCCESS);
}
