/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   twenty_five_line_fixers.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 09:36:16 by tblanker       #+#    #+#                */
/*   Updated: 2020/02/05 09:55:35 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

char	*precision_d_string(int precision, int nbr, int is_neg, char *number)
{
	char *string;

	if (is_neg && precision > 0)
	{
		free(number);
		nbr *= -1;
		number = ft_itoa(nbr);
	}
	if (nbr == -2147483648 && precision >= ft_strlen(number))
		number[0] = '0';
	string = (char *)malloc(sizeof(char) * precision + (is_neg) + 1);
	if (!string)
	{
		free(number);
		return (NULL);
	}
	string[precision + is_neg] = '\0';
	zerofill(string, precision + is_neg);
	if (is_neg)
		string[0] = '-';
	string = string_into_string_right(string, number);
	free(number);
	return (string);
}

int		precision_neg_star(int i, t_percent *conv, va_list args)
{
	conv->precision = va_arg(args, int);
	if (conv->precision < 0)
		conv->precision = -2;
	i++;
	return (i);
}

char	*get_hex_string_fix(char *hex_num, int precision)
{
	char *string;

	if (precision > ft_strlen(hex_num) && hex_num != NULL)
	{
		string = (char *)malloc(sizeof(char) * precision + 1);
		if (!string)
		{
			free(hex_num);
			return (NULL);
		}
		string[precision] = '\0';
		zerofill(string, precision);
		string = string_into_string_right(string, hex_num);
		free(hex_num);
		return (string);
	}
	return (hex_num);
}
