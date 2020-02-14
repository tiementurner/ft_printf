/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 12:35:53 by tblanker       #+#    #+#                */
/*   Updated: 2020/02/05 09:55:38 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	ft_putchar(char c, t_percent *conv)
{
	write_function(c, conv);
}

void	write_function(char c, t_percent *conv)
{
	int error;

	error = write(1, &c, 1);
	if (conv->count == -1 || error == -1)
		conv->count = -1;
	return ;
}

void	ft_putstr(char *s, t_percent *conv)
{
	int i;
	int length;

	if (!s)
		return ;
	i = 0;
	length = ft_strlen(s);
	while (i < length)
	{
		ft_putchar(s[i], conv);
		i++;
	}
}
