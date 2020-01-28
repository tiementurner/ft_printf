/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 11:54:04 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/28 21:25:42 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (s[0] == (char)c)
			return (1);
		s++;
	}
	if ((char)c == '\0')
		return (0);
	return (0);
}
