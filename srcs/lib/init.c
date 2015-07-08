/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by achazal           #+#    #+#             */
/*   Updated: 2015/02/20 12:52:13 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>
#include <moves.h>
#include <matrices.h>
#include <events.h>
#include <libft.h>
#include <lib.h>
#include <unistd.h>
#include <stdlib.h>

static inline void	init_env_values(t_env *e)
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
	e->cp[0] = 0;
	e->cp[1] = 10;
	e->cp[2] = 0;
	e->pitch = M_PI;
	e->roll = 0;
	e->yaw = 0;
	e->fov = 70;
	e->near = 0.1f;
	e->far = 1000;
	e->aspect = WIN_WIDTH / (float)WIN_HEIGHT;
	e->moves = 0;
}

static inline int	refresh(t_env *e)
{
	e->mr[0] += e->xrot;
	e->mr[1] += e->yrot;
	e->mr[2] += e->zrot;
	refresh_moves(e);
	draw_map(e);
	return (0);
}

void				play_fdf(t_vec ***map)
{
	t_env			*e;

	if (!(e = (t_env *)ft_memalloc(sizeof(t_env))))
		put_exit(2, "Malloc error\n", 2);
	if (!(e->mlx = mlx_init()))
		put_exit(2, "Failed to initialize minilibx\n", 2);
	e->map = map;
	e->win = mlx_new_window(e->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);
	e->img = mlx_new_image(e->mlx, WIN_WIDTH, WIN_HEIGHT);
	e->data = mlx_get_data_addr(e->img, &(e->bpp),
		&(e->line_size), &(e->endian));
	init_env_values(e);
	mlx_hook(e->win, KEYPRESS, KEYPRESSMASK, key_press, e);
	mlx_hook(e->win, KEYRELEASE, KEYRELEASEMASK, key_release, e);
	mlx_hook(e->win, MOTIONNOTIFY, POINTERMOTIONMASK, mouse_hook, e);
	mlx_loop_hook(e->mlx, refresh, e);
	mlx_loop(e->mlx);
}

void				put_exit(int fd, char *str, int out)
{
	write(fd, str, ft_strlen(str));
	exit(out);
}
