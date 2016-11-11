/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:32:33 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/08 15:33:41 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern int	g_map_size;
extern int	g_size;

int		calc_map_size(char **minos)
{
	int size;
	int mino_sum;

	size = 1;
	mino_sum = ft_2strlen(minos) * 4;
	while (size * size < mino_sum)
		size++;
	return (size);
}

char	*fill_map(char *map, int map_size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < map_size - 1)
	{
		count++;
		if (count == g_size + 1)
		{
			map[i] = '\n';
			count = 0;
		}
		else
			map[i] = '.';
		i++;
	}
	map[i] = '\0';
	return (map);
}

char	*map_gen(char **minos, int size)
{
	int		map_size;
	char	*map;

	if (size <= 0)
		size = calc_map_size(minos);
	else
		size += calc_map_size(minos);
	g_size = size;
	map_size = ((size * size) + (size + 1));
	g_map_size = map_size;
	if (!(map = (char*)malloc(sizeof(char) * (map_size))))
		put_err();
	return (fill_map(map, map_size));
}
