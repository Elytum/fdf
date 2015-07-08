/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by achazal           #+#    #+#             */
/*   Updated: 2015/02/20 12:52:13 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		ft_put_pixel(t_env *e, int x, int y, char *color)
{
	int		octet;
	char	*position;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	octet = e->line_size / WIN_WIDTH;
	if (y > 0)
		y -= 1;
	position = e->data + (e->line_size * y) + (x * octet);
	*(position) = *color++;
	*(position + 1) = *color++;
	*(position + 2) = *color++;
}
