/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coclayto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:53:04 by coclayto          #+#    #+#             */
/*   Updated: 2020/02/19 00:44:00 by coclayto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf(const char *fmt, ...)
{
	va_list		args;
	int			printed;
	t_struct	flags;
/*
	const char	*str;
	char		*s;
	int			d;
*/
	va_start(args, fmt);
	printed = formatparse(fmt, flags, args, 0);
/*	str = fmt;
	while (*str)
	{
		if (*str != '%')
			write(1, str, 1);
		else
		{
			if (*++str == 'd')
			{
				d = va_arg(args, int);
				ft_putnbr(d);
			}
			else if (*str == 's')
			{
				s = va_arg(args, char *);
				while (*s)
					write(1, s++, 1);
			}
			else
				write(1, str, 1);
		}
		str++;
	}
*/
	va_end(args);
	return (printed);
}
