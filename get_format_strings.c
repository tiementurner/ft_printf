/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_format_strings.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 16:35:52 by tblanker       #+#    #+#                */
/*   Updated: 2020/02/04 11:51:37 by tblanker      ########   odam.nl         */
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
	if (!number)
		return (NULL);
	if (nbr == 0 && (precision == 0 || precision == -1))
	{
		free(number);
		number = ft_strdup("");
		if (!number)
			return (NULL);
	}
	if (precision >= ft_strlen(number))
		return (precision_d_string(precision, nbr, is_neg, number));
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

char	*get_s_string(va_list args, int precision)
{
	char	*temp;
	int		i;
	char	*result;

	result = NULL;
	if (precision == -1)
		return (ft_strdup(""));
	i = 0;
	temp = va_arg(args, char *);
	if (temp == NULL)
	{
		temp = ft_strdup("(null)");
		if (!temp)
			return (NULL);
		i = 1;
	}
	result = ft_strdup(temp);
	if (precision < ft_strlen(temp) && precision != -1)
	{
		free(result);
		result = ft_substr(temp, 0, precision);
	}
	if (i == 1)
		free(temp);
	return (result);
}

char	*get_hex_string(va_list args, int precision, char type)
{
	unsigned int	temp;
	char			*hex_num;

	temp = va_arg(args, unsigned int);
	if (type == 'x')
		hex_num = dec_to_hex_lowercase(temp, type);
	if (type == 'X')
		hex_num = dec_to_hex_uppercase(temp);
	if (temp == 0 && (precision == 0 || precision == -1))
	{
		free(hex_num);
		hex_num = ft_strdup("");
	}
	return (get_hex_string_fix(hex_num, precision));
}
