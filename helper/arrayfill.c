/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arrayfill.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 12:11:26 by tblanker       #+#    #+#                */
/*   Updated: 2020/02/05 09:54:44 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	zerofill(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = '0';
		i++;
	}
}

void	ft_bspace(void *s, int n)
{
	int			i;
	char		*p;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = ' ';
		i++;
	}
}
