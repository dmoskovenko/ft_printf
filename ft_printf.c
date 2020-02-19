/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: releanor <releanor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:53:04 by coclayto          #+#    #+#             */
/*   Updated: 2020/02/19 18:05:35 by releanor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list		params;
	t_struct	*new_struct;
	int			frmtlngth;

	frmtlngth = ft_strlen(fmt);
	if (!(new_struct = (t_struct*)malloc(sizeof(t_struct))))
		return (0);
	//bezerostruct(s);
	new_struct->fmt = (char *)fmt;
	va_start(params, fmt);
	if (!fmt[0])
	{
		// error();
		return (0);
	}
	if (frmtlngth == 1 && fmt[0] == '%')
		return (0);
	/*else
		status = */format_parse(fmt, new_struct, params, 0);
	va_end(params);
	free(new_struct);
	return (0);
}

// void	ft_printf(const char *fmt, ...)
// {
// 	va_list		args;
// 	const char	*str;
// 	char		*s;
// 	int			d;

// 	va_start(args, fmt);
// 	str = fmt;
// 	while (*str)
// 	{
// 		if (*str != '%')
// 			write(1, str, 1);
// 		else
// 		{
// 			if (*++str == 'd')
// 			{
// 				d = va_arg(args, int);
// 				ft_putnbr(d);
// 			}
// 			else if (*str == 's')
// 			{
// 				s = va_arg(args, char *);
// 				while (*s)
// 					write(1, s++, 1);
// 			}
// 			else
// 				write(1, str, 1);
// 		}
// 		str++;
// 	}
// 	va_end(args);
// }

// int		main(void)
// {
// 	ft_printf("digit: %d %s\n", 30, "tis");
// 	printf("digit: %d %s\n", 30, "tis");
// 	return (0);
// }
