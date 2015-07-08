/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by achazal           #+#    #+#             */
/*   Updated: 2015/02/20 12:52:13 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrices.h>
#include <libft.h>

void				matrix_identity(float *m)
{
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = 1;
	m[6] = 0;
	m[7] = 0;
	m[8] = 0;
	m[9] = 0;
	m[10] = 1;
	m[11] = 0;
	m[12] = 0;
	m[13] = 0;
	m[14] = 0;
	m[15] = 1;
}

void				matrix_inverse(float *matrix)
{
	float			tmp[16];
	int				i;
	int				j;

	i = 0;
	ft_memcpy(tmp, matrix, sizeof(float) * 16);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			matrix[i * 4 + j] = tmp[i + j * 4];
			j++;
		}
		i++;
	}
}

void				matrix_copy(float *dst, float *src)
{
	dst[0] = src[0];
	dst[1] = src[1];
	dst[2] = src[2];
	dst[3] = src[3];
	dst[4] = src[4];
	dst[5] = src[5];
	dst[6] = src[6];
	dst[7] = src[7];
	dst[8] = src[8];
	dst[9] = src[9];
	dst[10] = src[10];
	dst[11] = src[11];
	dst[12] = src[12];
	dst[13] = src[13];
	dst[14] = src[14];
	dst[15] = src[15];
}

float				*matrix_combine(float *dst, float *s)
{
	static float	t[16];

	t[0] = dst[0] * s[0] + dst[4] * s[1] + dst[8] * s[2] + dst[12] * s[3];
	t[1] = dst[1] * s[0] + dst[5] * s[1] + dst[9] * s[2] + dst[13] * s[3];
	t[2] = dst[2] * s[0] + dst[6] * s[1] + dst[10] * s[2] + dst[14] * s[3];
	t[3] = dst[3] * s[0] + dst[7] * s[1] + dst[11] * s[2] + dst[15] * s[3];
	t[4] = dst[0] * s[4] + dst[4] * s[5] + dst[8] * s[6] + dst[12] * s[7];
	t[5] = dst[1] * s[4] + dst[5] * s[5] + dst[9] * s[6] + dst[13] * s[7];
	t[6] = dst[2] * s[4] + dst[6] * s[5] + dst[10] * s[6] + dst[14] * s[7];
	t[7] = dst[3] * s[4] + dst[7] * s[5] + dst[11] * s[6] + dst[15] * s[7];
	t[8] = dst[0] * s[8] + dst[4] * s[9] + dst[8] * s[10] + dst[12] * s[11];
	t[9] = dst[1] * s[8] + dst[5] * s[9] + dst[9] * s[10] + dst[13] * s[11];
	t[10] = dst[2] * s[8] + dst[6] * s[9] + dst[10] * s[10] + dst[14] * s[11];
	t[11] = dst[3] * s[8] + dst[7] * s[9] + dst[11] * s[10] + dst[15] * s[11];
	t[12] = dst[0] * s[12] + dst[4] * s[13] + dst[8] * s[14] + dst[12] * s[15];
	t[13] = dst[1] * s[12] + dst[5] * s[13] + dst[9] * s[14] + dst[13] * s[15];
	t[14] = dst[2] * s[12] + dst[6] * s[13] + dst[10] * s[14] + dst[14] * s[15];
	t[15] = dst[3] * s[12] + dst[7] * s[13] + dst[11] * s[14] + dst[15] * s[15];
	matrix_copy(dst, (float*)t);
	return (dst);
}

void				ft_v_x_m(float v[4], float m[16])
{
	static float	tab[4];

	tab[0] = m[0] * v[0] + m[1] * v[1] + m[2] * v[2] + m[3] * v[3];
	tab[1] = m[4] * v[0] + m[5] * v[1] + m[6] * v[2] + m[7] * v[3];
	tab[2] = m[8] * v[0] + m[9] * v[1] + m[10] * v[2] + m[11] * v[3];
	tab[3] = m[12] * v[0] + m[13] * v[1] + m[14] * v[2] + m[15] * v[3];
	v[0] = tab[0];
	v[1] = tab[1];
	v[2] = tab[2];
	v[3] = tab[3];
}
