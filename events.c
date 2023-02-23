/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:56:03 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 01:27:15 by sabdelra         ###   ########.fr       */
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
	return (EVENT_ERR);
}

int	handle_keyrelease(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Up || keysym == XK_Down)
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->img.mlx_img);
		free(fdf->map->p);
		free(fdf->map);
		fdf->img.mlx_img = mlx_new_image(fdf->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
		mem_check(fdf->img.mlx_img);
		fdf->map = load_map(fdf->map_path, &fdf->vc);
		render_img(fdf, fdf->map);
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
