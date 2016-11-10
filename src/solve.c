/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_minos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 16:21:30 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/09 15:55:49 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

extern char	**g_minos;
extern int	g_coords[26][3];
extern int	g_num_minos;
int			g_history[26][5];
int			g_map_size;
int			g_size;
int			g_alpha_char = 65;


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

void	revert_map(char *map, int *history)
{
	int i;

	i = 1;
	while (i < 5)
		map[history[i++]] = '.';
}

int		solve(char **map, int tet[][3], int num)
{
	int static size = 1;
	int		i;
	t_tet	t_tetmino;



	if (num == g_num_minos)
		return (1);
	i = 0;
	while ((*map)[i])
	{
		t_tetmino = place(*map, i, tet[num]);
		//printf("tet coords: %d, %d, %d, %d, %d\n", t_tetmino.coords[0],t_tetmino.coords[1],t_tetmino.coords[2], t_tetmino.coords[3], t_tetmino.coords[4]);
		if (t_tetmino.valid == 1)
		{
			g_alpha_char++;
			ft_memcpy(g_history[num], t_tetmino.coords, sizeof(g_history[num]));
			if (solve(map, tet, num + 1))
				return (1);
			else
			{
				g_alpha_char--;
				revert_map(*map, g_history[num]);
			}
		}
		else	
		{
			if (num == 0 && i == g_map_size-5)
			{
				free(*map);
				*map = map_gen(g_minos, size++);
				i = -1;
			}
		}
		i++;
	}
	return (0);
}
