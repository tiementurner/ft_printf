/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 12:35:53 by tblanker       #+#    #+#                */
/*   Updated: 2019/12/13 14:06:16 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (i < (int)strlen(s))
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	unsigned int	result;

	result = 0;
	if (n < 0)
	{
		ft_putchar('-');
		result = (unsigned int)(n * -1);
	}
	else
		result = (unsigned int)n;
	if (result >= 10)
		ft_putnbr(result / 10);
	ft_putchar((char)(result % 10 + '0'));
}
