/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_out.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/17 15:10:43 by tblanker       #+#    #+#                */
/*   Updated: 2019/12/20 16:32:33 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	print_out_struct(t_percent *conv, va_list args)
{
	char *output;
	char *format;

	format = get_format_string(conv, args);
	if (conv->width > ft_strlen(format))
	{
		output = (char *)malloc(sizeof(char) * (conv->width) + 1);
		ft_bspace(output, conv->width);
		output[conv->width] = '\0';
	}
	else
	{
		output = (char *)malloc(sizeof(char) * (ft_strlen(format)) + 1);
		ft_bspace(output, ft_strlen(format));
		output[ft_strlen(format)] = '\0';
	}
	if (conv->zero && !(conv->left) && conv->precision < 0)
		ft_bzero(output, ft_strlen(output));
	if (conv->left)
		output = string_into_string_left(output, format);
	else if (!(conv->left))
		output = string_into_string_right(output, format);
	ft_putstr(output);
}

char	*get_format_string(t_percent *conv, va_list args)
{
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
	if (conv->type == 'x' || conv->type == 'X')
		return (get_hex_string(args, conv->precision, conv->type));
	if (conv->type == '%')
		return (ft_strdup("%"));
	return (0);
}
