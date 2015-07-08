/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by achazal           #+#    #+#             */
/*   Updated: 2015/02/20 12:52:13 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector.h>
#include <math.h>

t_point3		new_point3(float x, float y, float z)
{
	t_point3	p;

	p.x = x;
	p.y = y;
	p.z = z;
	return (p);
}

static double	vec_norm(t_point3 vec)
{
	return (sqrt(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z));
}

t_point3		vec_normalize(t_point3 vec)
{
	t_point3	normalized;
	double		norm;

	norm = vec_norm(vec);
	if (norm == 0)
		norm = 0.0001f;
	normalized.x = vec.x / norm;
	normalized.y = vec.y / norm;
	normalized.z = vec.z / norm;
	return (normalized);
}

t_point3		vec_rev_sign(t_point3 vec)
{
	return (new_point3(-vec.x, -vec.y, -vec.z));
}
