/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilstwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:48:22 by wlee              #+#    #+#             */
/*   Updated: 2016/11/10 15:48:57 by wlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putendl(char const *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
	write(1, "\n", 1);
}

void	ft_putstr(char const *s)
{
	while (*s != '\0')
	{
		write(1, s, 1);
		s++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*newstring;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	newstring = (char *)malloc(sizeof(char) * (len + 1));
	if (newstring == 0)
		return (NULL);
	while (s[start] != '\0' && len > 0)
	{
		newstring[i] = s[start];
		start++;
		i++;
		len--;
	}
	newstring[i] = '\0';
	return (newstring);
}

char	*ft_strdup(const char *s1)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (newstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		newstr[i] = s1[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}
