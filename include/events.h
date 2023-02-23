/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabdelra <sabdelra@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:55:45 by sabdelra          #+#    #+#             */
/*   Updated: 2023/02/23 22:12:17 by sabdelra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
#define EVENTS_H

#include "fdf.h"

int	handle_no_event(void *data);
int	handle_keypress(int keysym, t_fdf *fdf);
int	handle_keyrelease(int keysym, t_fdf *fdf);

// *
int	close_window(t_fdf *fdf);
int zoom(int keysym, t_fdf *fdf);

#endif
