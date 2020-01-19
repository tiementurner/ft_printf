/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_out.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:10:43 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/16 13:31:01 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char	*init_output(t_percent *conv, char *format)
{
	char *output;

	if (conv->width > ft_strlen(format))
	{
		output = (char *)malloc(sizeof(char) * (conv->width) + 1);
		if (!output)
			return (NULL);
		ft_bspace(output, conv->width);
		output[conv->width] = '\0';
	}
	else
	{
		output = (char *)malloc(sizeof(char) * (ft_strlen(format)) + 1);
		if (!output)
			return (NULL);
		ft_bspace(output, ft_strlen(format));
		output[ft_strlen(format)] = '\0';
	}
	return (output);
}

void		print_out_struct(t_percent *conv, va_list args)
{
	char *output;
	char *format;

	format = get_format_string(conv, args);
	if (!format)
		return ;
	output = init_output(conv, format);
	if (!output)
		return ;
	if (conv->zero && !(conv->left) && conv->precision < 0)
	{
		ft_bzero(output, ft_strlen(output));
		if (format[0] == '-' && (conv->type == 'i' || conv->type == 'd') &&
		conv->width > ft_strlen(format))
		{
			format[0] = '0';
			output[0] = '-';
		}
	}
	(conv->left) ? (output = string_into_string_left(output, format)) :
	(output = string_into_string_right(output, format));
	ft_putstr(output, conv);
	conv->count += ft_strlen(output);
	free(output);
	free(format);
}

char		*get_format_string(t_percent *conv, va_list args)
{
	if (conv->type == 'c')
		return (get_c_string(conv, args));
	if (conv->type == 'd' || conv->type == 'i')
		return (get_d_string(conv->precision, args));
	if (conv->type == 'p')
		return (get_p_string(args, conv->precision, conv->type));
	if (conv->type == 's')
		return (get_s_string(args, conv->precision, conv->width));
	if (conv->type == 'u')
		return (get_u_string(conv->precision, args));
	if (conv->type == 'x' || conv->type == 'X')
		return (get_hex_string(args, conv->precision, conv->type));
	if (conv->type == '%')
		return (ft_strdup("%"));
	return (0);
}
