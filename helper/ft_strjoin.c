/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:42:48 by tblanker       #+#    #+#                */
/*   Updated: 2020/02/05 09:55:04 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static	char	*ft_merge(char *p, char const *s1, char const *s2)
{
	int i;
	int j;

	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	j = i;
	i = 0;
	while (s2[i])
	{
		p[j] = s2[i];
		i++;
		j++;
	}
	p[j] = '\0';
	return (p);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p)
		p = ft_merge(p, s1, s2);
	return (p);
}

char			*string_into_string_right(char *s1, char *s2)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(s1) - ft_strlen(s2);
	while (s1[i])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	return (s1);
}

char			*string_into_string_left(char *s1, char *s2)
{
	int i;

	i = 0;
	while (i < ft_strlen(s2))
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}
