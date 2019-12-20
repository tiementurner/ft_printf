/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 15:45:47 by tblanker       #+#    #+#                */
/*   Updated: 2019/12/20 16:24:44 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

typedef	struct		percent
{
	char			type;
	int				zero;
	int				left;
	int				width;
	int				precision;
}					t_percent;

void	reset_conv(t_percent *conv);
int		ft_check_char(char c, const char *set);
int		ft_printf(const char *format, ...);
void	print_out_struct(t_percent *conv, va_list args);

void	set_left(char *format, t_percent *conv);
int		set_flags(char *format, t_percent *conv, int i);
int		set_width(char *format, t_percent *conv, int i, va_list args);
int		set_precision(char *format, t_percent *conv, int i, va_list args);
int		set_type(char *format, t_percent *conv, int i);

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(int n);

void	ft_bspace(void *s, size_t n);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(int nbr);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*get_format_string(t_percent *conv, va_list args);
char	*string_into_string_right(char *s1, char *s2);
char	*string_into_string_left(char *s1, char *s2);
char	*dec_to_hex_lowercase(long temp);
char	*dec_to_hex_uppercase(long temp);
char	*get_c_string(va_list args);
char	*get_d_string(int precision, va_list args);
char	*get_p_string(va_list args);
char	*get_s_string(va_list args, int precision);
char	*get_u_string(int precision, va_list args);
char	*get_hex_string(va_list args, int precision, char type);

#endif
