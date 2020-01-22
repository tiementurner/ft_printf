/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 11:31:26 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/22 10:15:16 by tblanker      ########   odam.nl         */
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
	i = set_width((char *)format, conv, i, args);
	i = set_precision((char *)format, conv, i, args);
	//printf("precision:%d\n", conv->precision);
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
		if (format[i] == '\0')
			break ;
		if (format[i] != '%')
		{
			ft_putchar(format[i], &conv);
			conv.count++;
			i++;
		}
	}
	va_end(args);
	return (conv.count);
}
