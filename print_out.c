/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_out.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:10:43 by tblanker       #+#    #+#                */
/*   Updated: 2019/12/20 14:07:53 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_out_struct(t_percent *conv, va_list args)
{
	char *output;
	char *format;

	if (conv->width > 0)
		output = (char *)malloc(sizeof(char) * (conv->width + 1));
	format = get_format_string(conv, args);
	printf("\n format: %s\n", format);
}

char	*get_format_string(t_percent *conv, va_list args)
{
	printf("\n%c\n", conv->type);
	if (conv->type == 'c')
		return (get_c_string(args));
	if (conv->type == 'd' || conv->type == 'i')
		return (get_d_string(conv->precision, args));
	if (conv->type == 'p')
		return (get_p_string(args));
	if (conv->type == 's')
		return (get_s_string(args, conv->precision));
	if (conv->type == 'u')
		return (get_u_string(conv->precision, args));
	if (conv->type == 'x')
		return (dec_to_hex_lowercase(va_arg(args, long)));
	return (0);
}
