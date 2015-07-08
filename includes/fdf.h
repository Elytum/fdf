/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 04:07:02 by achazal           #+#    #+#             */
/*   Updated: 2015/05/03 04:07:04 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <vector.h>
# include <math.h>

# define TO_DEGREE(x) ((int)(180 * x / M_PI) % 360)
# define TO_RADIAN(x) (x / 180.0f * M_PI)

# define LEFT_MOVE 0b10000000
# define RIGHT_MOVE 0b01000000
# define UP_MOVE 0b00100000
# define DOWN_MOVE 0b00010000
# define FORWARD_MOVE 0b00001000
# define BACKWARD_MOVE 0b00000100

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				line_size;
	int				endian;
	t_vec			***map;
	float			mp[3];
	float			mr[3];
	float			ms[3];
	float			pitch;
	float			roll;
	float			yaw;
	float			cp[3];
	float			fov;
	float			near;
	float			far;
	float			aspect;
	float			proj[16];
	float			view[16];
	float			transf[16];
	float			total[16];
	char			color[3];
	char			moves;
	float			xdir;
	float			ydir;
	float			xrot;
	float			yrot;
	float			zrot;
}					t_env;

# define WIN_WIDTH 1200
# define WIN_HEIGHT 800
# define WIN_NAME "FDF"

void				play_fdf(t_vec ***map);
void				ft_put_pixel(t_env *e, int x, int y, char *color);
void				ft_drawline(t_vec *p1, t_vec *p2, t_env *e);
void				draw_map(t_env *e);

#endif
