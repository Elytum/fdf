/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRICES_H
# define MATRICES_H

# include <fdf.h>
# include <vector.h>

void	matrix_rotate(float *m, t_point3 axis, float angle);
void	matrix_scale(float *m, float x, float y, float z);
void	matrix_translate(float *m, float x, float y, float z);
void	matrix_identity(float *m);
void	matrix_inverse(float *matrix);

void	matrix_copy(float *dst, float *src);
float	*matrix_combine(float *dst, float *s);
void	ft_v_x_m(float v[4], float m[16]);
void	calculate_total(t_env *e);

#endif
