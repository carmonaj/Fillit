/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:49:31 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/10 15:12:54 by wlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern int	g_coords[26][3];
char		**g_minos;

int	main(int argc, char **argv)
{
	char buff[1025];
	char *map;

	if (argc == 2)
	{
		if (rd_f(argv[1], buff))
		{
			g_minos = rd_minos(buff);
			map = map_gen(g_minos, 0);
			solve(&map, g_coords, 0);
			ft_putstr(map);
		}
	}
	else
	{
		ft_putendl("usage: ./fillit source_file");
		return (0);
	}
}
