/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:58:42 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/01 14:47:04 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H
#define BUFF_SIZE 1024

#include <fcntl.h>

int		rd_f(char *f, char buff[BUFF_SIZE]);
int		nl_check(int count, char c);
int		count_check(char *buff, int i);
int		is_mino(char *buff);
void	put_err(void);
void	put_minos(char **minos);
void	store_coords(char *mino, int *coords);
void	store_mino(char *mino, char**minos);
char	**rd_minos(char *buff);

#endif
