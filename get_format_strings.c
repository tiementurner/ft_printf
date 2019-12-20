/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_format_strings.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 16:35:52 by tblanker       #+#    #+#                */
/*   Updated: 2019/12/20 14:06:58 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_c_string(va_list args)
{
	char *string;
	char c;

	c = va_arg(args, int);
	string = (char *)malloc(sizeof(char) * 2);
	string[0] = c;
	string[1] = '\0';
	return (string);
}

char	*get_d_string(int precision, va_list args)
{
	char	*number;
	char	*string;
	int		i;
	int		nbr;
	int		j;

	j = 0;
	nbr = va_arg(args, int);
	printf("\n%d\n", nbr);
	number = ft_itoa(nbr);
	printf("\n%s\n", number);
	if (precision > ft_strlen(number))
	{
		string = (char *)malloc(sizeof(char) * precision);
		string[precision] = '\0';
		ft_bzero(string, 20);
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

char		*get_p_string(va_list args)
{
	long temp;
	char *string;
	char zero_x[3];

	zero_x[0] = '0';
	zero_x[1] = 'x';
	zero_x[2] = '\0';
	temp = va_arg(args, long);
	string = dec_to_hex_lowercase(temp);
	return (ft_strjoin(zero_x, string));
}

char	*get_s_string(va_list args, int precision)
{
	char	*temp;
	char	*string;
	int		i;

	i = 0;
	temp = va_arg(args, char *);
	if (precision < ft_strlen(temp))
		string = ft_substr(temp, 0, precision);
	else
		string = ft_strdup(temp);
	return (string);
}
