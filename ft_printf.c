/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 11:31:26 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/31 15:53:06 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		reset_conv(t_percent *conv)
{
	conv->zero = 0;
	conv->left = 0;
	conv->width = 0;
	conv->precision = -2;
}

static int	call_functions(char *format, t_percent *conv, int i, va_list args)
{
	i++;
	reset_conv(conv);
	i = set_flags((char *)format, conv, i);
	if (format[i] == '\0')
		return (i);
	i = set_width((char *)format, conv, i, args);
	if (format[i] == '\0')
		return (i);
	i = set_precision((char *)format, conv, i, args);
	if (format[i] == '\0')
		return (i);
	i = set_type((char *)format, conv, i);
	print_out_struct(conv, args);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	t_percent	conv;
	int			i;

	conv.count = 0;
	i = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i = call_functions((char *)format, &conv, i, args);
		if (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i], &conv);
			conv.count++;
			i++;
		}
	}
	va_end(args);
	return (conv.count);
}
