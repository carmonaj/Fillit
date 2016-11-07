/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_minos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 16:21:30 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/07 15:07:26 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

extern int g_coords[26][3];
extern int g_num_minos;
int g_history[26][5];
int g_map_size;
int	g_size;

int		ft_2strlen(char **s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int		calc_map_size(char **minos)
{
	int size;
	int mino_sum;

	size = 1;
	mino_sum = ft_2strlen(minos) * 4;
	if (mino_sum == 4)
		while (size * size < mino_sum)
			size++;
	else
		while (size * size <= mino_sum)
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

char	*map_gen(char **minos)
{
	int		size;
	int		map_size;
	char	*map;

	size = calc_map_size(minos);
	g_size = size;
	map_size = ((size * size) + (size + 1));
	g_map_size = map_size;
	if (!(map = (char*)malloc(sizeof(char) * (map_size))))
		put_err();
	return (fill_map(map, map_size));
}

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
	static int	a = 65;
	int			k;

	k = 0;
	if (a > 90)
		a = 65;
	while (k < 4)
	{
		map[put[k]] = a;
		k++;
	}
	a++;
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

int		solve(char *map, int tet[][3], int num)
{
	int		i;
	t_tet	t_tetmino;

	if (num == g_num_minos)
		return (1);
	i = 0;
	while (map[i])
	{
		t_tetmino = place(map, i, tet[num]);
		if (t_tetmino.valid == 1)
		{
			ft_memcpy(g_history[num], t_tetmino.coords, sizeof(g_history[num]));
			printf("good:\n%s", map);
			if (solve(map, tet, num + 1))
				return (1);
			else
			{
				printf("bad:\n%s", map);
				revert_map(map, g_history[num]);
			}
		}
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	char buff[1025];
	char **minos;
	char *map;

	if (argc == 2)
	{
		if (rd_f(argv[1], buff))
		{
			minos = rd_minos(buff);
			map = map_gen(minos);
			solve(map, g_coords, 0);
		}
	}
}
