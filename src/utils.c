/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:57:36 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/01 16:14:46 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Function to throw error
*/

void	put_err(void)
{
	ft_putendl("error");
	exit(-1);
}

/*
** Function to display 2d string array
*/

void	put_minos(char **minos)
{
	while (*minos)
	{
		ft_putstr(*minos);
		ft_putstr("\n");
		minos++;
	}
}

/*
** Function returns length of a 2d string array
*/

int		ft_2strlen(char **s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
