/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:56:03 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 21:46:27 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_no_event(void)
{
	return (0);
}

int	handle_keypress(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		close_window(fdf);
	else if (keysym == XK_Up || keysym == XK_Down)
	{
		if (keysym == XK_Up && fdf->vc.zoom == MAX_ZOOM)
			return (0);
		else if (keysym == XK_Down && fdf->vc.zoom == MIN_ZOOM)
			return (0);
		zoom(keysym, fdf);
	}
	if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d)
		move(keysym, fdf);
	return (EVENT_ERR);
}

int	handle_keyrelease(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Up || keysym == XK_Down)
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->img.mlx_img);
		fdf->img.mlx_img = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		fdf->img.addr = mlx_get_data_addr(fdf->img.mlx_img, &fdf->img.bpp,
				&fdf->img.line_len, &fdf->img.endian);
		mem_check(fdf->img.mlx_img);
		apply_zoom(fdf->map, fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
			fdf->img.mlx_img, 0, 0);
		return (0);
	}
	if (keysym == XK_w || keysym == XK_a || keysym == XK_s || keysym == XK_d)
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->img.mlx_img);
		fdf->img.mlx_img = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		fdf->img.addr = mlx_get_data_addr(fdf->img.mlx_img, &fdf->img.bpp,
				&fdf->img.line_len, &fdf->img.endian);
		mem_check(fdf->img.mlx_img);
		move_projection(fdf->map, fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr,
			fdf->img.mlx_img, 0, 0);
		return (0);
	}
	return (EVENT_ERR);
}

int	close_window(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.mlx_img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->map->p);
	free(fdf->map);
	free(fdf->mlx_ptr);
	exit(EXIT_SUCCESS);
}

int	zoom(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Up && fdf->vc.zoom < MAX_ZOOM)
		fdf->vc.zoom += 1;
	else if (keysym == XK_Down && fdf->vc.zoom > MIN_ZOOM)
		fdf->vc.zoom -= 1;
	return (0);
}

int	move(int keysym, t_fdf *fdf)
{
	if (keysym == XK_w && fdf->vc.y_offset < WIN_HEIGHT)
		fdf->vc.y_offset += 10;
	else if (keysym == XK_s && fdf->vc.y_offset > (-1 * (WIN_HEIGHT)))
		fdf->vc.y_offset -= 10;
	else if (keysym == XK_a && fdf->vc.x_offset < WIN_WIDTH)
		fdf->vc.x_offset += 10;
	else if (keysym == XK_d && fdf->vc.x_offset > (-1 * WIN_WIDTH))
		fdf->vc.x_offset -= 10;
	return (0);
}
