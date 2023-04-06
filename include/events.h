/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:55:45 by sabdelra          #+#    #+#             */
/*   Updated: 2023/04/06 06:17:54 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fdf.h"

# define EVENT_ERR 3

# define XK_Escape			53

//* zoom controls
# define XK_Up				126
# define XK_Down			125

//* movement controls
# define XK_w				13
# define XK_a				0
# define XK_s				1
# define XK_d				2

//* rotation controls
# define XK_u				32
# define XK_h				4
# define XK_j				38
# define XK_k				40

//* isometric
# define XK_i				34
//! parrallel
# define XK_p				35

//! elevation
# define XK_t				17
# define XK_g				5

//* recreate image functions
typedef void (*f)(t_map *map, t_fdf *fdf);

int	handle_no_event(void);
int	handle_keypress(int keysym, t_fdf *fdf);
int	handle_keyrelease(int keysym, t_fdf *fdf);

//* Events
int		close_window(t_fdf *fdf);
int		zoom(int keysym, t_fdf *fdf);
int		move(int keysym, t_fdf *fdf);
int		rotate(int keysym, t_fdf *fdf);
void	recreate_image(t_fdf *fdf, f);
void	reset_rotation(t_fdf *fdf);
int	elevation(t_fdf *fdf);

#endif
