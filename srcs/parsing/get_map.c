/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by achazal           #+#    #+#             */
/*   Updated: 2015/02/20 12:52:13 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
#include <lib.h>
#include <libft.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static inline void	set_color(t_vec *ptr)
{
	int				v;
	int				color;

	v = (int)ptr->y;
	if (v < -10)
		color = 0x000080;
	else if (v < -5)
		color = 0x2389DA;
	else if (v < 0)
		color = 0x00B2FF;
	else if (v < 2)
		color = 0xAD987A;
	else if (v < 10)
		color = 0x006400;
	else if (v < 15)
		color = 0x03C03C;
	else if (v < 30)
		color = 0x663300;
	else if (v < 100)
		color = 0x543D37;
	else
		color = 0xFFFFFF;
	ptr->color[0] = color & 0x0000FF;
	ptr->color[1] = (color & 0x00FF00) >> 8;
	ptr->color[2] = (color & 0xFF0000) >> 16;
}

static inline void	set_pixel(t_vec *ptr, float x, float y, float z)
{
	ptr->x = x;
	ptr->y = z;
	ptr->z = y;
	ptr->p = 1;
	set_color(ptr);
	ptr->y = -ptr->y;
}

static inline t_vec	**get_line(char *str, size_t xmax, size_t ymax, size_t ypos)
{
	t_vec			**line;
	t_vec			**ptr;
	size_t			xpos;

	if (!(line = (t_vec **)malloc(sizeof(t_vec *) * (xmax + 1))))
		put_exit(2, "Malloc error\n", 2);
	ptr = line;
	while (*str == ' ' || *str == '\t')
		str++;
	xpos = 0;
	while (xpos < xmax)
	{
		if (ptr == NULL)
			put_exit(2, "There is a line too small\n", 2);
		if (!(ptr[xpos] = (t_vec *)malloc(sizeof(t_vec))))
			put_exit(2, "Malloc error\n", 2);
		set_pixel(ptr[xpos], (float)xpos - (float)xmax / 2,
			(float)ypos - (float)ymax / 2, ft_matod(&str));
		++xpos;
	}
	if (*str)
		put_exit(2, "There is a line too long\n", 2);
	ptr[xpos] = NULL;
	return (line);
}

static inline t_vec	***load_map(char *path, size_t xmax, size_t ymax)
{
	char			*line;
	t_vec			***map;
	t_vec			***ptr;
	int				fd;
	size_t			ypos;

	if ((fd = open(path, O_RDONLY)) <= 0)
		put_exit(2, "Error opening file\n", 2);
	if (!(map = (t_vec ***)malloc(sizeof(t_vec **) * (ymax + 1))))
		put_exit(2, "Malloc error\n", 2);
	ypos = 0;
	ptr = map;
	while (ypos < ymax)
	{
		if (get_next_line(fd, &line) != 1)
			put_exit(2, "The file changed during execution\n", 2);
		ptr[ypos] = get_line(line, xmax, ymax, ypos);
		free(line);
		++ypos;
	}
	close(fd);
	ptr[ypos] = NULL;
	return (map);
}

t_vec				***get_map(char *path)
{
	int				fd;
	char			*line;
	size_t			xmax;
	size_t			ymax;
	char			*ptr;

	line = NULL;
	if (((fd = open(path, O_RDONLY)) <= 0) || get_next_line(fd, &line) != 1)
		put_exit(2, "Error reading file\n", 2);
	ptr = line;
	while (*ptr == ' ' || *ptr == '\t')
		ptr++;
	xmax = 0;
	while (*ptr)
	{
		ft_matod(&ptr), xmax++;
		if (*ptr != '\0' && *ptr != '+' && *ptr != '-' && *ptr != ' ' &&
			*ptr != '\t' && !(*ptr >= '0' && *ptr <= '9'))
			put_exit(2, "Invalid map\n", 2);
	}
	free(line), ymax = 1;
	while (get_next_line(fd, &line) == 1)
		ymax++, free(line);
	free(line), close(fd);
	return (load_map(path, xmax, ymax));
}
