/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tblanker <tblanker@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 10:55:41 by tblanker       #+#    #+#                */
/*   Updated: 2020/01/13 15:24:18 by tblanker      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int		is_negative(int n)
{
	if (n < 0)
		return (1);
	return (0);
}
