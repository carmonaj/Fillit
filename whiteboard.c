AA..
AA..
....
....

A...
A...
A...
A...

..
..

AA
AA

AAA
AAA
...

-place tets

if can't place tet
backtrack to prev map & start +1

if tet is #1 && can't place or move 
clear & increase map size

tet[0] =
	history[0][0] = index
	history[0][1] = first #
	history[0][2] = second #
	history[0][3] = third #
	history[0][4] = fourth #

tet[1] =
	history[1][0] = index
	history[1][1] = first #
	history[1][2] = second #
	history[1][3] = third #
	history[1][4] = fourth #

history = arr[26][5]

solve (map, index, tet, num)
{
	if (num ==  g_num_minos)
		return ;
	
	t_tet t_tetmino;
	
	t_tetmino = place (map, index, tet[num])
	if (t_tetmino.valid = 0)					// can't place tet .. place returns bool & coords of tet
	{											// move tet
		revert_map(map, history[num-1]);		// revert to prev map	
		solve (map, index+1, tet, num - 1);
	}
	else
	{
		history[num] = t_tetmino.coords;
		solve (map, 0, tet, num + 1);
	}
}


void	revert_map(char *map, int history)
{
	int i;

	i = 1;
	while (i < 5)
		map[history[0] + history[i++]] = '.';
}


