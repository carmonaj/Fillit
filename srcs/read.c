/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 14:42:49 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/01 16:13:11 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** Function to read file to buffer. Return
** 1 if file has been succesfully read, otherwise
** it returns 0
*/

int		rd_f(char *f, char buff[BUFF_SIZE])
{
	int		fd;
	int		len;

	if ((fd = open(f, O_RDONLY)) != -1)
		if ((len = read(fd, buff, 700)) > 0)
		{
			buff[len] = '\0';
			return (1);
		}
	put_err();
	return (0);
}

/*
**	Function reads &validates mino file. If file is valid, it
**	returns a 2d array with minos. If file is invalid, it exits.
*/

char	**rd_minos(char *buff)
{
	int		len;
	int		i;
	int		start;
	char	**minos;

	len = ft_strlen(buff);
	if (!(minos = (char**)malloc(sizeof(char*) * (26 + 1))))
		put_err();
	start = 0;
	i = 0;
	while (start <= len)
		if (is_mino(ft_strsub(buff, start, 20)))
		{
			store_mino(ft_strsub(buff, start, 20), minos);
			i = start + (20 - 1);
			if (buff[i + 1] == '\n' || buff[i + 1] == '\0')
				if (buff[i + 1] == '\0')
					return (minos);
			start += 21;
		}
		else
			put_err();
	exit(-1);
}
