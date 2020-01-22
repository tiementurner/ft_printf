/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_format_strings.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 16:35:52 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/22 12:29:51 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*get_c_string(t_percent *conv, va_list args)
{
	int		i;
	char	c;

	i = conv->width;
	c = va_arg(args, int);
	if (conv->left == 1)
		ft_putchar(c, conv);
	while (i > 1)
	{
		ft_putchar(' ', conv);
		i--;
	}
	if (conv->left == 0)
		ft_putchar(c, conv);
	if (conv->width > 0)
		conv->count += conv->width;
	else
		conv->count++;
	return (0);
}

char	*get_d_string(int precision, va_list args)
{
	char	*number;
	int		nbr;
	int		is_neg;

	nbr = va_arg(args, int);
	is_neg = is_negative(nbr);
	number = ft_itoa(nbr);
	if (nbr == 0 && (precision == 0 || precision == -1))
		number = ft_strdup("");
	if (precision > ft_strlen(number))
	{
		free(number);
		return (precision_d_string(precision, nbr, is_neg));
	}
	else
		return (number);
}

char	*get_p_string(va_list args, int precision, char type)
{
	unsigned long	temp;
	char			*string;
	char			zero_x[4];
	char			*result;

	zero_x[0] = '0';
	zero_x[1] = 'x';
	zero_x[2] = '\0';
	temp = va_arg(args, unsigned long);
	if (temp == 0 && precision == -2)
	{
		zero_x[2] = '0';
		zero_x[3] = '\0';
	}
	string = dec_to_hex_lowercase(temp, type);
	result = ft_strjoin(zero_x, string);
	free(string);
	return (result);
}

char	*get_s_string(va_list args, int precision, int width)
{
	char	*temp;
	int		i;
	char	*result;

	result = NULL;
	if (precision == -1 && width == 0)
		return (0);
	i = 0;
	temp = va_arg(args, char *);
	if (temp == NULL)
	{
		temp = ft_strdup("(null)");
		i = 1;
	}
	result = ft_strdup(temp);
	result = get_s_string_fix(precision, width, temp, result);
	if (i == 1)
		free(temp);
	return (result);
}

char	*get_hex_string(va_list args, int precision, char type)
{
	char	*string;
	long	temp;
	char	*hex_num;

	temp = va_arg(args, long);
	if (type == 'x')
		hex_num = dec_to_hex_lowercase(temp, type);
	if (type == 'X')
		hex_num = dec_to_hex_uppercase(temp);
	if (temp == 0 && (precision == 0 || precision == -1))
		hex_num = ft_strdup("");
	if (precision > ft_strlen(hex_num))
	{
		string = (char *)malloc(sizeof(char) * precision);
		if (!string)
			return (NULL);
		string[precision] = '\0';
		ft_bzero(string, precision);
		string = string_into_string_right(string, hex_num);
		free(hex_num);
		return (string);
	}
	else
		return (hex_num);
}
