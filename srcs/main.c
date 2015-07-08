/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achazal <achazal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 14:33:16 by achazal           #+#    #+#             */
/*   Updated: 2015/05/24 01:04:24 by achazal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parsing.h>
#include <lib.h>
#include <fdf.h>

#include <stdlib.h>

int		main(int ac, char **av)
{
	t_vec	***map;

	if (ac != 2)
		put_exit(2, "Wrong usage : ./fdf \"MAP_PATH\"\n", 2);
	map = get_map(av[1]);
	play_fdf(map);
	return (0);
}
