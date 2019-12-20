/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 11:53:15 by tblanker       #+#    #+#                */
/*   Updated: 2019/12/17 21:55:40 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	int		i;

	i = 0;
	p = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (p)
	{
		while (i < ft_strlen(s1))
		{
			p[i] = s1[i];
			i++;
		}
		p[ft_strlen(s1)] = '\0';
	}
	return (p);
}
