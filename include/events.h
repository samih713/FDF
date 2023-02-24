/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:55:45 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/24 17:33:45 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fdf.h"

# define EVENT_ERR 3

int	handle_no_event(void);
int	handle_keypress(int keysym, t_fdf *fdf);
int	handle_keyrelease(int keysym, t_fdf *fdf);

// * Events
int	close_window(t_fdf *fdf);
int	zoom(int keysym, t_fdf *fdf);
int	move(int keysym, t_fdf *fdf);

#endif
