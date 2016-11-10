/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarmona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/24 15:58:42 by jcarmona          #+#    #+#             */
/*   Updated: 2016/11/09 21:04:19 by jcarmona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
#define FILLIT_H
#define BUFF_SIZE 1024

#include <fcntl.h>

typedef	struct	s_t{
	int	coords[5];
	int	valid;
}				t_tet;

int		rd_f(char *f, char buff[BUFF_SIZE]);
int		nl_check(int count, char c);
int		count_check(char *buff, int i);
int		is_mino(char *buff);
int		calc_map_size(char **minos);
int		solve(char **map, int tet[][3], int num);
int		ft_2strlen(char **s);
void	put_err(void);
void	put_minos(char **minos);
void	store_coords(char *mino, int *coords);
void	store_mino(char *mino, char**minos);
char	**rd_minos(char *buff);
char	*map_gen(char **g_minos, int size);
char	*fill_map(char *map, int map_size);
t_tet	place(char *map, int start, int *crds);

#endif
