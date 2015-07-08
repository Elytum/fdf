/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 17:20:50 by achazal           #+#    #+#             */
/*   Updated: 2015/01/17 17:20:52 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>
#include <libft.h>
#include <matrices.h>

static inline void	calculate_on_vector(t_env *e, t_vec *ptr)
{
	static float	tmp[4];

	tmp[0] = ptr->x;
	tmp[1] = ptr->y;
	tmp[2] = ptr->z;
	tmp[3] = ptr->p;
	ft_v_x_m(tmp, e->total);
	if (tmp[3] > 0)
	{
		tmp[0] /= tmp[3];
		tmp[1] /= tmp[3];
		ptr->pos[0] = (tmp[0] + .5) * WIN_WIDTH;
		ptr->pos[1] = (tmp[1] + .5) * WIN_HEIGHT;
	}
	else
	{
		ptr->pos[0] = 0.0 / 0.0;
		ptr->pos[1] = 0.0 / 0.0;
	}
}

static inline void	calcultate_position(t_env *e)
{
	t_vec			***pptr;
	t_vec			**ptr;

	pptr = e->map;
	while (*pptr)
	{
		ptr = *pptr;
		while (*ptr)
			calculate_on_vector(e, *ptr++);
		pptr++;
	}
}

void				draw_map(t_env *e)
{
	size_t			x;
	ssize_t			y;

	calculate_total(e);
	calcultate_position(e);
	y = 0;
	while (e->map[y])
	{
		x = 0;
		while (e->map[y][x])
		{
			if (x > 0)
				ft_drawline(e->map[y][x - 1], e->map[y][x], e);
			if (y > 0)
				ft_drawline(e->map[y - 1][x], e->map[y][x], e);
			++x;
		}
		++y;
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_do_sync(e->mlx);
	ft_bzero(e->data, WIN_WIDTH * WIN_HEIGHT * sizeof(char) * 4);
}
