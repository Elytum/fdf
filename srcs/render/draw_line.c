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

#include <fdf.h>
#include <vector.h>

static inline int	abs(int x)
{
	return ((x < 0) ? -x : x);
}

static inline int	ft_inscreen(t_vec *p1, t_vec *p2)
{
	if (p1->pos[0] < -500 || p1->pos[0] > WIN_WIDTH + 500 ||
		p1->pos[1] < -500 || p1->pos[1] > WIN_HEIGHT + 500)
		return (0);
	if (p2->pos[0] < -500 || p2->pos[0] > WIN_WIDTH + 500 ||
		p2->pos[1] < -500 || p2->pos[1] > WIN_HEIGHT + 500)
		return (0);
	if (p1->pos[0] != p1->pos[0] || p2->pos[0] != p2->pos[0])
		return (0);
	return (1);
}

static inline void	drawing_loop(t_env *e, int tab[4], int tools[6])
{
	while (42)
	{
		ft_put_pixel(e, tab[0], tab[2], e->color);
		if (tab[0] == tab[1] && tab[2] == tab[3])
			break ;
		tools[5] = tools[4];
		if (tools[5] > -tools[0])
		{
			tools[4] -= tools[2];
			tab[0] += tools[1];
		}
		if (tools[5] < tools[2])
		{
			tools[4] += tools[0];
			tab[2] += tools[3];
		}
	}
}

void				ft_drawline(t_vec *p1, t_vec *p2, t_env *e)
{
	static int		tab[4];
	static int		tools[6];

	if (!(ft_inscreen(p1, p2)))
		return ;
	tab[0] = (int)p1->pos[0];
	tab[1] = (int)p2->pos[0];
	tab[2] = (int)p1->pos[1];
	tab[3] = (int)p2->pos[1];
	tools[0] = abs(tab[1] - tab[0]);
	tools[1] = tab[0] < tab[1] ? 1 : -1;
	tools[2] = abs(tab[3] - tab[2]);
	tools[3] = tab[2] < tab[3] ? 1 : -1;
	tools[4] = (tools[0] > tools[2] ? tools[0] : -tools[2]) / 2;
	e->color[0] = (p1->color[0] + p2->color[0]) / 2;
	e->color[1] = (p1->color[1] + p2->color[1]) / 2;
	e->color[2] = (p1->color[2] + p2->color[2]) / 2;
	drawing_loop(e, tab, tools);
}
