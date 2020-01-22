/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   twenty_five_line_fixers.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/14 09:36:16 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/22 12:30:14 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*precision_d_string(int precision, int nbr, int is_neg)
{
	char *string;
	char *number;

	if (is_neg && precision > 0)
		nbr *= -1;
	number = ft_itoa(nbr);
	if (nbr == 0 && (precision == 0 || precision == -1))
		number = ft_strdup("");
	string = (char *)malloc(sizeof(char) * precision + (is_neg));
	if (!string)
		return (NULL);
	string[precision + is_neg] = '\0';
	ft_bzero(string, precision + is_neg);
	if (is_neg)
		string[0] = '-';
	free(number);
	return (string_into_string_right(string, number));
}

int		precision_neg_star(int i, t_percent *conv, va_list args)
{
	conv->precision = va_arg(args, int);
	if (conv->precision < 0)
		conv->precision = -2;
	i++;
	return (i);
}

char	*get_s_string_fix(int precision, int width, char *temp, char *result)
{
	if (precision < ft_strlen(temp) && precision != -1)
	{
		free(result);
		result = ft_substr(temp, 0, precision);
	}
	else if (width > 0 && precision == -1)
	{
		free(result);
		result = ft_substr(temp, 0, width);
		ft_bspace(result, width);
	}
	return (result);
}
