/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_unsigned_string.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 16:25:03 by tblanker       #+#    #+#                */
/*   Updated: 2019/12/20 14:22:59 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_arraylength(unsigned int nbr)
{
	int arraylength;

	arraylength = 1;
	while (nbr >= 10)
	{
		arraylength++;
		nbr = nbr / 10;
	}
	return (arraylength);
}

static char		*ft_makestring(int arraylength, unsigned int nbr, char *string)
{
	while (arraylength > -1)
	{
		string[arraylength] = nbr % 10 + '0';
		arraylength--;
		nbr = nbr / 10;
	}
	return (string);
}

static char		*ft_uitoa(unsigned int nbr)
{
	char	*string;
	int		arraylength;

	arraylength = ft_arraylength(nbr);
	string = (char *)malloc(sizeof(char) * arraylength + 1);
	if (!string)
		return (NULL);
	string[arraylength] = '\0';
	arraylength--;
	string = ft_makestring(arraylength, nbr, string);
	return (string);
}

char			*get_u_string(int precision, va_list args)
{
	char			*number;
	char			*string;
	int				i;
	unsigned int	nbr;
	int				j;

	j = 0;
	nbr = va_arg(args, int);
	number = ft_uitoa(nbr);
	if (precision > ft_strlen(number))
	{
		string = (char *)malloc(sizeof(char) * precision);
		string[precision] = '\0';
		ft_bzero(string, precision);
		i = precision - ft_strlen(number);
		while (string[i])
		{
			string[i] = number[j];
			i++;
			j++;
		}
		return (string);
	}
	else
		return (number);
}
