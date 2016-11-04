/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 17:49:31 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/01 16:18:39 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		ft_2strlen(char **minos)
{
	int len;

	len = 0;
	while (minos[len])
		len++;
	return (len);
}

int		main(int argc, char **argv)
{
	char buff[1024];
	char **minos;

	if (argc == 2)
		if (rd_f(argv[1], buff))
		{
			if ((minos = rd_minos(buff)))
			{
				put_minos(minos);
				printf("%d\n", ft_2strlen(minos));
			}
			else
				put_err();
		}
	return (0);
}
