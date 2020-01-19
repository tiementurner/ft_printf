/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:26:00 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/16 12:44:51 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		i;

	if (!(s))
		return (NULL);
	i = 0;
	if (start > (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if (start + len > (unsigned long)ft_strlen(s))
		p = (char *)malloc(sizeof(char) * (ft_strlen(s) - start + 1));
	else
		p = (char *)malloc(sizeof(char) * (len + 1));
	if (p)
	{
		while (i < len && s[start] != '\0')
		{
			p[i] = s[start];
			start++;
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	else
		return (NULL);
}
