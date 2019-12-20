/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   header.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 15:45:47 by tblanker       #+#    #+#                */
/*   Updated: 2019/12/19 16:41:16 by tblanker      ########   odam.nl         */
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
	int				asterisk;
	int				width;
	int				precision;
}					t_percent;

char	*ft_strdup(const char *s1);
char	*get_c_string(va_list args);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(const char *s);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
void	reset_conv(t_percent *conv);
void	set_left(char *format, t_percent *conv);
int		set_flags(char *format, t_percent *conv, int i);
int		ft_check_char(char c, const char *set);
void	ft_putchar(char c);
int		ft_printf(const char *format, ...);
void	ft_putstr(char *s);
void	ft_putnbr(int n);
int		set_width(char *format, t_percent *conv, int i, va_list args);
int		set_precision(char *format, t_percent *conv, int i, va_list args);
int		set_type(char *format, t_percent *conv, int i);
void	print_out_struct(t_percent *conv, va_list args);
char	*get_format_string(t_percent *conv, va_list args);
char	*ft_itoa(int nbr);
char	*get_d_string(int precision, va_list args);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
char	*get_p_string(va_list args);
char	*dec_to_hex_lowercase(long temp);
char	*dec_to_hex_uppercase(long temp);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_s_string(va_list args, int precision);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_u_string(int precision, va_list args);

#endif
