/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dec_hex.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 12:39:03 by tblanker       #+#    #+#                */
/*   Updated: 2020/02/05 09:54:34 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static	char	*reverse_hex(char *reversed_hex, int i)
{
	int		j;
	char	*hex;
	int		end;

	end = i;
	j = 0;
	hex = (char *)malloc(sizeof(char) * (i + 1));
	if (!hex)
		return (NULL);
	while (j < end)
	{
		i--;
		hex[j] = reversed_hex[i];
		j++;
	}
	hex[end] = '\0';
	return (hex);
}

char			*dec_to_hex_uppercase(unsigned long temp)
{
	unsigned long	remainder;
	char			hex[100];
	int				i;

	i = 0;
	if (temp == 0)
		return (ft_strdup("0"));
	while (temp != 0)
	{
		remainder = temp % 16;
		temp = temp / 16;
		if (remainder >= 10)
		{
			hex[i] = remainder + 55;
			i++;
		}
		else
		{
			hex[i] = remainder + 48;
			i++;
		}
	}
	return (reverse_hex(hex, i));
}

char			*dec_to_hex_lowercase(unsigned long temp, char type)
{
	unsigned long	remainder;
	char			hex[100];
	int				i;

	i = 0;
	if (temp == 0 && type == 'x')
		return (ft_strdup("0"));
	while (temp != 0)
	{
		remainder = temp % 16;
		temp = temp / 16;
		if (remainder >= 10)
		{
			hex[i] = remainder + 87;
			i++;
		}
		else
		{
			hex[i] = remainder + 48;
			i++;
		}
	}
	return (reverse_hex(hex, i));
}
