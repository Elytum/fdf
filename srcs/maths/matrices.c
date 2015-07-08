/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <matrices.h>

static inline void	calculate_transformation(t_env *e)
{
	matrix_identity(e->transf);
	matrix_translate(e->transf, e->mp[0], e->mp[1], e->mp[2]);
	matrix_rotate(e->transf, new_point3(1, 0, 0), e->mr[0]);
	matrix_rotate(e->transf, new_point3(0, 1, 0), e->mr[1]);
	matrix_rotate(e->transf, new_point3(0, 0, 1), e->mr[2]);
	matrix_scale(e->transf, e->ms[0], e->ms[1], e->ms[2]);
}

static inline void	calculate_view(t_env *e)
{
	t_point3		rev;

	matrix_identity(e->view);
	matrix_rotate(e->view, new_point3(1, 0, 0), e->pitch);
	matrix_rotate(e->view, new_point3(0, 1, 0), e->yaw);
	matrix_rotate(e->view, new_point3(0, 0, 1), e->roll);
	rev = new_point3(e->cp[0], e->cp[1], e->cp[2]);
	rev = vec_rev_sign(rev);
	matrix_translate(e->view, rev.x, rev.y, rev.z);
}

static inline void	calculate_projection(t_env *e)
{
	float			x_scale;
	float			y_scale;
	float			frustrum;

	matrix_identity(e->proj);
	y_scale = (float)((1.0f / tan(TO_RADIAN(e->fov / 2.0f))) * e->aspect);
	x_scale = y_scale / e->aspect;
	frustrum = e->far - e->near;
	e->proj[0] = x_scale;
	e->proj[5] = y_scale;
	e->proj[10] = -((e->far + e->near) / frustrum);
	e->proj[11] = -((2 * e->near * e->far) / frustrum);
	e->proj[14] = -1;
	e->proj[15] = 0;
}

void				calculate_total(t_env *e)
{
	calculate_transformation(e);
	calculate_view(e);
	calculate_projection(e);
	matrix_copy(e->total, e->transf);
	matrix_combine(e->total, e->view);
	matrix_combine(e->total, e->proj);
}
