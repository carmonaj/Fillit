/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:59:53 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/09 21:05:48 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern int	g_size;
extern int	g_map_size;
extern char g_alpha_char;

int		*check_avail(char *map, int pos, int coord, int values[2])
{
	values[0] = 0;
	if (coord > 1)
	{
		if (g_size > 4)
			pos = pos + coord + (g_size - 4);
		else
			pos = pos + coord - (4 - g_size);
		if (pos - 1 < g_map_size && map[pos - 1] == '.')
			values[0] = 1;
	}
	else
	{
		pos = pos + coord;
		values[1] = pos;
		if (pos - 1 < g_map_size && map[pos - 1] == '.')
			values[0] = 1;
	}
	values[1] = pos;
	return (values);
}

void	place_mino(int put[4], char *map)
{
	int			k;

	k = 0;
	if (g_alpha_char > 90)
		g_alpha_char = 65;
	while (k < 4)
	{
		map[put[k]] = g_alpha_char;
		k++;
	}
}

t_tet	place(char *map, int start, int *crds)
{
	int		i;
	int		j;
	int		k;
	int		pos;
	int		put[4];
	int		values[2];
	t_tet	t_tetmino;

	i = start;
	pos = 0;
	k = 0;
	if (map[i] == '.')
	{
		pos = i + 1;
		t_tetmino.coords[k] = start;
		put[k] = pos - 1;
		t_tetmino.coords[++k] = pos - 1;
		j = 0;
		while (j < 3)
		{
			check_avail(map, pos, crds[j++], values);
			if (values[0] == 1)
			{
				pos = values[1];
				put[k] = pos - 1;
				t_tetmino.coords[++k] = pos - 1;
			}
			else
				pos = values[1];
			if (k == 4)
			{
				place_mino(put, map);
				t_tetmino.valid = 1;
				return (t_tetmino);
			}
		}
	}
	t_tetmino.valid = 0;
	return (t_tetmino);
}
