/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:52:44 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/01 16:17:33 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	g_coords[26][3];
int g_num_minos;

/*
**	Function stores mino coords
*/

void		store_coords(char *mino, int *coords)
{
	int j;
	int k;
	int skp;

	j = 0;
	k = 0;
	skp = 0;
	while (*mino)
	{
		j++;
		if (*mino == '#')
		{
			if (skp)
			{
				coords[k] = j;
				k++;
			}
			skp = 1;
			j = 0;
		}
		mino++;
	}
}

/*
**	Function stores mino in a 2d array
*/

void		store_mino(char *mino, char **minos)
{
	static int i = 0;

	store_coords(mino, g_coords[i]);
	minos[i] = ft_strdup(mino);
	minos[i + 1] = 0;
	i++;
	g_num_minos = i;
}
