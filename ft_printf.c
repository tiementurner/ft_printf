/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 11:31:26 by tblanker       #+#    #+#                */
/*   Updated: 2019/12/18 11:55:48 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void	reset_conv(t_percent *conv)
{
	conv->zero = 0;
	conv->left = 0;
	conv->asterisk = 0;
	conv->width = 0;
	conv->precision = 0;
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_percent	conv;
	int			i;

	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			format++;
			reset_conv(&conv);
			i = set_flags((char *)format, &conv, i);
			i = set_width((char *)format, &conv, i, args);
			i = set_precision((char *)format, &conv, i, args);
			i = set_type((char *)format, &conv, i);
			print_out_struct(&conv, args);
			printf("precision : %d", conv.precision);
			printf("\nwidth: %d\nleft flag: %d\nzero flag : %d\ntype : %c\n", conv.width, conv.left, conv.zero, conv.type);
		}
		ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (0);
}
