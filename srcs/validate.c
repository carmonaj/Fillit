/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:49:03 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/01 16:23:08 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
**	Function checks for proper number of '\n's
*/

int		nl_check(int count, char c)
{
	if (count == 5)
	{
		if (c != '\n')
			return (-1);
		return (1);
	}
	else if (c != '.' && c != '#')
		return (-1);
	return (0);
}

/*
** Function checks for proper number of #'s
*/

int		count_check(char *buff, int i)
{
	int count;

	count = 0;
	if (i - 1 >= 0 && buff[i - 1] == '#')
		count++;
	if (i + 1 <= 19 && buff[i + 1] == '#')
		count++;
	if (i + 5 <= 19 && buff[i + 5] == '#')
		count++;
	if (i - 5 >= 0 && buff[i - 5] == '#')
		count++;
	return (count);
}

/*
** Function checks whether mino is valid
*/

int		is_mino(char *buff)
{
	int nl_count;
	int h_count;
	int count;
	int i;

	nl_count = 0;
	h_count = 0;
	count = 0;
	i = 0;
	while (buff[i])
	{
		if (nl_check(++nl_count, buff[i]) == -1)
			return (0);
		else if (nl_check(nl_count, buff[i]))
			nl_count = 0;
		if (buff[i] == '#')
		{
			h_count++;
			count += count_check(buff, i);
		}
		i++;
	}
	if ((count != 6 && count != 8) || (h_count != 4))
		return (0);
	return (1);
}
