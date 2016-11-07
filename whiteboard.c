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


check if tet fits 
tet#1 starts search at index 0
tet#1 fits
save tet#1 position and index in map state

check if nxt tet fits
tet#2 starts search at index 0
tet#2 fits
save tet#2 position and index in map state

check if nxt tet fits
tet#3 starts search at index 0
if tet doesn't fit, revert back to previous map state and tet

reverted back to tet#2
revert back to prev map
increment tet#2's index
check if tet#2fits

tet#2 doesn't fit, so reset tet#2's index to 0
revert back to previous map state and tet

reverted back to tet#1
revert back to prev map
incrment tet#1's index
check if tet#1 fits

if tet#1 doesn't fit
increment tet#1's index


if tet#1 fits
save tet#1 position and index in map state

check if nxt tet fits
tet#2 starts search at index 0
tet#2 fits
save tet#2 position and index in map state

check if next tet fits
tet#3 starts search at index 0
tet#3 doesn't fit
revert back to previous map state and tet

reverted back to tet#2
revert back to prev map
increment tet#2 index
check if tet#2 fits
tet#2 fits
save map  tet#2 position and index in map state

check if nxt tet fits
tet#3 starts search at index 0
if tet#3 doesn't fit
revert back to previouos map state and tet
increment tet#2 index
if tet#2 doesn't fit
revert back to tet#1
....
...
..

