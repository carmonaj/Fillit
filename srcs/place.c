/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:59:53 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/09 23:31:39 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

extern int	g_size;
extern int	g_map_size;
extern char g_alpha_char;

int		*check_avail(char *map, int pos, int coord)
{
	int *values;

	values = (int*)malloc(sizeof(int) * 2);
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

t_tet	place_mino(int put[4], char *map, t_tet t_tetmino)
{
	int	k;

	k = 0;
	if (g_alpha_char > 90)
		g_alpha_char = 65;
	while (k < 4)
		map[put[k++]] = g_alpha_char;
	t_tetmino.valid = 1;
	return (t_tetmino);
}

t_tet	place(char *map, int i, int *crds, int *v)
{
	int		pos;
	int		put[4];
	t_tet	t_tetmino;

	if (map[i] == '.')
	{
		pos = i + 1;
		t_tetmino.coords[v[1]] = i;
		put[v[1]] = pos - 1;
		t_tetmino.coords[++v[1]] = pos - 1;
		v[0] = 0;
		while (v[0] < 3)
			if (check_avail(map, pos, crds[v[0]++])[0] == 1)
			{
				pos = check_avail(map, pos, crds[v[0] - 1])[1];
				put[v[1]] = pos - 1;
				t_tetmino.coords[++v[1]] = pos - 1;
			}
			else
				pos = check_avail(map, pos, crds[v[0] - 1])[1];
		if (v[1] == 4)
			return (place_mino(put, map, t_tetmino));
	}
	t_tetmino.valid = 0;
	return (t_tetmino);
}
