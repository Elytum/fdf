/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by achazal           #+#    #+#             */
/*   Updated: 2015/02/20 12:52:13 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <events.h>

static inline void	ft_move(t_env *e, float x, float y, float z)
{
	if (x)
	{
		e->cp[0] += (-cos(e->yaw) * SPEED) * x;
		e->cp[1] += 0;
		e->cp[2] += (-sin(e->yaw) * SPEED) * x;
	}
	if (y)
		e->cp[1] += SPEED * y;
	if (z)
	{
		e->cp[0] += (cos(e->pitch) * sin(e->yaw)) * z * SPEED;
		e->cp[1] += -(sin(e->pitch)) * z * SPEED;
		e->cp[2] += -(cos(e->pitch) * cos(e->yaw)) * z * SPEED;
	}
}

void				refresh_moves(t_env *e)
{
	if (e->moves & FORWARD_MOVE)
		ft_move(e, 0, 0, 1);
	if (e->moves & BACKWARD_MOVE)
		ft_move(e, 0, 0, -1);
	if (e->moves & LEFT_MOVE)
		ft_move(e, 1, 0, 0);
	if (e->moves & RIGHT_MOVE)
		ft_move(e, -1, 0, 0);
	if (e->moves & UP_MOVE)
		ft_move(e, 0, 1, 0);
	if (e->moves & DOWN_MOVE)
		ft_move(e, 0, -1, 0);
}
