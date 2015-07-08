/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_hooks.c                                      :+:      :+:    :+:   */
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

int		key_press_extra(int keycode, t_env *e)
{
	if (keycode == KEY_CLEAR)
	{
		e->mp[0] = 0;
		e->mp[1] = 0;
		e->mp[2] = 0;
		e->mr[0] = 0;
		e->mr[1] = 0;
		e->mr[2] = 0;
		e->ms[0] = 1;
		e->ms[1] = .025;
		e->ms[2] = 1;
	}
	else if (keycode == KEY_0)
	{
		e->xrot = 0;
		e->yrot = 0;
		e->zrot = 0;
	}
	return (0);
}
