/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:56:03 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 00:30:36 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* int close_window(int keycode, t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, &fdf->img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->win_ptr);
	free(fdf->mlx_ptr);
} */

int	handle_no_event(void *fdf)
{
	return (0);
}

int	handle_keypress(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Escape)
		close_window(fdf);
	else if (keysym == XK_Up || keysym == XK_Down)
	{
		zoom(keysym, fdf);
		printf("key pressed: %d\n", keysym);
	}
	return (1);
}

// * handle the situation when releasing from previously max or min zoom
int	handle_keyrelease(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Up || keysym == XK_Down)
	{
		mlx_destroy_image(fdf->mlx_ptr, fdf->img.mlx_img);
		free(fdf->map->p);
		free(fdf->map);
		fdf->img.mlx_img = mlx_new_image(fdf->mlx_ptr,WIN_WIDTH ,WIN_HEIGHT);
		mem_check(fdf->img.mlx_img);
		fdf->map = load_map(fdf->map_path, &fdf->vc);
		render_img(fdf, fdf->map);
		mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.mlx_img, 0, 0);
		return (0);
	}
	else
		return (1);
}

int	close_window(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img.mlx_img);
	mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	mlx_destroy_display(fdf->mlx_ptr);
	free(fdf->map->p);
	free(fdf->map);
	free(fdf->mlx_ptr);
	exit(0);
}

int zoom(int keysym, t_fdf *fdf)
{
	if (keysym == XK_Up && fdf->vc.zoom < MAX_ZOOM)
	{
		fdf->vc.zoom += 1;
		printf("zoom is %d\n", fdf->vc.zoom);
	}
	else if (keysym == XK_Down && fdf->vc.zoom > MIN_ZOOM)
	{
		fdf->vc.zoom -= 1;
		printf("zoom is %d\n", fdf->vc.zoom);
	}
	return (0);
}
