/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   flags.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 16:51:41 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/22 12:48:29 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	set_flags(char *format, t_percent *conv, int i)
{
	if (format[i] == '%' || format[i] == '\0')
		return (i);
	if (format[i] == '-' || (format[i + 1]) == '-')
	{
		conv->left = 1;
		i++;
	}
	if ((format[i] == '0' || format[i + 1] == '0' || format[i - 1] == '0') &&
	format[i] != '.' && (!(ft_isdigit(format[i])) || format[i] == '0'))
	{
		conv->zero = 1;
		i++;
	}
	while (format[i] == '-')
		i++;
	return (i);
}

int	set_width(char *format, t_percent *conv, int i, va_list args)
{
	char	size[100];
	int		j;

	ft_bspace(size, 100);
	j = 0;
	while (ft_isdigit(format[i]))
	{
		size[j] = format[i];
		j++;
		i++;
	}
	if (j > 0)
		conv->width = ft_atoi(size);
	if (format[i] == '*')
	{
		conv->width = va_arg(args, int);
		if (conv->width < 0)
		{
			conv->width *= -1;
			conv->left = 1;
		}
		i++;
	}
	return (i);
}

int	set_precision(char *format, t_percent *conv, int i, va_list args)
{
	char	size[100];
	int		j;

	ft_bspace(size, 100);
	if (format[i] == '.')
	{
		i++;
		j = 0;
		while (ft_isdigit(format[i]))
		{
			size[j] = format[i];
			j++;
			i++;
		}
		if (j > 0)
			conv->precision = ft_atoi(size);
		if (j == 0)
			conv->precision = -1;
		if (format[i] == '*')
			i = precision_neg_star(i, conv, args);
	}
	return (i);
}

int	set_type(char *format, t_percent *conv, int i)
{
	if (format[i] == 'c')
		conv->type = 'c';
	if (format[i] == 's')
		conv->type = 's';
	if (format[i] == 'p')
		conv->type = 'p';
	if (format[i] == 'd')
		conv->type = 'd';
	if (format[i] == 'i')
		conv->type = 'i';
	if (format[i] == 'u')
		conv->type = 'u';
	if (format[i] == 'x')
		conv->type = 'x';
	if (format[i] == 'X')
		conv->type = 'X';
	if (format[i] == '%')
		conv->type = '%';
	i++;
	return (i);
}
