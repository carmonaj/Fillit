/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_minos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 16:21:30 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/03 14:52:47 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

extern int g_coords[26][3];
extern int g_num_minos;
int	g_size;
int g_map_size;

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
		while (size * size <= mino_sum)
			size++;
	else
		while (size * size <= mino_sum) //<=
			size++;
	return (size);
}

char	*fill_map(char *map, int map_size)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (i < map_size-1)
	{
		count++;
		if (count == g_size+1)
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
	int size;
	int	map_size;
	char *map;

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
		if (pos-1 < g_map_size && map[pos-1] == '.')
			values[0] = 1;
	}
	else
	{
		pos = pos + coord;
		values[1] = pos;
		if (pos-1 < g_map_size && map[pos-1] == '.')
			values[0] = 1;
	}
	
	values[1] = pos;
	return (values);	
}

void	place_mino(int put[4], char *map)
{
	int k;
    static int a = 65;

	k = 0;
	while (k < 4)
	{
		printf("put %d: %d\n", k, put[k]);
		map[put[k]] = a;
		k++;
	}
	a++;
}

/////////////////////////////////////////////////////

typedef	struct 	s_t{

	int coords[5];
	int valid;
}				t_tet;


/////////////////////////////////////////////////////


t_tet		place(char *map, int start, int *crds)
{
    int i;
    int j;
    int k;
    int pos;
    int	put[4];
	int values[2];
	t_tet	t_tetmino;
    
    pos = 0;
    i = start;
    while (map[i])
    {
        k = 0;
        if (map[i] == '.')
        {
            pos = i + 1;
			t_tetmino.coords[k] = start; //k:0
            put[k] = pos-1; //k:0
			t_tetmino.coords[++k] = pos-1; //k:1
            j = 0;
            while (j < 3)
            {
				check_avail(map, pos, crds[j++], values);
				if (values[0] == 1)
				{
					pos = values[1];
					put[k] = pos-1; //k:1
					t_tetmino.coords[++k] = pos-1; //k:2 to k:3
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
		i++;
    }
   	t_tetmino.valid = 0;
	return (t_tetmino);
}

/////////////////////////////////////////////////////

int g_history[26][5];

void	revert_map(char *map, int *history)
{
	int i;

	i = 1;
	while (i < 5)
		map[history[i++]] = '.';
}

char	*solve (char *map, int index, int tet[][3], int num)
{
	static int count = 0;

	if (num == g_num_minos)
		return (map);
	if (num < 0 && index > 25)
	{
		count++;
		index = count;
		printf("count/index: %d", count);
		map = ".....\n.....\n.....\n.....\n.....\n";
	}
	printf("num: %d\n",num);
	printf("index: %d\n", index);
	t_tet	t_tetmino;
	t_tetmino = place(map, index, tet[num]);
	//printf("index: %d\n", t_tetmino.coords[0]);
	printf("coord 1: %d\n", t_tetmino.coords[1]);
	printf("coord 2: %d\n", t_tetmino.coords[2]);
	printf("coord 3: %d\n", t_tetmino.coords[3]);
	printf("coord 4: %d\n", t_tetmino.coords[4]);
	
	printf("--------------------------\n\n");
	if (t_tetmino.valid == 0)
	{
		printf("mino not valid\n");
	
		revert_map(map, g_history[num-1]);
		printf("PREV MAP:\n%s", map);
		solve(map, index+1, tet, num-1);
	}
	else
	{
		ft_memcpy(g_history[num],t_tetmino.coords, sizeof(g_history[num]));
		printf("map:\n%s", map);
		solve(map, index, tet, num+1);
	}
	return (map);
}


/////////////////////////////////////////////////////


int		main(int argc, char **argv)
{
	char buff[1025];
	char **minos;
	char *map;
	int i;

	//t_tet t_tetmino;

	//char map[] = "1BBB.\nA.CCC\nAAAAC\n.....\n";
	if (argc == 2)
	{
		if (rd_f(argv[1], buff))
		{
			minos = rd_minos(buff);	
			map = map_gen(minos);
			i = 0;

			printf("%s", solve(map, 0, g_coords, 0));
		
		/*	t_tetmino = place(map, 0, g_coords[0]);	

			printf("valid: %d\n", t_tetmino.valid);
			while (i < 4)
			{
				printf("coords: %d\n", t_tetmino.coords[i++]);
			}

			printf("map:\n%s", map);

			ft_memcpy(g_history[0],t_tetmino.coords, sizeof(g_history[0]));

			revert_map(map, g_history[0]);

			printf("--------------\n\n");

			printf("map:\n%s", map);
		*/


			//printf("coords 0: %d\n", g_history[0][1]);
			//printf("coords 1: %d\n", g_history[0][2]);
			
			/*while (i < g_num_minos)
			{
				if (place(map, 1, g_coords[i]))
					printf("%s\n", map);
				else
					printf("invalid\n");
				i++;
			}*/
		}
	}
}
