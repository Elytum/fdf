/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include <sys/types.h>

typedef struct	s_vec
{
	float		x;
	float		y;
	float		z;
	float		p;
	char		color[3];
	float		pos[2];
}				t_vec;

typedef struct	s_point3
{
	float	x;
	float	y;
	float	z;
}				t_point3;

t_point3		new_point3(float x, float y, float z);
t_point3		vec_normalize(t_point3 vec);
t_point3		vec_rev_sign(t_point3 vec);

#endif
