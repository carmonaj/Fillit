/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 23:08:04 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/09 23:08:19 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern char	**g_minos;
extern int	g_coords[26][3];
extern int	g_num_minos;
int			g_history[26][5];
int			g_map_size;
int			g_size;
int			g_alpha_char = 65;

void	revert_map(char *map, int *history)
{
	int i;

	i = 1;
	while (i < 5)
		map[history[i++]] = '.';
	g_alpha_char--;
}

int		increase_map_size(char **map)
{
	static int	size = 1;

	free(*map);
	*map = map_gen(g_minos, size++);
	return (-1);
}

int		solve(char **map, int mino[][3], int num)
{
	int			v[2];
	int			i;
	t_tet		t_tetmino;

	if (num == g_num_minos)
		return (1);
	i = 0;
	while ((*map)[i])
	{
		v[1] = 0;
		t_tetmino = place(*map, i, mino[num], v);
		if (t_tetmino.valid)
		{
			g_alpha_char++;
			ft_memcpy(g_history[num], t_tetmino.coords, sizeof(g_history[num]));
			if (solve(map, mino, num + 1))
				return (1);
			else
				revert_map(*map, g_history[num]);
		}
		else if (num == 0 && i == g_map_size - 5)
			i = increase_map_size(map);
		i++;
	}
	return (0);
}
