/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include <fdf.h>

# define SPEED 2
# define KEYPRESSMASK				(1L << 0)
# define KEYRELEASEMASK				(1L << 1)
# define KEYPRESS					2
# define KEYRELEASE					3
# define POINTERMOTIONMASK			(1L << 6)
# define MOTIONNOTIFY				6
# define KEY_0 82
# define KEY_1 83
# define KEY_2 84
# define KEY_3 85
# define KEY_4 86
# define KEY_5 87
# define KEY_6 88
# define KEY_7 89
# define KEY_8 91
# define KEY_9 92
# define KEY_PAGE_UP 116
# define KEY_PAGE_DOWN 121
# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_T 17
# define KEY_Y 16
# define KEY_U 32
# define KEY_G 5
# define KEY_H 4
# define KEY_J 38
# define KEY_B 11
# define KEY_N 45
# define KEY_M 46
# define KEY_CLEAR 71

# define FIELD 200
# define RATIO 1 / 100.f

int		key_press(int keycode, t_env *e);
int		key_press_extra(int keycode, t_env *e);
int		key_release(int keycode, t_env *e);
int		mouse_hook(int x, int y, t_env *e);

#endif
