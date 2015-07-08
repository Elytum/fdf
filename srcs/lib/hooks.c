/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by achazal           #+#    #+#             */
/*   Updated: 2015/02/20 12:52:13 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <events.h>
#include <moves.h>
#include <lib.h>

static inline void	key_press_scale(int keycode, t_env *e)
{
	if (keycode == KEY_T)
		e->ms[0] *= 1.05;
	else if (keycode == KEY_Y)
		e->ms[0] /= 1.05;
	else if (keycode == KEY_U)
		e->ms[0] = 1;
	else if (keycode == KEY_G)
		e->ms[1] *= 1.05;
	else if (keycode == KEY_H)
		e->ms[1] /= 1.05;
	else if (keycode == KEY_J)
		e->ms[1] = 1;
	else if (keycode == KEY_B)
		e->ms[2] *= 1.05;
	else if (keycode == KEY_N)
		e->ms[2] /= 1.05;
	else if (keycode == KEY_M)
		e->ms[2] = 1;
	else
		key_press_extra(keycode, e);
}

static inline void	key_press_rotations(int keycode, t_env *e)
{
	if (keycode == KEY_1)
		e->xrot = 0;
	else if (keycode == KEY_2)
		e->xrot += .005;
	else if (keycode == KEY_3)
		e->xrot -= .005;
	else if (keycode == KEY_4)
		e->yrot = 0;
	else if (keycode == KEY_5)
		e->yrot += .005;
	else if (keycode == KEY_6)
		e->yrot -= .005;
	else if (keycode == KEY_7)
		e->zrot = 0;
	else if (keycode == KEY_8)
		e->zrot += .005;
	else if (keycode == KEY_9)
		e->zrot -= .005;
	else
		key_press_scale(keycode, e);
}

int					key_press(int keycode, t_env *e)
{
	if (keycode == KEY_W)
		e->moves |= FORWARD_MOVE;
	else if (keycode == KEY_S)
		e->moves |= BACKWARD_MOVE;
	else if (keycode == KEY_A)
		e->moves |= LEFT_MOVE;
	else if (keycode == KEY_D)
		e->moves |= RIGHT_MOVE;
	else if (keycode == KEY_PAGE_UP)
		e->moves |= UP_MOVE;
	else if (keycode == KEY_PAGE_DOWN)
		e->moves |= DOWN_MOVE;
	else if (keycode == KEY_UP)
		e->pitch += .05;
	else if (keycode == KEY_DOWN)
		e->pitch -= .05;
	else if (keycode == KEY_LEFT)
		e->yaw += .05;
	else if (keycode == KEY_RIGHT)
		e->yaw -= .05;
	else if (keycode == 53)
		put_exit(1, "Echap pressed\n", 0);
	else
		key_press_rotations(keycode, e);
	return (0);
}

int					key_release(int keycode, t_env *e)
{
	if (keycode == KEY_W)
		e->moves &= ~FORWARD_MOVE;
	else if (keycode == KEY_S)
		e->moves &= ~BACKWARD_MOVE;
	else if (keycode == KEY_A)
		e->moves &= ~LEFT_MOVE;
	else if (keycode == KEY_D)
		e->moves &= ~RIGHT_MOVE;
	else if (keycode == KEY_PAGE_UP)
		e->moves &= ~UP_MOVE;
	else if (keycode == KEY_PAGE_DOWN)
		e->moves &= ~DOWN_MOVE;
	return (0);
}

int					mouse_hook(int x, int y, t_env *e)
{
	static int		oldx = 0;
	static int		oldy = 0;

	if (oldy != y)
	{
		e->pitch -= (y - oldy) * RATIO;
		oldy = y;
	}
	if (oldx != x)
	{
		e->yaw -= (x - oldx) * RATIO;
		oldx = x;
	}
	return (0);
}
